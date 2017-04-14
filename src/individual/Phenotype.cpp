#include <gram/individual/Phenotype.h>

using namespace gram;
using namespace std;

Phenotype::Phenotype() {
  terminals.reserve(128);
}

void Phenotype::addTerminal(std::shared_ptr<Terminal> terminal) {
  terminals.push_back(terminal);
}

string Phenotype::serialize() const {
  string serialized;

  for (auto& terminal : terminals) {
    serialized += terminal->getValue();
  }

  return serialized;
}

bool Phenotype::operator==(const Phenotype& phenotype) const {
  if (terminals.size() != phenotype.terminals.size()) {
    return false;
  }

  for (int i = 0; i < terminals.size(); i++) {
    if (*terminals[i] != *phenotype.terminals[i]) {
      return false;
    }
  }

  return true;
}

bool Phenotype::operator!=(const Phenotype& phenotype) const {
  return !operator==(phenotype);
}
