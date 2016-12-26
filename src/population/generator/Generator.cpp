#include <gram/population/generator/Generator.h>

using namespace gram;
using namespace std;

Generator::Generator(IndividualSelector &selector, Crossover &crossover, Mutation &mutation)
    : selector(selector), crossover(crossover), mutation(mutation) {
  //
}

vector<shared_ptr<Individual>> Generator::generateSuccessor(vector<shared_ptr<Individual>> individuals) const {
  vector<shared_ptr<Individual>> parents = selectParents(individuals);

  vector<shared_ptr<Individual>> children = createChildren(parents);

  mutateChildren(children);

  return children;
}

vector<shared_ptr<Individual>> Generator::selectParents(vector<shared_ptr<Individual>> individuals) const {
  vector<shared_ptr<Individual>> parents;

  unsigned long size = individuals.size();

  for (unsigned long i = 0; i < size; i++) {
    shared_ptr<Individual> parent = selector.select(individuals);

    parents.push_back(parent);
  }

  return parents;
}

vector<shared_ptr<Individual>> Generator::createChildren(vector<shared_ptr<Individual>> parents) const {
  vector<shared_ptr<Individual>> children;

  unsigned long size = parents.size();

  for (unsigned long i = 0; i < size; i += 2) {
    Individual firstParent = *parents[i];
    Individual secondParent = *parents[i + 1];

    Individual firstChild = firstParent.mateWith(secondParent, crossover);
    Individual secondChild = firstParent.mateWith(secondParent, crossover);

    children.push_back(make_shared<Individual>(firstChild));
    children.push_back(make_shared<Individual>(secondChild));
  }

  return children;
}

void Generator::mutateChildren(vector<shared_ptr<Individual>> children) const {
  for (auto &child : children) {
    child->mutate(mutation);
  }
}
