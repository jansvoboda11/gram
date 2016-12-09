#ifndef GRAM_EVOLUTION_OPERATOR_MUTATION
#define GRAM_EVOLUTION_OPERATOR_MUTATION

#include <gram/individual/Genotype.h>
#include <gram/util/BoolGenerator.h>
#include <gram/util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Mutation {
 public:
  Mutation(gram::util::BoolGenerator &boolGenerator, gram::util::NumberGenerator &numberGenerator);
  gram::individual::Genotype apply(gram::individual::Genotype genotype);
 private:
  gram::util::BoolGenerator &boolGenerator;
  gram::util::NumberGenerator &numberGenerator;
};
}
}

#endif // GRAM_EVOLUTION_OPERATOR_MUTATION
