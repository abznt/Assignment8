set(targetName Statistics)
project(${targetName})

set(srcList
        Statistic.h
        Statistic.cpp
        )

add_library(${targetName} STATIC ${srcList})
target_include_directories(${targetName} PUBLIC ${PROJECT_SOURCE_DIR})
unset(${targetName})