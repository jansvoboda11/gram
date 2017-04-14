#include <gram/language/symbol/Symbol.h>

#include <gram/language/symbol/NonTerminal.h>
#include <gram/language/symbol/Terminal.h>

using namespace gram;

Terminal& Symbol::toTerminal() {
  return dynamic_cast<Terminal&>(*this);
}

NonTerminal& Symbol::toNonTerminal() {
  return dynamic_cast<NonTerminal&>(*this);
}
