#include <gram/individual/Phenotype.h>

using namespace gram::language;
using namespace gram::individual;

void Phenotype::addTerminal(Terminal terminal) {
  terminals.push_back(terminal);
}

std::string Phenotype::serialize() {
  if (terminals.empty()) {
    return "";
  }

  std::string serialized;

  for (auto &terminal : terminals) {
    serialized += terminal.value();
  }

  return serialized;
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
