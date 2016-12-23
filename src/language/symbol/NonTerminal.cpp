#include <gram/language/symbol/NonTerminal.h>

using namespace gram::language;

void NonTerminal::addOption(std::shared_ptr<Option> option) {
  options.push_back(option);
}

std::shared_ptr<Option> NonTerminal::optionAt(unsigned long index) {
  return options[index];
}

unsigned long NonTerminal::size() const {
  return options.size();
}

bool NonTerminal::operator==(const NonTerminal &nonTerminal) const {
  if (size() != nonTerminal.size()) {
    return false;
  }

  for (int i = 0; i < size(); i++) {
    std::shared_ptr<Option> firstOption = options[i];
    std::shared_ptr<Option> secondOption = nonTerminal.options[i];

    if (*firstOption != *secondOption) {
      return false;
    }
  }

  return true;
}

bool NonTerminal::operator!=(const NonTerminal &nonTerminal) const {
  return !operator==(nonTerminal);
}
