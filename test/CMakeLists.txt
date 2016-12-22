include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(fakeit
        PREFIX ${gram_SOURCE_DIR}/test/lib/fakeit
        GIT_REPOSITORY https://github.com/eranpeer/FakeIt
        GIT_TAG master
        UPDATE_COMMAND ${GIT_EXECUTABLE} pull
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )

include_directories(../src)

add_subdirectory(lib/googletest/googlemock)
add_subdirectory(unit)
add_subdirectory(acceptance)
