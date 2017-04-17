#include "gram/language/symbol/Terminal.h"

using namespace gram;
using namespace std;

Terminal::Terminal(string value) : value(value) {
  //
}

string Terminal::getValue() const {
  return value;
}

bool Terminal::isTerminal() const {
  return true;
}

bool Terminal::isNonTerminal() const {
  return false;
}

bool Terminal::operator==(const Terminal& terminal) const {
  return value == terminal.value;
}

bool Terminal::operator!=(const Terminal& terminal) const {
  return !operator==(terminal);
}
