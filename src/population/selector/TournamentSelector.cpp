#include <gram/population/selector/TournamentSelector.h>

using namespace gram;
using namespace std;

TournamentSelector::TournamentSelector(unique_ptr<NumberGenerator> numberGenerator)
    : numberGenerator(move(numberGenerator)) {
  //
}

Individual TournamentSelector::select(const Individuals& individuals) const {
  if (individuals.size() == 0) {
    throw logic_error("Cannot select an individual from an empty vector.");
  }

  if (individuals.size() == 1) {
    return individuals.at(0);
  }

  Individuals candidates;
  unsigned long count = max(individuals.size() / 50, static_cast<unsigned long>(1));

  for (unsigned long i = 0; i < count; i++) {
    unsigned long index = numberGenerator->generate() % individuals.size();
    Individual candidate = individuals.at(index);

    candidates.addIndividual(make_shared<Individual>(candidate));
  }

  return candidates.bestIndividual();
}
