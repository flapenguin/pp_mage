#ifndef _PP_MAGE_
#define _PP_MAGE_

#include <stddef.h>

// Boolean logic
#define PP_TRUE _PP_TRUE
#define PP_FALSE _PP_FALSE

#define PP_NOT(X) PP_CONCAT(_PP_NOT, X)
#define PP_AND(X, Y) PP_IF_ELSE(X, Y, PP_FALSE)
#define PP_OR(X, Y) PP_IF_ELSE(X, PP_TRUE, Y)
#define PP_XOR(X, Y) PP_IF_ELSE(X, PP_NOT(Y), Y)

// Conditionals
#define PP_IF(Condition, Then) PP_APPLY(PP_CONCAT(_PP_IF, Condition), Then)
#define PP_IF_NOT(Condition, Then) PP_IF(PP_NOT(Condition), Then)
#define PP_IF_ELSE(Condition, Then, Else) PP_IF(Condition, Then) PP_IF_NOT(Condition, Else)

// Apply macro
#define PP_APPLY(Fn, ...) _PP_EXPAND( Fn(__VA_ARGS__))
#define PP_ID(x) x

// Apply macro for each arg
#define PP_MAP(Fn, ...) PP_APPLY(PP_CONCAT(_PP_MAP_, PP_NARG(__VA_ARGS__)), Fn, __VA_ARGS__)

// Wrap statement
#define PP_STMT_START do {
#define PP_STMT_END } while(0)
#define PP_STMT(...) PP_STMT_START __VA_ARGS__; PP_STMT_END

// General identifier concat
#define PP_CONCAT(a, b) _PP_CONCAT(a, b)

// Get number of arguments
#define PP_NARG(...) _PP_EXPAND(_xPP_NARG_IMPL(dummy,##__VA_ARGS__,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0))

// Collections
#define PP_CONTAINER_OF(Ptr, Type, Member) ( (Type*)((char*)(Ptr) - (char*)offsetof(Type, Member)) )

// ... Implementation details ...
#define _PP_NOT_PP_TRUE PP_FALSE
#define _PP_NOT_PP_FALSE PP_TRUE

#define _PP_IF_PP_TRUE(X) X
#define _PP_IF_PP_FALSE(X)

#define _PP_EXPAND(x) x
#define _PP_CONCAT(a, b) a ## b

#define _xPP_NARG_IMPL(dummy,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,N,...) N

#define _PP_MAP_1(Fn, _1)\
    Fn(_1 )
#define _PP_MAP_2(Fn, _1, _2)\
    Fn(_1 ) Fn(_2 )
#define _PP_MAP_3(Fn, _1, _2, _3)\
    Fn(_1 ) Fn(_2 ) Fn(_3 )
#define _PP_MAP_4(Fn, _1, _2, _3, _4)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 )
#define _PP_MAP_5(Fn, _1, _2, _3, _4, _5)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 )
#define _PP_MAP_6(Fn, _1, _2, _3, _4, _5, _6)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 )
#define _PP_MAP_7(Fn, _1, _2, _3, _4, _5, _6, _7)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 )
#define _PP_MAP_8(Fn, _1, _2, _3, _4, _5, _6, _7, _8)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 )
#define _PP_MAP_9(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 )
#define _PP_MAP_10(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10)
#define _PP_MAP_11(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11)
#define _PP_MAP_12(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11) Fn(_12)
#define _PP_MAP_13(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11) Fn(_12) Fn(_13)
#define _PP_MAP_14(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11) Fn(_12) Fn(_13) Fn(_14)
#define _PP_MAP_15(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11) Fn(_12) Fn(_13) Fn(_14) Fn(_15)
#define _PP_MAP_16(Fn, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)\
    Fn(_1 ) Fn(_2 ) Fn(_3 ) Fn(_4 ) Fn(_5 ) Fn(_6 ) Fn(_7 ) Fn(_8 ) \
    Fn(_9 ) Fn(_10) Fn(_11) Fn(_12) Fn(_13) Fn(_14) Fn(_15) Fn(_16)

#endif