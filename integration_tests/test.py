from VeloxChemMP import *

app_manager = CAppManager.create("test.inp", "test.out")

app_manager.execute()

assert app_manager.get_state() == True
