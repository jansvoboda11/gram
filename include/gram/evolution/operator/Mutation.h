#ifndef GRAM_EVOLUTION_OPERATOR_MUTATION
#define GRAM_EVOLUTION_OPERATOR_MUTATION

#include <gram/individual/Genotype.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Mutation {
 public:
  Mutation(gram::util::NumberGenerator &generator);
  gram::individual::Genotype apply(gram::individual::Genotype genotype);
 private:
  gram::util::NumberGenerator &generator;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR_MUTATION
