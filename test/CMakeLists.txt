include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(catch
        PREFIX ${gram_SOURCE_DIR}/test/lib/catch
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG master
        UPDATE_COMMAND ${GIT_EXECUTABLE} pull
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )

ExternalProject_Add(fakeit
        PREFIX ${gram_SOURCE_DIR}/test/lib/fakeit
        GIT_REPOSITORY https://github.com/eranpeer/FakeIt
        GIT_TAG master
        UPDATE_COMMAND ${GIT_EXECUTABLE} pull
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )

add_subdirectory(acceptance)
add_subdirectory(unit)
