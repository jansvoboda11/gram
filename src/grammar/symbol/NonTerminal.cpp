#include <gram/grammar/symbol/NonTerminal.h>

using namespace gram::grammar;

void NonTerminal::addOption(std::weak_ptr<Option> option) {
  options.push_back(option);
}

std::shared_ptr<Option> NonTerminal::optionAt(unsigned long index) {
  return options[index].lock();
}

unsigned long NonTerminal::optionCount() {
  return options.size();
}

bool NonTerminal::operator==(const NonTerminal &nonTerminal) const {
  if (options.size() != nonTerminal.options.size()) {
    return false;
  }

  size_t size = options.size();

  for (int i = 0; i < size; i++) {
    std::shared_ptr<Option> firstOption = options[i].lock();
    std::shared_ptr<Option> secondOption = nonTerminal.options[i].lock();

    if (*firstOption != *secondOption) {
      return false;
    }
  }

  return true;
}

bool NonTerminal::operator!=(const NonTerminal &nonTerminal) const {
  return !operator==(nonTerminal);
}
