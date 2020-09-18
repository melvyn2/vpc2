project(interfaces)

add_library(interfaces STATIC interfaces.cpp)

target_include_directories(interfaces PUBLIC ../public ../public/tier0)