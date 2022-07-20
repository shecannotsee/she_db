echo "["$(date "+%Y-%m-%d %H:%M:%S")"]build"
make
echo "["$(date "+%Y-%m-%d %H:%M:%S")"]run"
./main
echo "["$(date "+%Y-%m-%d %H:%M:%S")"]clean"
rm -rf main