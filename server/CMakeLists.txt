cmake_minimum_required (VERSION 3.5.1)
project (server)

set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/server.c src/open62541.c)
add_executable (server ${SOURCES})
