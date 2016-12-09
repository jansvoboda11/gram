include_directories(../../include)
include_directories(include)

set(SOURCE_FILES
        src/util/FakeBoolGenerator.cpp
        src/util/FakeNumberGenerator.cpp
        )

add_library(gram_test_fake STATIC ${SOURCE_FILES})
