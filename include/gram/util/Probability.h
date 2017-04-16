#ifndef GRAM_PROBABILITY
#define GRAM_PROBABILITY

namespace gram {
/**
 * Class.
 */
class Probability {
 public:
  Probability(double value);
  double getValue() const;
 private:
  double value;
};
}

#endif // GRAM_PROBABILITY
