for f in *.cpp ; do arm-linux-g++ -fPIC -c $f ; done
arm-linux-g++ -shared -o libnanoGL.so *.o
