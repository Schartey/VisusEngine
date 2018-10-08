rm -r build
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=.. -DBUILD_SHARED_LIB=ON
make
make install
