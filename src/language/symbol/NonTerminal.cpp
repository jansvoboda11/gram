#include <gram/language/symbol/NonTerminal.h>

using namespace gram;
using namespace std;

void NonTerminal::addOption(shared_ptr<Option> option) {
  options.push_back(option);
}

Option& NonTerminal::optionAt(unsigned long index) const {
  return *options.at(index);
}

unsigned long NonTerminal::size() const {
  return options.size();
}

bool NonTerminal::operator==(const NonTerminal& nonTerminal) const {
  if (size() != nonTerminal.size()) {
    return false;
  }

  for (unsigned long i = 0; i < size(); i++) {
    if (options.at(i) != nonTerminal.options.at(i)) {
      return false;
    }
  }

  return true;
}

bool NonTerminal::operator!=(const NonTerminal& nonTerminal) const {
  return !operator==(nonTerminal);
}
