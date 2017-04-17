#ifndef GRAM_TEST_STRING_DIFF_EVALUATOR
#define GRAM_TEST_STRING_DIFF_EVALUATOR

#include <memory>
#include <string>

#include "gram/evaluation/Evaluator.h"
#include "gram/individual/Genotype.h"
#include "gram/language/mapper/ContextFreeMapper.h"

class StringDiffEvaluator : public gram::Evaluator {
 public:
  StringDiffEvaluator(std::shared_ptr<gram::ContextFreeMapper> mapper, std::string desired);
  double evaluate(const gram::Genotype& genotype) noexcept;
  double calculateFitness(std::string program);
 private:
  std::shared_ptr<gram::ContextFreeMapper> mapper;
  std::string desired;
};

#endif // GRAM_TEST_STRING_DIFF_EVALUATOR
