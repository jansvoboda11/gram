#include <gram/evolution/selector/IndividualSelector.h>

using namespace gram::evolution;
using namespace gram::population;
using namespace gram::util;

IndividualSelector::IndividualSelector(Population population, NumberGenerator &generator)
    : population(population), generator(generator) {
  //
}
