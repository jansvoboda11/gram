#ifndef GRAM_LANGUAGE_GRAMMAR_TERMINAL
#define GRAM_LANGUAGE_GRAMMAR_TERMINAL

#include <string>

namespace gram {
namespace language {
namespace grammar {
/**
 * Class.
 */
class Terminal {
 public:
  Terminal(std::string value);
  std::string getValue();
  bool operator==(const Terminal &terminal) const;
  bool operator!=(const Terminal &terminal) const;
 private:
  std::string value;
};
}
}
}

#endif // GRAM_LANGUAGE_GRAMMAR_TERMINAL
