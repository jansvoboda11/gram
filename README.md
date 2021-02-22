# Gram

[![Build Status](https://travis-ci.org/jansvoboda11/gram.svg?branch=main)](https://travis-ci.org/jansvoboda11/gram)

Gram is a lightweight **grammatical evolution** library written in modern C++.

## Documentation

While Gram does not have a standalone documentation, my [bachelor thesis](https://www.fit.vut.cz/study/thesis-file/19143/19143.pdf) contains a high-level overview.

## Build

```shell
cmake -S . -B build/
cmake --build build/
```

## Test

```shell
cmake -S . -B build/ -DGRAM_BUILD_TESTS=ON
cmake --build build/
./build/test/unit/utest
./build/test/acceptance/atest # May not finish.
```
