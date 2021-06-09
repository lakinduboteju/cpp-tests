cmake_minimum_required(VERSION 3.10.2)

project(BufferManager)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")

    message(STATUS "<<------------------- Debug Build ------------------->>")
    add_definitions( "-std=gnu++11 -O0 -Wall -Wextra" )

elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RELEASE")

    message(STATUS "<<------------------- Release Build ------------------->>")
    add_definitions( "-std=gnu++11 -O3 -Wall -Wextra" )

endif()

set(exe_name object_alloc)
add_executable(${exe_name}
    main.cpp
)

include(../gtest.cmake)

set(exe_name object_alloc_test)
add_executable(${exe_name}
    Test.cpp
)
target_link_libraries(${exe_name} PRIVATE
    gtest
)
