cmake_minimum_required (VERSION 3.5.1)
project (client)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
if (UNIX)
	link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/bin/unix/x64)
elseif (Win32)
	# bla
endif ()

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/include)
if (UNIX)
link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin/unix/x64)
elseif (Win32)
	#bla
endif ()

set (SOURCES src/client.cpp
	     src/intfopcua.cpp
	     src/intfjson.cpp
	     src/getdata.cpp)

add_executable (client ${SOURCES})

set_target_properties(client PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS YES
)


if (UNIX)

	# build for UNIX
	target_link_libraries (client json-c open62541 pthread)

elseif (Win32)

	# build for Win32

endif ()

	
