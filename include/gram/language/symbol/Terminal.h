#ifndef GRAM_LANGUAGE_TERMINAL_SYMBOL
#define GRAM_LANGUAGE_TERMINAL_SYMBOL

#include <string>

namespace gram {
/**
 * Class.
 */
class Terminal {
 public:
  Terminal(std::string value);
  std::string value() const;
  bool operator==(const Terminal &terminal) const;
  bool operator!=(const Terminal &terminal) const;
 private:
  std::string val;
};
}

#endif // GRAM_LANGUAGE_TERMINAL_SYMBOL
