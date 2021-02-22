# Gram

[![Build Status](https://travis-ci.org/jansvoboda11/gram.svg?branch=master)](https://travis-ci.org/jansvoboda11/gram)

Gram is a lightweight **grammatical evolution** library written in modern C++.

## Build

```
cmake -S . -B build/
cmake --build build/
```

## Test

```
cmake -S . -B build/ -DGRAM_BUILD_TESTS=ON
cmake --build build/
./build/test/unit/utest
./build/test/acceptance/atest # May not finish.
```
