import math
import numpy as np
from .veloxchemlib import VisualizationDriver
from .veloxchemlib import CubicGrid

#Optional imports for notebook viewer
try:
    import k3d
    import ipywidgets as widgets
except ImportError:
    k3d = None
    widgets = None

class veloxviz:
    """
    An approximate but very quick module to compute a molecular orbital on a grid

    It does this by computing the AOs of each unique atom type in an atomic grid.
    These AOs are then translated as needed to the nearest grid point of the actual atomic center
    to compute on-the-fly the molecular orbital on the full grid

    Instance variables
        - grid_density: The density of grid points per a.u.
        - grid_margins: Minimal distance in a.u. between the box edge and all atomic nuclei
        - atombox_radius: Radius in a.u. of the atomix grid
        - mo_threshold: Do not compute AO contribution if corresponding MO coefficient is below this value
    """

    def __init__(self):
        self.grid_density = 4 #nr of grid points per a.u.
        self.grid_margins = 3 # a.u. added around the molecule to create the box
        self.atombox_radius = 6 # Radius in a.u. for each atomix box
        self.mo_threshold = 0.01 # Do not compute AO if MO coefficient is below this value

    def init(self,molecule,basis):
        """
        Initialize the calculation.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        """

        self.molecule=molecule
        self.basis=basis
        
        #Define box size
        natoms=molecule.number_of_atoms()
        self.atomnr=molecule.elem_ids_to_numpy()
        coords=molecule.get_coordinates()
        self.coords=coords
        xmin=coords[:,0].min()-self.grid_margins
        xmax=coords[:,0].max()+self.grid_margins
        ymin=coords[:,1].min()-self.grid_margins
        ymax=coords[:,1].max()+self.grid_margins
        zmin=coords[:,2].min()-self.grid_margins
        zmax=coords[:,2].max()+self.grid_margins
        nx = math.ceil((xmax-xmin)*self.grid_density)
        ny = math.ceil((ymax-ymin)*self.grid_density)
        nz = math.ceil((zmax-zmin)*self.grid_density)
        dx = (xmax-xmin)/nx
        dy = (ymax-ymin)/ny
        dz = (zmax-zmin)/nz
        
        self.origin=(xmin,ymin,zmin)
        self.stepsize=(dx,dy,dz)
        self.npoints=(nx,ny,nz)
        self.grid=CubicGrid(self.origin, self.stepsize, self.npoints)
        
        #Create a small box for each atom
        nx_atom = math.ceil(self.atombox_radius/dx*2)
        ny_atom = math.ceil(self.atombox_radius/dy*2)
        nz_atom = math.ceil(self.atombox_radius/dz*2)
        self.atom_origin=(-nx_atom*dx/2,-ny_atom*dy/2,-nz_atom*dz/2)
        self.atom_npoints = (nx_atom, ny_atom, nz_atom)
        
        Atomgrid = CubicGrid( self.atom_origin, self.stepsize, self.atom_npoints)
        
        #Create atomic map
        vis_drv = VisualizationDriver()
        ao_info = vis_drv.get_atomic_orbital_info(molecule, basis)
        natoms=len(ao_info)
        
        #Create reverse atomic map
        atom_to_ao = vis_drv.map_atom_to_atomic_orbitals(molecule, basis)
        self.ao_to_atom =[[] for i in range(natoms)]
        for iatom, atoms in enumerate(atom_to_ao):
            for iorb, orb in enumerate(atoms):
                self.ao_to_atom[orb]=[iatom,iorb]        
        
        #Compute each unique AO on the grid
        self.AOdict={}
        for iatom, atom in enumerate(self.atomnr):
            if atom not in self.AOdict:
                atomlist=[]
                for orb in atom_to_ao[iatom]:
                    vis_drv.compute_atomic_orbital_for_grid(Atomgrid, basis, ao_info[orb])
                    atomlist.append(Atomgrid.values_to_numpy())
                self.AOdict[atom]=atomlist
        
    def compute(self,orbital, index):
        """
        Compute a specific molecular orbital.

        :param orbital:
            A MolecularOrbital object.
        :param index:
            The index of the molecular orbital of interest.

        :return:
            A tuple with:
               - The numpy array with the value of the MO on the grid.
               - A CubicGrid containing the grid information
        """
        thisorb=orbital[:,index]
        
        #Create full grid
        nx, ny, nz = self.atom_npoints
        nporb=np.zeros(self.npoints)
        
        #Loop over AOs
        for icoef, coef in enumerate(thisorb):
            if abs(coef)>self.mo_threshold:
                iatom, iorb = self.ao_to_atom[icoef]
                thisatom=self.atomnr[iatom]
                AO=self.AOdict[thisatom][iorb]
                t = np.round((self.coords[iatom]-self.origin+self.atom_origin)/self.stepsize).astype('int')
                ncopy = [nx, ny, nz]
                p1= [0,0,0]
                for i in range(3):
                    if t[i]<0:
                        p1[i]=-t[i]
                        t[i]=0
                        ncopy[i]-=p1[i]
                    if t[i]+ncopy[i]>=self.npoints[i]:
                        ncopy[i]=self.npoints[i]-t[i]
                nporb[t[0]:t[0]+ncopy[0],t[1]:t[1]+ncopy[1],t[2]:t[2]+ncopy[2]] += coef*AO[p1[0]:p1[0]+ncopy[0],p1[1]:p1[1]+ncopy[1],p1[2]:p1[2]+ncopy[2]]

        return nporb, self.grid


