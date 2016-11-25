#include <population/individual/Phenotype.h>

using namespace gram::language::grammar;
using namespace gram::population::individual;

void Phenotype::addTerminal(Terminal terminal) {
  terminals.push_back(terminal);
}

Terminal Phenotype::terminalAt(int index) {
  return terminals[index];
}

std::string Phenotype::serialize() {
  if (terminals.empty()) {
    return "";
  }

  std::string serialized;

  for (auto &terminal : terminals) {
    serialized += terminal.getValue() + " ";
  }

  return serialized.substr(0, serialized.length() - 1);
}

bool Phenotype::operator==(const Phenotype &phenotype) const {
  if (terminals.size() != phenotype.terminals.size()) {
    return false;
  }

  for (int i = 0; i < terminals.size(); i++) {
    if (terminals[i] != phenotype.terminals[i]) {
      return false;
    }
  }

  return true;
}

bool Phenotype::operator!=(const Phenotype &phenotype) const {
  return !operator==(phenotype);
}
