#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <gram/population/generator/Generator.h>
#include <gram/population/initializer/Initializer.h>
#include <gram/population/processor/Processor.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Evolution {
 public:
  gram::individual::Individual run(int populationSize, int iterationCount);
  void setInitializer(gram::population::Initializer *newInitializer);
  void setProcessor(gram::population::Processor *newProcessor);
  void setGenerator(gram::population::Generator *newGenerator);
 private:
  gram::population::Initializer *initializer;
  gram::population::Processor *processor;
  gram::population::Generator *generator;
};
}
}

#endif // GRAM_EVOLUTION_EVOLUTION