class nb_orbviewer:
    """
    An orbital visualizer for jupyter notebook

    Instance variables
        - vv: The veloxviz driver, where grid settings are defined.
    """
    def __init__(self):
        self.vv=veloxviz()
        if k3d == None or widgets == None:
            print('''Error: nb_orbviewer is an optional addition to VeloxChem. To be able to run it, you need to install k3d
    conda install -c conda-forge k3d
    jupyter nbextension install --py --sys-prefix k3d
    jupyter nbextension enable --py --sys-prefix k3d
          ''')
            exit()

    def init(self, molecule,basis):
        """
        Initialize the calculation.

        :param molecule:
            The molecule.
        :param basis:
            The AO basis set.
        """

        self.molecule=molecule
        self.vv.init(molecule,basis)

    def plot(self, MO_object):
        """
        Plot the orbitals, with a widget to choose which.

        :param molecule:
            The molecule.
        """

        self.iorb=self.molecule.number_of_beta_electrons()-1
        MOs=MO_object.alpha_to_numpy()
        self.MOs=MOs
        self.thisplot = k3d.plot(grid_visible=False)
        self.plt_atoms, self.plt_bonds = self.drawmol(self.molecule)
        self.thisplot += self.plt_atoms
        for bonds in self.plt_bonds:
            self.thisplot += bonds
        orbital, grid=self.vv.compute(MOs, self.iorb)
        self.plt_iso, self.plt_iso2 = self.draworb(grid,orbital)
        self.thisplot += self.plt_iso
        self.thisplot += self.plt_iso2
        self.thisplot.display()
        
        #Create orbital list:
        orbene=MO_object.ea_to_numpy()
        orbocc=MO_object.occa_to_numpy()
        orblist=[]
        for i in range(len(orbene)):
            orblist.append((f'{i+1:3d} occ={orbocc[i]:.3f} ene={orbene[i]:.3f}',i))
        
        #Add widget
        int_range = widgets.Dropdown(
            options=orblist,
            value=self.iorb,description='Orbital:')
        display(int_range)
        int_range.observe(self.on_orb_index_change, names='value')
    def on_orb_index_change(self,change):
        """
        Register a widget event to plot a different orbital.

        :param change:
            A dictionary created by the widget observe.
        """
        self.thisplot.camera_auto_fit=False #To avoid disturbing the current view
        self.thisplot-=self.plt_iso
        self.thisplot-=self.plt_iso2
        self.iorb=change['new']
        orbital, grid=self.vv.compute(self.MOs, self.iorb)
        self.plt_iso, self.plt_iso2 = self.draworb(grid,orbital)
        self.thisplot += self.plt_iso
        self.thisplot += self.plt_iso2
        self.thisplot.render()
        
        

    def drawmol(self,molecule):
        """
        Draw a ball and stick model of the molecule.

        :param molecule:
            The molecule.

        :return:
            A tuple with:
                - a k3d points objects for all atoms
                - a list of k3d line objects, 2 per bonds 
        """
        atomcolor=np.array([0xFFFFFF,0xD9FFFF,0xCC80FF,0xC2FF00,0xFFB5B5,0x909090,0x3050F8,0xFF0D0D,0x90E050,0xB3E3F5,0xAB5CF2,0x8AFF00,0xBFA6A6,0xF0C8A0,0xFF8000,0xFFFF30,0x1FF01F,0x80D1E3,0x8F40D4,0x3DFF00,0xE6E6E6,0xBFC2C7,0xA6A6AB,0x8A99C7,0x9C7AC7,0xE06633,0xF090A0,0x50D050,0xC88033,0x7D80B0,0xC28F8F,0x668F8F,0xBD80E3,0xFFA100,0xA62929,0x5CB8D1,0x702EB0,0x00FF00,0x94FFFF,0x94E0E0,0x73C2C9,0x54B5B5,0x3B9E9E,0x248F8F,0x0A7D8C,0x006985,0xC0C0C0,0xFFD98F,0xA67573,0x668080,0x9E63B5,0xD47A00,0x940094,0x429EB0,0x57178F,0x00C900,0x70D4FF,0xFFFFC7,0xD9FFC7,0xC7FFC7,0xA3FFC7,0x8FFFC7,0x61FFC7,0x45FFC7,0x30FFC7,0x1FFFC7,0x00FF9C,0x00E675,0x00D452,0x00BF38,0x00AB24,0x4DC2FF,0x4DA6FF,0x2194D6,0x267DAB,0x266696,0x175487,0xD0D0E0,0xFFD123,0xB8B8D0,0xA6544D,0x575961,0x9E4FB5,0xAB5C00,0x754F45,0x428296,0x420066,0x007D00,0x70ABFA,0x00BAFF,0x00A1FF,0x008FFF,0x0080FF,0x006BFF,0x545CF2,0x785CE3,0x8A4FE3,0xA136D4,0xB31FD4,0xB31FBA,0xB30DA6,0xBD0D87,0xC70066,0xCC0059,0xD1004F,0xD90045,0xE00038,0xE6002E,0xEB0026],dtype="uint32")
        atomradius=[0.53,0.31,1.67,1.12,0.87,0.67,0.56,0.48,0.42,0.38,1.90,1.45,1.18,1.11,0.98,0.88,0.79,0.71,2.43,1.94,1.84,1.76,1.71,1.66,1.61,1.56,1.52,1.49,1.45,1.42,1.36,1.25,1.14,1.03,0.94,0.88,2.65,2.19,2.12,2.06,1.98,1.90,1.83,1.78,1.73,1.69,1.65,1.61,1.56,1.45,1.33,1.23,1.15,1.08,2.98,2.53,1.95,1.85,2.47,2.06,2.05,2.38,2.31,2.33,2.25,2.28,2.26,2.26,2.22,2.22,2.17,2.08,2.00,1.93,1.88,1.85,1.80,1.77,1.74,1.71,1.56,1.54,1.43,1.35,1.27,1.20]
        natoms=molecule.number_of_atoms()
        atomnr=molecule.elem_ids_to_numpy()-1
        coords=molecule.get_coordinates().astype('float32')

        #Create a list of colors and radii
        colors=[]
        radii=[]
        for nr in atomnr:
            if nr<len(atomcolor):
                colors.append(atomcolor[nr])
            else:
                colors.append(atomcolor[len(atomcolor)-1])
            if nr<len(atomradius):
                radii.append(atomradius[nr])
            else:
                radii.append(2.0)

        #Balls
        plt_atoms = k3d.points(positions=coords, point_size=0.7, colors=colors)

        #Sticks
        plt_bonds=[]
        for i in range(natoms):
            colori=colors[i]
            for j in range(i+1,natoms):
                bond=(radii[i]+radii[j])/0.529
                if np.linalg.norm(coords[i,:]-coords[j,:])<1.25*bond:
                    colorj=colors[j]
                    plt_bonds.append(k3d.line([coords[i,:],0.5*(coords[i,:]+coords[j,:])], width=0.35,colors=[colori,colori],shader='mesh',radial_segments=16))
                    plt_bonds.append(k3d.line([0.5*(coords[i,:]+coords[j,:]),coords[j,:]], width=0.35,colors=[colorj,colorj],shader='mesh',radial_segments=16))

        return plt_atoms, plt_bonds

    def draworb(self,grid,orbital,isovalue=0.07):
        """
        Draw an isosurface of the orbitals

        :param grid:
            The cubic grid containing the grid information.
        :param orbital:
            The molecular orbital on the grid

        :return:
            A tuple with the k3d positive and negative isosurfaces
        """
        orbital2=np.swapaxes(orbital,0,2).astype('float32') #There is a mismatch between the x,y,z order of vlx and k3d

        #Plot orbitals
        xmin, ymin, zmin = grid.get_origin()
        dx, dy, dz = grid.get_step_size()
        nx, ny, nz = grid.get_num_points()
        xmax=xmin+(nx-1)*dx
        ymax=ymin+(ny-1)*dy
        zmax=zmin+(nz-1)*dz

        bounds=[xmin,xmax,ymin,ymax,zmin,zmax]

        plt_iso = k3d.marching_cubes(orbital2, compression_level=9, bounds=bounds, level=isovalue,
                             flat_shading=False, opacity=1.0)
        plt_iso2 = k3d.marching_cubes(orbital2, compression_level=9, bounds=bounds, level=-isovalue,
                             flat_shading=False, color=0xff0000, opacity=1.0)
        return plt_iso, plt_iso2
