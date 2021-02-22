include(FetchContent)

find_package(Git REQUIRED)

FetchContent_Declare(fakeit
        GIT_REPOSITORY https://github.com/eranpeer/FakeIt.git
        GIT_TAG 2.0.5
        PATCH_COMMAND ${GIT_EXECUTABLE} apply ${gram_SOURCE_DIR}/patch/fakeit.hpp.patch || true
        )

FetchContent_MakeAvailable(fakeit)

set(fakeit_INCLUDE_DIR "${fakeit_SOURCE_DIR}/single_header/catch/")
