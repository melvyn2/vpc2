project(interfaces)

if(UNIX AND NOT APPLE AND NOT CYGWIN)
    add_library(interfaces SHARED interfaces.cpp)
else()
    add_library(interfaces STATIC interfaces.cpp)
endif()

target_include_directories(interfaces PUBLIC ../public ../public/tier0)