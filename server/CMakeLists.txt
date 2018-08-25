cmake_minimum_required (VERSION 3.5.1)
project (server)

set ( IS_64_BIT 0 )
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set( IS_64_BIT 1 )
endif ()

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/include)
if (UNIX)
	if ( IS_64_BIT )
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/bin/unix/x64)
	else ()
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/json-c/bin/unix/i386)
	endif ()
elseif (Win32)
endif ()

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/include)
if (UNIX)
	if ( IS_64_BIT )
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin/unix/x64)
	else()
		link_directories    (${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/open62541/bin/unix/i386)
	endif ()
elseif (Win32)
endif ()


set (CMAKE_C_FLAGS "-std=c99")
set (SOURCES src/server.c)

add_executable (server ${SOURCES})

if (UNIX)

	# build for UNIX
	target_link_libraries (server json-c open62541)

elseif (Win32)

	#build for Win32

endif ()
