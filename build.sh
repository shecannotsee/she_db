BUILD=./build
if [ ! -d "$BUILD" ]; then
    mkdir build
fi

cd build
cmake -G Ninja ..
ninja