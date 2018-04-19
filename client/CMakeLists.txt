cmake_minimum_required (VERSION 3.5.1)
project (client)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/lib)

set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/client.c
	         src/open62541.c)

add_executable (client ${SOURCES})

target_link_libraries (client json-c)
