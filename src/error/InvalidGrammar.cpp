#include "gram/error/InvalidGrammar.h"

using namespace gram;

InvalidGrammar::InvalidGrammar() : domain_error("Gram error: Grammar is not valid.") {
  //
}
