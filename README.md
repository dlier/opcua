# opcua
opc ua server and client testing

the targets are:
  -to be able to get data from any OPC UA server
  -to be able to configure the data types, name and interval in a jsonfile
  -to get them on a cyclic interval and to store the data in files

how to build 'server':
  cd  /opcua/server
  mkdir build
  cd build
  cmake ..
  make

the you can run the server:
  ./server

how to build 'client':
cd  /opcua/client
mkdir build
cd build
cmake ..
make

the you can run the server:
  ./client ../cfg/configuration.json
  
have fun...
