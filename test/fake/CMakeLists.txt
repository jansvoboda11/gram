include_directories(.)

set(SOURCE_FILES
        util/FakeNumberGenerator.cpp
        util/FakeNumberGenerator.h
        )

add_library(gram_test_fake STATIC ${SOURCE_FILES})
