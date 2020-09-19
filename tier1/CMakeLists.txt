PROJECT(tier1)

if(UNIX AND NOT APPLE AND NOT CYGWIN)
    add_library(tier1 SHARED)
else()
    add_library(tier1 STATIC)
endif()

target_sources(tier1 PUBLIC
                keyvalues.cpp
                checksum_crc.cpp
                checksum_md5.cpp
                convar.cpp
                generichash.cpp
                interface.cpp
                mempool.cpp
                memstack.cpp
                stringpool.cpp
                utlbuffer.cpp
                utlsymbol.cpp
                utlstring.cpp
                tier1.cpp
                characterset.cpp
                splitstring.cpp
                strtools.cpp
                exprevaluator.cpp)

target_include_directories(tier1 PUBLIC ../public ../public/tier0 ../public/tier1)