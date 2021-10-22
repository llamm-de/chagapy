# ChaosGame implementation in C++

This is a simple implementation of the chaos game written in C++. 

## Getting started

### Install dependencies
Chagapy uses the third party library [CLI11](https://github.com/CLIUtils/CLI11/tree/70f8072f9dd2292fd0b9f9e5f58e279f60483ed3) for processing of command line arguments. You can add the library automatically using 
```
git submodule init
git submodule update
```
This should clone the necessary file into the project. 

### Building the program
To compile and run the code, you need [CMake](https://www.cmake.org) installed on your system. Now you have to create a build directory using 
```mkdir build && cd build```. From here, you execute CMake by calling 
```
cmake <path-to-source-code>
```
where ```<path-to-source-code>``` must be set to the root of the projects directory.
Once CMake has generated the appropriate build files for your system, just run 
```
make release
```
to compile the program into a binary. If you want to build the executable in debug mode, please use ```make debug``` instead.

### Installation
To install Chagapy, you only need to call ```sudo make install```.


## Examples
Examples can be run and visualized using the [main.py](python/main.py) script. Before executing the script, first install the python 
dependencies listed in the [requirements.txt](python/requirements.txt) file.

## License

This project is licensed under the MIT license - see the [LICENSE.md](LICENSE.md) file for further details.

