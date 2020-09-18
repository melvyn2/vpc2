project(vstdlib)

add_library(vstdlib STATIC
        cvar.cpp
        vstrtools.cpp
        random.cpp
        keyvaluessystem.cpp)
target_include_directories(vstdlib PUBLIC ../public ../public/tier0 ../public/tier1)