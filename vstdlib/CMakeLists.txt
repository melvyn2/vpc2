project(vstdlib)

if(UNIX AND NOT APPLE AND NOT CYGWIN)
    add_library(vstdlib SHARED)
else()
    add_library(vstdlib STATIC)
endif()

target_sources(vstdlib PUBLIC
                cvar.cpp
                vstrtools.cpp
                random.cpp
                keyvaluessystem.cpp)

target_include_directories(vstdlib PUBLIC ../public ../public/tier0 ../public/tier1)