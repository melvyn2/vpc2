PROJECT(tier1)

add_library(tier1 STATIC
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