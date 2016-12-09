#include <gram/population/generator/Generator.h>

using namespace gram::evolution;
using namespace gram::population;
using namespace gram::individual;

Generator::Generator(IndividualSelector &selector, Crossover &crossover, Mutation &mutation)
    : selector(selector), crossover(crossover), mutation(mutation) {
  //
}

Population Generator::generateSuccessor(Population &population) {
  std::vector<Individual> parents = selectParents(population);

  std::vector<Individual> children = createChildren(parents);

  mutateChildren(children);

  return Population(children);
}

std::vector<Individual> Generator::selectParents(Population &oldPopulation) {
  std::vector<Individual> parents;

  unsigned long size = oldPopulation.size();

  for (unsigned long i = 0; i < size; i++) {
    Individual parent = selector.select(oldPopulation);

    parents.push_back(parent);
  }

  return parents;
}

std::vector<Individual> Generator::createChildren(std::vector<Individual> parents) {
  std::vector<Individual> children;

  unsigned long size = parents.size();

  for (unsigned long i = 0; i < size; i++) {
    Individual &firstParent = parents[i];
    Individual &secondParent = parents[i + 1];

    Genotype firstGenotype = crossover.apply(firstParent.getGenotype(), secondParent.getGenotype());
    Genotype secondGenotype = crossover.apply(secondParent.getGenotype(), firstParent.getGenotype());

    Individual firstChild(firstGenotype);
    Individual secondChild(secondGenotype);

    children.push_back(firstChild);
    children.push_back(secondChild);
  }

  return children;
}

void Generator::mutateChildren(std::vector<gram::individual::Individual> &children) {
  for (auto &child : children) {
    Genotype oldGenotype = child.getGenotype();
    Genotype mutatedGenotype = mutation.apply(oldGenotype);

    child.setGenotype(mutatedGenotype);
  }
}
