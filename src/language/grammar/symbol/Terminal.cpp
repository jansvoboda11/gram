#include <language/grammar/symbol/Terminal.h>

using namespace gram::language::grammar;

Terminal::Terminal(std::string value) : value(value) {
  //
}

std::string Terminal::getValue() {
  return value;
}

bool Terminal::operator==(const Terminal &terminal) const {
  return value == terminal.value;
}

bool Terminal::operator!=(const Terminal &terminal) const {
  return !operator==(terminal);
}
