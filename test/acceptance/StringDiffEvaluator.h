#ifndef GRAM_TEST_STRING_DIFF_EVALUATOR
#define GRAM_TEST_STRING_DIFF_EVALUATOR

#include <memory>
#include <string>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/mapper/ContextFreeMapper.h"

class StringDiffEvaluator : public gram::Evaluator {
public:
  StringDiffEvaluator(std::string desired);
  double evaluate(const gram::Phenotype& phenotype) noexcept;
  double calculateFitness(std::string program);

private:
  std::string desired;
};

#endif // GRAM_TEST_STRING_DIFF_EVALUATOR
