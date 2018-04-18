cmake_minimum_required (VERSION 3.5.1)
project (client)

set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/client.c src/open62541.c)
add_executable (client ${SOURCES})
