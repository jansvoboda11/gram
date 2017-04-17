#include "gram/population/selector/TournamentSelector.h"

#include <algorithm>
#include <vector>

#include "gram/error/NoIndividuals.h"
#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"
#include "gram/population/Individuals.h"
#include "gram/random/number_generator/NumberGenerator.h"

using namespace gram;
using namespace std;

TournamentSelector::TournamentSelector(unsigned long tournamentSize,
                                       unique_ptr<NumberGenerator> numberGenerator,
                                       unique_ptr<IndividualComparer> comparer)
    : tournamentSize(tournamentSize), numberGenerator(move(numberGenerator)), comparer(move(comparer)) {
  if (tournamentSize == 0) {
    throw NoIndividuals();
  }
}

Individual& TournamentSelector::select(Individuals& individuals) {
  if (individuals.empty()) {
    throw NoIndividuals();
  }

  vector<Individual*> candidates;
  candidates.reserve(tournamentSize);

  for (unsigned long i = 0; i < tournamentSize; i++) {
    unsigned long index = numberGenerator->generate() % individuals.size();
    candidates.push_back(&individuals[index]);
  }

  unsigned long bestIndex = 0;

  for (unsigned long i = 0; i < candidates.size(); i++) {
    if (comparer->isFirstFitter(*candidates[i], *candidates[bestIndex])) {
      bestIndex = i;
    }
  }

  return *candidates[bestIndex];
}
