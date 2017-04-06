#include <gram/population/selector/TournamentSelector.h>

using namespace gram;
using namespace std;

TournamentSelector::TournamentSelector(unsigned long tournamentSize, unique_ptr<NumberGenerator> numberGenerator)
    : tournamentSize(tournamentSize), numberGenerator(move(numberGenerator)) {
  //
}

Individual TournamentSelector::select(const Individuals& individuals) const {
  if (individuals.size() == 0) {
    throw logic_error("Cannot select an individual from an empty vector.");
  }

  if (individuals.size() == 1) {
    return individuals[0];
  }

  Individuals candidates;
  candidates.reserve(tournamentSize);

  for (unsigned long i = 0; i < tournamentSize; i++) {
    unsigned long index = numberGenerator->generate() % individuals.size();
    Individual candidate = individuals[index];

    candidates.addIndividual(make_shared<Individual>(candidate));
  }

  return candidates.bestIndividual();
}
