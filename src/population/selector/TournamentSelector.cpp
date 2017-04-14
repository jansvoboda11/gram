#include <gram/population/selector/TournamentSelector.h>

using namespace gram;
using namespace std;

TournamentSelector::TournamentSelector(unsigned long tournamentSize, unique_ptr<NumberGenerator> numberGenerator)
    : tournamentSize(tournamentSize), numberGenerator(move(numberGenerator)) {
  //
}

Individual& TournamentSelector::select(Individuals& individuals) {
  if (individuals.size() == 0) {
    throw logic_error("Cannot select an individual from an empty vector.");
  }

  if (individuals.size() == 1) {
    return individuals[0];
  }

  vector<Individual*> candidates;
  candidates.reserve(tournamentSize);

  for (unsigned long i = 0; i < tournamentSize; i++) {
    unsigned long index = numberGenerator->generate() % individuals.size();
    candidates.push_back(&individuals[index]);
  }

  unsigned long bestIndex = 0;

  for (unsigned long i = 0; i < candidates.size(); i++) {
    if (candidates[i]->getFitness() < candidates[bestIndex]->getFitness()) {
      bestIndex = i;
    }
  }

  return *candidates[bestIndex];
}
