#include <gram/population/generator/Generator.h>

using namespace gram::evolution;
using namespace gram::population;
using namespace gram::individual;

Generator::Generator(IndividualSelector &selector, Crossover &crossover, Mutation &mutation)
    : selector(selector), crossover(crossover), mutation(mutation) {
  //
}

Population Generator::generateSuccessor(Population &population) {
  std::vector<std::shared_ptr<Individual>> parents = selectParents(population);

  std::vector<std::shared_ptr<Individual>> children = createChildren(parents);

  mutateChildren(children);

  return Population(children);
}

std::vector<std::shared_ptr<Individual>> Generator::selectParents(Population &oldPopulation) {
  std::vector<std::shared_ptr<Individual>> parents;

  unsigned long size = oldPopulation.size();

  for (unsigned long i = 0; i < size; i++) {
    std::shared_ptr<Individual> parent = selector.select(oldPopulation);

    parents.push_back(parent);
  }

  return parents;
}

std::vector<std::shared_ptr<Individual>> Generator::createChildren(std::vector<std::shared_ptr<Individual>> parents) {
  std::vector<std::shared_ptr<Individual>> children;

  unsigned long size = parents.size();

  for (unsigned long i = 0; i < size; i += 2) {
    std::shared_ptr<Individual> firstParent = parents[i];
    std::shared_ptr<Individual> secondParent = parents[i + 1];

    auto firstChild = firstParent->mateWith(secondParent, crossover);
    auto secondChild = firstParent->mateWith(secondParent, crossover);

    children.push_back(firstChild);
    children.push_back(secondChild);
  }

  return children;
}

void Generator::mutateChildren(std::vector<std::shared_ptr<Individual>> children) {
  for (auto &child : children) {
    Genotype oldGenotype = child->getGenotype();
    Genotype mutatedGenotype = mutation.apply(oldGenotype);

    child->setGenotype(mutatedGenotype);
  }
}
