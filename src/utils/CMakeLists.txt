set(targetName Utils)
project(${targetName})

set(srcList
        FileUtil.h
        FileUtil.cpp
        )

add_library(${targetName} STATIC ${srcList})
target_include_directories(${targetName} PUBLIC ${PROJECT_SOURCE_DIR})
unset(srcList)
unset(targetName)