include(FetchContent)

FetchContent_Declare(catch
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.4
        )

FetchContent_MakeAvailable(catch)

set(catch_INCLUDE_DIR "${catch_SOURCE_DIR}/single_include/catch2/")
