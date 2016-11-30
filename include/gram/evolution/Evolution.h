#ifndef GRAM_EVOLUTION_EVOLUTION
#define GRAM_EVOLUTION_EVOLUTION

#include <string>

#include <gram/individual/Individual.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Evolution {
 public:
  gram::individual::Individual run();
};
}
}

#endif // GRAM_EVOLUTION_EVOLUTION
