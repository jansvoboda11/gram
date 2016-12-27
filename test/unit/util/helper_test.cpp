#include <gtest/gtest.h>

#include <gram/util/helper.h>

using namespace gram;
using namespace std;

TEST(helper_test, test_it_splits_string_containing_delimiter) {
  vector<string> pieces = explode("hello world, she said", " ");

  ASSERT_EQ(4, pieces.size());
  ASSERT_EQ("hello", pieces[0]);
  ASSERT_EQ("world,", pieces[1]);
  ASSERT_EQ("she", pieces[2]);
  ASSERT_EQ("said", pieces[3]);
}

TEST(helper_test, test_it_does_not_split_string_without_delimiter) {
  vector<string> pieces = explode("hello world", "x");

  ASSERT_EQ(1, pieces.size());
  ASSERT_EQ("hello world", pieces[0]);
}

TEST(helper_test, test_it_handles_multiple_delimiters_in_row) {
  vector<string> pieces = explode("hello world", "l");

  ASSERT_EQ(4, pieces.size());
  ASSERT_EQ("he", pieces[0]);
  ASSERT_EQ("", pieces[1]);
  ASSERT_EQ("o wor", pieces[2]);
  ASSERT_EQ("d", pieces[3]);
}

TEST(helper_test, test_it_trims_whitespace_on_the_left) {
  string trimmed = left_trim(" \n hello world ");

  ASSERT_EQ("hello world ", trimmed);
}

TEST(helper_test, test_it_does_not_trim_when_no_whitespace_on_the_left) {
  string trimmed = left_trim("hello world");

  ASSERT_EQ("hello world", trimmed);
}

TEST(helper_test, test_left_trim_handles_empty_string) {
  string trimmed = left_trim("");

  ASSERT_EQ("", trimmed);
}
