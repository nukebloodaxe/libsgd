## Welcome to LibSGD

Following Mark Sibly's death, this is a forked repository containing minor fixes to get compilation working.  Please compile from the development branch, as Dawn is currently broken in the main branch.

Please also note the extra sections added to this repository, such as the project [basically what needs to be done], discussions [please start here], and wiki areas.  [The Wiki is very empty right now]

Discussion is occurring regarding the library on Discord: https://discord.gg/f9g34x4u

MPzCodes has a compiled version of the 0.18 version of LibSGD with blitz3D available in the following repository for testing: https://github.com/MPzCodes/Blitz3D-with-libsgd

LibSGD is a simple game development library that provides a high-level, easy-to-use 'scene graph' style API for writing games and apps.

LibSGD also supports loading and playing audio and will eventually include network functionality.

The library is coded in C++, but the primary public API is pure 'C', making it highly compatible with a wide range of platforms and languages.

Currently supported languages include C/C++, Blitz3D, BlitzMax, Python and node.js. Support for more languages  is on the way.

Please note that Pull Requests are not currently being accepted for this repository.

LibSGD is licensed under the Zlib/PNG license.

Join the LibSFD discussion at https://skirmish-dev.net/forum [Currently Offline]

Help support LibSGD at https://patreon.com/libsgd


### CMake build instuctions for 64bit Windows 10

* Install git, cmake, python3 and MSVC (I use the free 2022 Community Edition).

* Clone this repository, CD to checkout dir and:

* Configure: ``cmake -S . -B cmake-build-windows-release -G "Visual Studio 17 2022"``

* Build: ``cmake --build cmake-build-windows-release --config Release``

* Install: ``cmake --install cmake-build-windows-release --config Release``

After install, output files should end up in cmake-build-windows-release/LIBSGD_INSTALL dir.


### CMake build instuctions for 64bit Linux (tested on Manjaro KDE)

* You will need at least git, cmake, python3, g++, binutils etc. You may also need to install dev packages for things like x11, openssl and so on.

* Clone this repository, CD to checkout dir and...

* Configure: ``cmake -S . -B cmake-build-linux-release -DCMAKE_BUILD_TYPE=Release``

* Build: ``cmake --build cmake-build-linux-release``

* Install: ``cmake --install cmake-build-linux-release``

After install, output files should end up in cmake-build-linux-release/LIBSGD_INSTALL dir.


### CMake build instructions for MacOS (tested on Sonoma 14.4.1)

* Install 'XCode' from app store.

* Install 'homebrew' from: https://brew.sh/

* Install cmake using 'brew install cmake'.

* Install openssl using 'brew install openssl'.

* Clone this repository, CD to checkout dir and:

* Configure: ``cmake -S . -B cmake-build-macos-release -DCMAKE_BUILD_TYPE=Release``

* Build: ``cmake --build cmake-build-macos-release``

* Install: ``cmake --install cmake-build-macos-release``

After install, output files should end up in cmake-build-macos-release/LIBSGD_INSTALL dir.


### Build instructions for the BlitzMax target

* Build the libsgd/blitzmax/sgd2bmx.bmx tool and place the output executable somewhere in you system path.

* Set the cmake option SGD_BLITZMAX_TARGET_ENABLED to ON. You can do this by passing -DSGD_BLITZMAX_TARGET_ENABLED=ON to cmake when configuring.

After building and installing, LIBSGD_INSTALL should include an additional blitzmax directory containing the SGD blitzmax module.
 

### Build instructions for the Python target

* Install the Python development libraries and SWIG.

* Set the cmake option SGD_PYTHON_TARGET_ENABLED to ON. You can do this by passing -DSGD_PYTHON_TARGET_ENABLED=ON to cmake when configuring.

After building and installing, LIBSGD_INSTALL should include an additional Python directory containing the SGD Python module.


### Build instructions for the node.js target

* Install nodejs and SWIG.

* Set the cmake option SGD_NODEJS_TARGET_ENABLED to ON You can do this by passing -DSGD_NODEJS_TARGET_ENABLED=ON to cmake when configuring.

After building and installing, LIBSGD_INSTALL should include an additional nodejs directory containing the SGD nodejs module.


### Build instructions for html help files

* Ensure you have the following Python modules installed:  sphinx and breathe.

* Install Doxygen.

* Set the cmake option SGD_DOCS_TARGET_ENABLED to ON. You can do this by passing -DSGD_DOCS_TARGET_ENABLED=ON to cmake when configuring.  

After building and installing, LIBSGD_INSTALL should include an additional html directory containing the SGD html help files.
