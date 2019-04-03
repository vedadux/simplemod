# SimpleMod

A small extendable linux kernel module based on ioctl calls. 
Extending the module is as simple as adding a new ioctl constant, and handling it in the kernel module.

# Installation

The `simplelib` library relies on the `simple_mod` kernel module. Both the library and the the kernel module can be build by running

    make

The library can be used by linking it to the application, or as a single header (`simplelib.h`) which can be directly included.

# Requirements

The library requires a recent Linux kernel (tested on 4.11, but should also work on 3.x kernels). 
The library does not rely on any other library. It uses only standard C functionality. 

# Example

The basic functionality (`simplelib_init` and `simplelib_cleanup`) is always required. 
After the initialization, all functions provided by the library can be used. 
The basic implementation also provides the ioctl template in form of `simplelib_hello`,
which makes a ioctl call to the kernel module. 
The kernel module handles such calls in the `device_ioctl` function, similarly to how
a simple kernel implementation might handle syscalls.

To add a new ioctl call:
* Add a new constant in `simple-mod.h`
* Handle the constant in a switch case inside function `device_ioctl` in `simple-mod.c`
* Add a library wrapper inside `simple.c`
* `make` the module and library again
* Install the kernel module with `insmod`
