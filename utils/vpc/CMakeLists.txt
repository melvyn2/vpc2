PROJECT(VPC)
set(CMAKE_CXX_STANDARD 11)

add_executable(vpc)

target_sources(vpc PRIVATE
                exprsimplifier.cpp
                groupscript.cpp
                conditionals.cpp
                macros.cpp
                projectscript.cpp
                scriptsource.cpp
                baseprojectdatacollector.cpp
                configuration.cpp
                dependencies.cpp
                main.cpp
                projectgenerator_makefile.cpp
                solutiongenerator_makefile.cpp
                solutiongenerator_xcode.cpp
                sys_utils.cpp
                ../vpccrccheck/crccheck_shared.cpp
                projectgenerator_codelite.cpp
                solutiongenerator_codelite.cpp
                projectgenerator_linux.cpp
                projectgenerator_vscode.cpp
                projectgenerator_cmake.cpp
                projectgenerator_clangdb.cpp
                solutiongenerator_linux.cpp)

target_include_directories(vpc PUBLIC ../../public ../../public/tier0 ../../public/tier1)

target_link_directories(vpc PUBLIC ../..)

if(APPLE)
find_library(FOUNDATION Foundation)
target_link_libraries(vpc tier1 tier0 vstdlib interfaces iconv ${FOUNDATION})
elseif(UNIX AND NOT APPLE AND NOT CYGWIN)
    target_link_libraries(vpc tier1 tier0 vstdlib interfaces pthread dl)
else()
    target_link_libraries(vpc tier1 tier0 vstdlib interfaces pthread)
endif()