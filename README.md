# PP_MAGE - preprocessor magic for your sources

[![Build Status](https://travis-ci.org/flapenguin/pp_mage.svg)](https://travis-ci.org/flapenguin/pp_mage)

## Overview
This **header-only** library for C and C++ provides number of usefull macros you can use to simplify your sources.

This is collection of good usefull macros you probably want to have.

## Building
No building is required, just add include directory to include path of your compiler.

You can use `make` or `make tests` to run tests.

## Documentation

### Booleans
`PP_TRUE`, `PP_FALSE` - constants.

`PP_NOT`, `PP_AND`, `PP_OR`, `PP_XOR` - logic functions.

### Conditions
`PP_IF(Condition, Then)` - expands to `Then` if `Condition` is true, expands to empty otherwise.

`PP_IFNOT(Condition, Then)` - expands to `Then` if `Condition` is false, expands to empty otherwise.

`PP_IF_ELSE(Condition, Then, Else)` - expands to `Then` if `Condition` is true, expands to `Else` otherwise.

### Functionals
`PP_NARG` and `PP_MAP` are limited by 16 arguments in current version.

`PP_APPLY(Macro, arg1, arg2, ...)` - expands to `Macro(arg1, arg2, ...)`.

`PP_NARG(arg1, ..., argN)` - expands to number `N`.

`PP_MAP(Macro, arg1, arg2 ...)` - expands to `Macro(arg1) Macro(arg2) ...`.

### Utilities

`PP_CONCAT(Foo, Bar)` - classical indirection concatenation macro.

`PP_CONTAINER_OF(Ptr, ParentType, Member)` - gets `ParentType*` by pointer `Ptr` to its `Member`.

### Blocks
Next macros are usefull for reducing braces and do-whiles in huge macros.

`PP_STMT_START` - expands to `do {`.

`PP_STMT_END` - expands to `} while(0)`.

`PP_STMT(...)` - expands to `do { ... } while(0)`.
