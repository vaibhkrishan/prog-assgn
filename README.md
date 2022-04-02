# Programming Assignment: 5-swans
I have written the writer in Python and the reader in C++.

The files are: writer.py, reader.cpp.

# Writer
To run the writer, simply run: python3 writer.py <path_to_fb_bytes.bin>
Note that this uses python3, not python2. The code will not run with python2.
If the path to fb_bytes.bin is not provided, the default value is taken as "fb_bytes.bin" in the current working directory.

# Reader
To compile the reader, simply run: g++ --std=c++0x reader.cpp -o <path_to_executable>
Note that I'm using C++11, which is necessary for the code to run.
To run the reader, run: <path_to_executable> <path_to_fb_bytes.bin>
Same as that in the writer, the default path for "fb_bytes.bin" is in the current working directory.
