#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <memory>

#include <gram/individual/processor/Processor.h>
#include <gram/population/Population.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Evolution {
 public:
  Evolution(std::shared_ptr<gram::individual::Processor> processor);
  gram::individual::Individual run(gram::population::Population &population, int goal);
 private:
  std::shared_ptr<gram::individual::Processor> processor;
};
}
}

#endif // GRAM_EVOLUTION_EVOLUTION
