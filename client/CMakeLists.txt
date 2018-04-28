cmake_minimum_required (VERSION 3.5.1)
project (client)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/bin)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/include)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin)

set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/client.cpp
		     src/intfopcua.cpp
			 src/intfjson.cpp)

add_executable (client ${SOURCES})

target_link_libraries (client json-c open62541)
