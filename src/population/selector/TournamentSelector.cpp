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
    return individuals[0];
  }

  unsigned long count = max(individuals.size() / 50, 1UL);

  Individuals candidates;
  candidates.reserve(count);

  for (unsigned long i = 0; i < count; i++) {
    unsigned long index = numberGenerator->generate() % individuals.size();
    Individual candidate = individuals[index];

    candidates.addIndividual(make_shared<Individual>(candidate));
  }

  return candidates.bestIndividual();
}
