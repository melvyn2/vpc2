PROJECT(tier0)

if(UNIX AND NOT APPLE AND NOT CYGWIN)
    add_library(tier0 SHARED)
else()
    add_library(tier0 STATIC)
endif()

target_sources(tier0 PUBLIC
        assert_dialog.cpp
        cpu_posix.cpp
        cpu.cpp
        dbg.cpp
        fasttimer.cpp
        mem.cpp
        mem_helpers.cpp
        memdbg.cpp
        memstd.cpp
        memvalidate.cpp
        minidump.cpp
        pch_tier0.cpp
        threadtools.cpp
        valobject.cpp
        vprof.cpp
        platform_posix.cpp
        pme_posix.cpp
        commandline.cpp
        win32consoleio.cpp
        logging.cpp
        tier0_strtools.cpp)
target_include_directories(tier0 PUBLIC ../public ../public/tier0 ../public/tier1)