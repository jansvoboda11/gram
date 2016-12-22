#include <gram/population/selector/TournamentSelector.h>

#include <algorithm>

using namespace gram::individual;
using namespace gram::population;
using namespace gram::util;

TournamentSelector::TournamentSelector(std::unique_ptr<NumberGenerator> generator) : generator(std::move(generator)) {
  //
}

std::shared_ptr<Individual> TournamentSelector::select(std::vector<std::shared_ptr<Individual>> individuals) {
  if (individuals.size() == 0) {
    throw std::logic_error("Cannot select an individual from an empty vector.");
  }

  if (individuals.size() == 1) {
    return individuals[0];
  }

  std::vector<std::shared_ptr<Individual>> preSelected;
  std::vector<unsigned long> preSelectedIds;

  for (int i = 0; i < individuals.size() / 2; i++) {
    unsigned long id = generator->generate() % individuals.size();

    if (std::find(preSelectedIds.begin(), preSelectedIds.end(), id) != preSelectedIds.end()) {
      i -= 1;
      continue;
    }

    preSelected.push_back(individuals[id]);
    preSelectedIds.push_back(id);
  }

  std::shared_ptr<Individual> best = preSelected[0];

  for (int i = 1; i < preSelected.size(); i++) {
    if (preSelected[i]->fitness() < best->fitness()) {
      best = preSelected[i];
    }
  }

  return best;
}
