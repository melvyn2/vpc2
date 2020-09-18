project(VPC2)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

if(UNIX)
    add_compile_definitions(PLATFORM_POSIX POSIX _POSIX)
    add_compile_definitions(GNUC)  # Not sure what this does, but is required
endif()
if(UNIX AND NOT APPLE AND NOT CYGWIN)
    add_compile_definitions(PLATFORM_LINUX LINUX _LINUX)
endif()
if(APPLE)
    add_compile_definitions(OSX _OSX)
endif()
if(WIN32)
    add_compile_definitions(PLATFORM_WINDOWS_PC PLATFORM_WINDOWS WIN32 _WIN32)
endif()


if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_definitions(COMPILER_GCC)  # IDK why but clang == gcc
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_definitions(COMPILER_GCC)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_definitions(COMPILER_MSVC)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE True)

set(CMAKE_C_FLAGS_DEBUG_INIT -DDEBUG -D_DEBUG -O0 -ggdb -g3)
set(CMAKE_CXX_FLAGS_DEBUG_INIT -DDEBUG -D_DEBUG -O0 -ggdb -g3)

set(CMAKE_C_FLAGS_RELEASE_INIT -DNDEBUG -O3 -ggdb -g1)
set(CMAKE_CXX_FLAGS_RELEASE_INIT -DNDEBUG -O3 -ggdb -g1)

set(CMAKE_C_FLAGS -w)
set(CMAKE_CXX_FLAGS -w)


if(APPLE)
    set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_HAVE_THREADS_LIBRARY 1)
    set(CMAKE_USE_WIN32_THREADS_INIT 0)
    set(CMAKE_USE_PTHREADS_INIT 1)
    set(THREADS_PREFER_PTHREAD_FLAG ON)

    add_compile_definitions(PLATFORM_64BITS)
    set(CMAKE_C_FLAGS_INIT -arch x86_64 -m64)
    set(CMAKE_CXX_FLAGS_INIT -arch x86_64 -m64)
else()
    set(CMAKE_C_FLAGS_INIT -arch i386 -m32)
    set(CMAKE_CXX_FLAGS_INIT -arch i386 -m32)
endif()

#add_compile_definitions(USE_LIGHT_MEM_DEBUG)

add_subdirectory(tier0)
add_subdirectory(tier1)
add_subdirectory(vstdlib)
add_subdirectory(interfaces)
add_subdirectory(utils/vpc)