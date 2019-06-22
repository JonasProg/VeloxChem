import time as tm
import sys
import os

from .errorhandler import assert_msg_critical


class OutputStream:
    """Implements the output stream.

    Implements the output stream.

    Attributes
    ----------
    width
        Width of the output.
    buffer_lines
        The buffered lines of output.
    stream
        The stream to which output is printed.
    state
        The flag for writing to the stream.
    """

    def __init__(self, filename=None, width=122):
        """Initializes the output stream.

        Initializes the output stream.

        Parameters
        ----------
        filename
            Name of the output file (or sys.stdout).
        width
            Width of the output.
        """

        self.width = width
        self.buffer_lines = []

        # filename is...
        #   None or empty:  stream is None
        #   sys.stdout:     stream is sys.stdout
        #   string:         stream is file handle

        if filename is None:
            self.stream = None
            self.state = False

        elif not filename or filename == '-':
            errio = "OutputStream: invalid argument"
            assert_msg_critical(False, errio)

        elif filename is sys.stdout:
            self.stream = sys.stdout
            self.state = True

        else:
            try:
                self.stream = open(filename, 'w')
            except OSError:
                errio = "OutputStream: cannot open output file "
                errio += "{}".format(filename)
                assert_msg_critical(False, errio)
            self.state = True

    def __del__(self):
        """Deletes the output stream.
        """

        if self.state:
            if self.buffer_lines:
                self.flush()
            if self.stream is not sys.stdout:
                self.stream.close()

    def get_state(self):
        """Gets the state of the output stream.

        Returns
        -------
            State of the output stream.
        """

        return self.state

    def flush(self):
        """Flushes the buffered output to stream.
        """

        if self.state:
            for line in self.buffer_lines:
                self.stream.write(line)
            self.stream.flush()
            del self.buffer_lines[:]

    @staticmethod
    def header(line, width):
        """Gets the header string.

        Gets the header string.

        Parameters
        ----------
        line
            The line of text.
        width
            Width of the output.

        Returns
        -------
            The header string.
        """

        length = len(line)
        left = (width - length) // 2
        right = width - length - left
        return ' ' * left + line + ' ' * right

    @staticmethod
    def title(line, width):
        """Gets the title string.

        Gets the title string.

        Parameters
        ----------
        line
            The line of text.
        width
            Width of the output.

        Returns
        -------
            The title string.
        """

        length = len(line)
        left = (width - 2 - length) // 2
        right = width - 2 - length - left
        return '!' + ' ' * left + line + ' ' * right + '!'

    @staticmethod
    def info(line, width):
        """Gets the information string.

        Gets the information string.

        Parameters
        ----------
        line
            The line of text.
        width
            Width of the output.

        Returns
        -------
            The information string.
        """

        length = len(line)
        left = 9
        right = width - length - left
        return '* Info * ' + line + ' ' * right

    @staticmethod
    def tsep(width):
        """Gets the separator string.

        Gets the separator string.

        Parameters
        ----------
        width
            Width of the output.

        Returns
        -------
            The separator string.
        """

        return '!' + '=' * (width - 2) + '!'

    def print_line(self, line):
        """Prints the line to stream.

        Prints the line to stream.

        Parameters
        ----------
        line
            The line of text.
        """

        if not self.state:
            return
        self.buffer_lines.append(line + os.linesep)

    def print_blank(self):
        """Prints a blank line to stream.
        """

        if not self.state:
            return
        self.buffer_lines.append(' ' * self.width + os.linesep)

    def print_header(self, line):
        """Prints a header line to stream.

        Prints a header line to stream.

        Parameters
        ----------
        line
            The line of text.
        """

        if not self.state:
            return
        self.buffer_lines.append(self.header(line, self.width) + os.linesep)

    def print_title(self, line):
        """Prints a title line to stream.

        Prints a title line to stream.

        Parameters
        ----------
        line
            The line of text.
        """

        if not self.state:
            return
        self.buffer_lines.append(self.title(line, self.width) + os.linesep)

    def print_info(self, line):
        """Prints an information line to stream.

        Prints an information line to stream.

        Parameters
        ----------
        line
            The line of text.
        """

        if not self.state:
            return
        self.buffer_lines.append(self.info(line, self.width) + os.linesep)

    def print_separator(self):
        """Prints a separator line to stream.
        """

        if not self.state:
            return
        self.buffer_lines.append(self.tsep(self.width) + os.linesep)

    def print_block(self, block_lines):
        """Prints a block of lines to stream.

        Prints a block of lines to stream.

        Parameters
        ----------
        block_lines
            The multiple lines of text.
        """

        if not self.state:
            return

        lines = block_lines.split(os.linesep)
        for line in lines:
            self.print_header(line)

    def print_start_header(self, num_nodes):
        """Prints start header to output stream.

        Prints start header to output stream.

        Parameters
        ----------
        num_nodes
            The number of MPI processes.
        """

        if not self.state:
            return tm.time()

        start_time = tm.time()

        self.print_separator()
        self.print_title("")
        self.print_title("VELOXCHEM (V.0.0 2019)")
        self.print_title("AN ELECTRONIC STRUCTURE CODE")
        self.print_title("")
        self.print_title("Copyright (c) 2019 VeloxChem developers.")
        self.print_title("All rights reserved.")
        self.print_separator()
        exec_str = "VeloxChem execution started"
        if num_nodes > 1:
            exec_str += " on " + str(num_nodes) + " compute nodes"
        exec_str += " at " + tm.asctime(tm.localtime(start_time)) + "."
        self.print_title(exec_str)
        self.print_separator()
        self.print_blank()

        return start_time

    def print_finish_header(self, start_time):
        """Prints finish header to output stream.

        Prints finish header to output stream.

        Parameters
        ----------
        start_time
            The start time of the computation.
        """

        if not self.state:
            return

        end_time = tm.time()

        self.print_separator()
        exec_str = "VeloxChem execution completed at "
        exec_str += tm.asctime(tm.localtime(end_time)) + "."
        self.print_title(exec_str)
        self.print_separator()
        exec_str = "Total execution time is "
        exec_str += "{:.2f}".format(end_time - start_time) + " sec."
        self.print_title(exec_str)
        self.print_separator()
        self.flush()
