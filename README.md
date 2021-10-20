### Installation

## Linux

###install required libraries: gcc, make, libX

`sudo apt-get install gcc make xorg libxext-dev libbsd-dev`

### Compile MinilibX

run ./configure or make both will make a few tests, create Makefile.gen and then automatically run make on this generated Makefile.gen . libmlx.a and libmlx_$(HOSTTYPE).a are created. test/mlx-test binary is also created.

### Install MinilibX

no installation script is provided. You may want to install
libmlx.a and/or libmlx_$(HOSTTYPE).a in /usr/X11/lib or /usr/local/lib
mlx.h in /usr/X11/include or /usr/local/include
man/man3/mlx*.1 in /usr/X11/man/man3 or /usr/local/man/man3
