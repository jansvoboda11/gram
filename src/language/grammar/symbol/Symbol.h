#ifndef GRAM_LANGUAGE_GRAMMAR_SYMBOL
#define GRAM_LANGUAGE_GRAMMAR_SYMBOL

#include <memory>

namespace gram {
namespace language {
namespace grammar {
/**
 * Class.
 */
class Symbol {
 public:
  virtual std::unique_ptr<Symbol> expand(int possibilityNumber) = 0;
};
}
}
}

#endif // GRAM_LANGUAGE_GRAMMAR_SYMBOL
