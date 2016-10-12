#include <gtest/gtest.h>

#include <Greeter.h>

TEST(greeter_test, test_it_greets) {
    gram::Greeter greeter;

    std::string greeting = greeter.getGreeting();

    ASSERT_EQ("Hello world!", greeting);
}
