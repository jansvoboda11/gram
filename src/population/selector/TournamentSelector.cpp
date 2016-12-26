#include <gram/population/selector/TournamentSelector.h>

using namespace gram;
using namespace std;

TournamentSelector::TournamentSelector(unique_ptr<NumberGenerator> generator) : generator(move(generator)) {
  //
}

shared_ptr<Individual> TournamentSelector::select(vector<shared_ptr<Individual>> individuals) {
  if (individuals.size() == 0) {
    throw logic_error("Cannot select an individual from an empty vector.");
  }

  if (individuals.size() == 1) {
    return individuals[0];
  }

  vector<shared_ptr<Individual>> preSelected;
  vector<unsigned long> preSelectedIds;

  for (int i = 0; i < individuals.size() / 2; i++) {
    unsigned long id = generator->generate() % individuals.size();

    if (find(preSelectedIds.begin(), preSelectedIds.end(), id) != preSelectedIds.end()) {
      i -= 1;
      continue;
    }

    preSelected.push_back(individuals[id]);
    preSelectedIds.push_back(id);
  }

  shared_ptr<Individual> best = preSelected[0];

  for (int i = 1; i < preSelected.size(); i++) {
    if (preSelected[i]->fitness() < best->fitness()) {
      best = preSelected[i];
    }
  }

  return best;
}
