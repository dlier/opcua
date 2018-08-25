cmake_minimum_required (VERSION 3.5.1)
project (client)

set ( IS_64_BIT 0 )
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	set( IS_64_BIT 1 )
endif ()

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
if (UNIX)
	if ( IS_64_BIT )
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../4rdParty/json-c/bin/unix/x64)
	else ()
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../4rdParty/json-c/bin/unix/i386)
	endif ()
elseif (Win32)
endif ()

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/include)
if (UNIX)
	if ( IS_64_BIT )
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin/unix/x64)
	else ()
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin/unix/i386)
	endif ()
elseif (Win32)
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

	
