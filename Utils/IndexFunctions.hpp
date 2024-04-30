#ifndef INDEX_FUNCTIONS_HPP
#define INDEX_FUNCTIONS_HPP
#include <vector>
#include <cstdint>
#include <gmpxx.h>

namespace IndexingFunctions{

    std::size_t rank(const std::vector<unsigned char>& permutation);

    std::vector<unsigned char> unrank(std::size_t rank, std::size_t perm_size);

    std::vector<unsigned char> getInversion(std::vector<unsigned char> permutation);

    size_t toCombinadicBase(std::vector<unsigned char> combination);

    std::vector<unsigned char> combinationFromRank(size_t rank, size_t k);

    size_t binomialCoef(size_t n, size_t p);

    size_t factorial(size_t n); 

    std::vector<unsigned char> getDual (std::vector<unsigned char> perm);

}   

#endif