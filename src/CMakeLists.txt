set(targetName Main)
project(${targetName})

add_subdirectory(statistics)
add_subdirectory(utils)

add_executable(${targetName} main.cpp)
target_link_libraries(${targetName} Statistics)
target_link_libraries(${targetName} Utils)

unset(targetName)