# Message passing practise using Google's Protobuf

This repository is created for our team members to get familiar with
Google's protobuf library which is a extremely good library for creating
structured data. The Swarm Project intends to use Google's protobuf
to send structured data (messages) for their communication infrastructure
to have a proper protocol to send/receive messages to the bots.

## Platform

Please make sure you are running Ubuntu systems. If you are using other
linux systems, then it would be a little more pain to configure this.
Just try and avoid using any unix system for this development. Windows
is a big NO NO!

**Note:** There are two versions of protobuf ie. v2 and v3. We will be
using the **v3** and **not v2**. Please make sure you have that version
otherwise it will cause unnecessary problems.

Also we will be using mainly C++ for all of our communications system
so we will try to only support this and not other languages.

## Installing Google's Protobuf

Firstly you would need some packages for the build systems to work. To
install those things in Ubuntu, type this: 

`$ sudo apt-get install autoconf automake libtool curl make g++ unzip`

On other platforms, you would need to use their own package management
system to install dependencies. 

The methods to install protobuf are:

 * Using `apt-get`: This is a bad method since the Ubuntu packages are not
   updated and currently they are on protobuf v2 while we would be using
   v3.

 * Cloning their github repo and build the latest tip of master: This is
   a good method if you are **really desperate** to get the latest commits.
   Unfortunately their bazel build system isn't that robust and is failing
   on some machines, so just try and avoid this. And on top of that you
   will also have to download and configure gmock source and then generate
   various template Makefiles and configure script. Not worth the effort!

 * Get the stable v3: This is the most reliable method. Get the source
   code for the v3 tag.
   [Here](https://github.com/google/protobuf/releases/tag/v3.0.0) is the
   release tag for the same. You can get a zipped source code from here.

Now let's come to how to actually install. These steps need to be followed: 

```
$ ./configure
$ make
$ make check
$ sudo make install
$ sudo ldconfig                         #refresh the shared library cache
```

**Note:** If `make check` fails, you can still install, but some features
of the library won't work.

A very detailed installation documentation can be found
[here](https://github.com/google/protobuf/blob/master/src/README.md).
It also contains how to configure protobuf on all systems. If you
are able to configure it all by yourself, well and good!

## Compiling the source code

Our build process is quite simple and we have avoided the use of fancy
tools as much as we can. We simply use Makefiles.

To compile: 

`$ make`

## Binaries

There should be two binaries created `read` and `write` and it is self
explanatory as to what they would be doing. 

`write`: reads the various values from standard input stream and writes
         the protobuf message to a file passed in the arguments.

`read`: reads the protobuf values from a file passed in the arguments
        and outputs the various values to the standout output stream.

## Running

To run the `write` program, use: 

`$ ./write hi.txt`

where `hi.txt` is the file name where the protobuf message will be
stored.

Other binaries should follow the same convention.

## Learning about Protobuf

To learn about protobuf, nothing can be better than Google's own
documentation. Clone the
[protobuf's github repo](https://github.com/google/protobuf) and read
the examples in the directory `examples/` and `docs/`.

For a proper tutorial please refer
[here](https://developers.google.com/protocol-buffers/).
