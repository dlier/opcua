cmake_minimum_required (VERSION 3.5.1)
project (server)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/bin)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/include)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin)

set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/server.c)

add_executable (server ${SOURCES})

target_link_libraries (server json-c open62541)
