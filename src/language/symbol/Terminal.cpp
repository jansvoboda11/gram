#include <gram/language/symbol/Terminal.h>

using namespace gram;
using namespace std;

Terminal::Terminal(string value) : val(value) {
  //
}

string Terminal::value() const {
  return val;
}

bool Terminal::operator==(const Terminal &terminal) const {
  return val == terminal.val;
}

bool Terminal::operator!=(const Terminal &terminal) const {
  return !operator==(terminal);
}
