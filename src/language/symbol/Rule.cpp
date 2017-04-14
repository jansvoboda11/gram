#include <gram/language/symbol/Rule.h>

using namespace gram;
using namespace std;

Rule::Rule(string name) : name(name) {
  //
}

string Rule::getName() const {
  return name;
}

void Rule::addOption(unique_ptr<Option> option) {
  options.push_back(move(option));
}

Option& Rule::optionAt(unsigned long index) const {
  return *options[index];
}

unsigned long Rule::size() const {
  return options.size();
}

bool Rule::operator==(const Rule& rule) const {
  if (name != rule.name) {
    return false;
  }

  if (options.size() != rule.options.size()) {
    return false;
  }

  for (unsigned long i = 0; i < options.size(); i++) {
    if (*options[i] != *rule.options[i]) {
      return false;
    }
  }

  return true;
}

bool Rule::operator!=(const Rule& rule) const {
  return !operator==(rule);
}
