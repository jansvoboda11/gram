add_executable(atest
        StringDiffEvaluator.cpp
        StringDiffEvaluator.h
        evolution_test.cpp
        test.cpp
        )

target_include_directories(atest PRIVATE
        ${gram_SOURCE_DIR}/include
        ${catch_INCLUDE_DIR}
        ${fakeit_INCLUDE_DIR}
        )

target_link_libraries(atest gram)
