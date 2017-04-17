#include "gram/language/symbol/Rule.h"

#include <algorithm>
#include <memory>

#include "gram/error/InvalidGrammar.h"
#include "gram/language/symbol/Option.h"

using namespace gram;
using namespace std;

Rule::Rule(string name) : name(name) {
  if (name.length() == 0) {
    throw InvalidGrammar();
  }

  //
}

string Rule::getName() const {
  return name;
}

void Rule::addOption(unique_ptr<Option> option) {
  options.push_back(move(option));
}

Option& Rule::operator[](unsigned long index) const {
  return *options[index];
}

unsigned long Rule::size() const {
  return options.size();
}
