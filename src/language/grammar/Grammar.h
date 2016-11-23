#ifndef GRAM_LANGUAGE_GRAMMAR_GRAMMAR
#define GRAM_LANGUAGE_GRAMMAR_GRAMMAR

#include "symbol/Symbol.h"

namespace gram {
namespace language {
namespace grammar {
/**
 * Class.
 */
class Grammar {
  std::unique_ptr<Symbol> getStartSymbol();
};
}
}
}

#endif // GRAM_LANGUAGE_GRAMMAR_GRAMMAR
