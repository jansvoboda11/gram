#ifndef GRAM_INDIVIDUAL_MAPPER_MOCK
#define GRAM_INDIVIDUAL_MAPPER_MOCK

#include <gmock/gmock.h>

#include <gram/individual/Mapper.h>

namespace gram {
namespace individual {
/**
 * Mock.
 */
class MapperMock : public Mapper {
 public:
  MapperMock(gram::grammar::Grammar grammar) : Mapper(grammar) {};
  MOCK_METHOD1(map, Phenotype(Genotype));
};
}
}

#endif // GRAM_INDIVIDUAL_MAPPER_MOCK
