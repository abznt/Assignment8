set(targetName Main)
project(${targetName})

add_subdirectory(expressiontree)

add_executable(${targetName} main.cpp)
target_link_libraries(${targetName} ExpressionTree)

unset(targetName)