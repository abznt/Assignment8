set(libname ExpressionTree)

set(srcList
        Node.cpp
        Node.h
        UnaryNode.cpp
        UnaryNode.h
        Positive.cpp
        Positive.h
        Negative.cpp
        Negative.h
        BinaryNode.cpp
        BinaryNode.h
        Add.cpp
        Add.h
        Sub.cpp
        Sub.h
        Mul.cpp
        Mul.h
        Div.cpp
        Div.h
        LeafNode.cpp
        LeafNode.h
        Constant.cpp
        Constant.h
        Variable.cpp
        Variable.h
        ExpressionTree.cpp
        ExpressionTree.h)

add_library(${libname} STATIC ${srcList})
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

unset(srcList)
unset(libname)
