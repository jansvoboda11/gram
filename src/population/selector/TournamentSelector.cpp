#include <gram/population/selector/TournamentSelector.h>

#include <algorithm>

using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;

TournamentSelector::TournamentSelector(std::unique_ptr<NumberGenerator> generator) : generator(std::move(generator)) {
  //
}

std::shared_ptr<Individual> TournamentSelector::select(Population population) {
  if (population.size() == 0) {
    throw std::logic_error("Cannot select an individual from an empty population.");
  }

  if (population.size() == 1) {
    return population[0];
  }

  std::vector<std::shared_ptr<Individual>> preSelected;
  std::vector<long> preSelectedIds;

  for (int i = 0; i < population.size() / 2; i++) {
    long id = generator->generate() % population.size();

    if (std::find(preSelectedIds.begin(), preSelectedIds.end(), id) != preSelectedIds.end()) {
      i -= 1;
      continue;
    }

    preSelected.push_back(population[id]);
    preSelectedIds.push_back(id);
  }

  std::shared_ptr<Individual> best = preSelected[0];

  for (int i = 1; i < preSelected.size(); i++) {
    if (preSelected[i]->getFitness() < best->getFitness()) {
      best = preSelected[i];
    }
  }

  return best;
}
