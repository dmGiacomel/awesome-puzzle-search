#ifndef INDEX_FUNCTIONS_CPP
#define INDEX_FUNCTIONS_CPP
#include "IndexFunctions.hpp"
#include <numeric>
#include <iostream>
#include <gmpxx.h>

size_t IndexingFunctions::factorial(size_t n) {
    size_t result = 1;
    for (size_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

//co-lex order
//só deus sabe como isso funciona, mas isso funciona 
//https://computationalcombinatorics.wordpress.com/2012/09/10/ranking-and-unranking-of-combinations-and-permutations/

size_t IndexingFunctions::toCombinadicBase(std::vector<unsigned char> permutation){
    size_t result = 0;
    size_t k = permutation.size();
    
    for (size_t i = 0; i < k; i++){
        result += binomialCoef(permutation[i], i + 1);
    }

    return result;
}

//só deus sabe como isso funciona, mas isso funciona 
//https://computationalcombinatorics.wordpress.com/2012/09/10/ranking-and-unranking-of-combinations-and-permutations/
std::vector<unsigned char> IndexingFunctions::combinationFromRank(size_t m, size_t k){
    std::vector<unsigned char> s(k);
    std::iota(s.begin(), s.end(), 0);

    long long int i = k - 1;

    while(i >= 0){
        long long int l = i;
        //std::cout << "l: " << l << "\ti + 1: " << i + 1 << "\n";
        while (binomialCoef(l, i + 1) <= m){
            l++;
        }
        s[i] = l - 1;
        m -= binomialCoef(l - 1, i + 1);
        i--;
    }

    return s;
}

size_t IndexingFunctions::binomialCoef(size_t n, size_t k){
    size_t p = std::min(k, n - k);
    size_t res = 1;
    for (size_t i = 0; i < p; i++){
        res *= (n - i);
        res /= i + 1;
    }
    return res;
}

std::vector<unsigned char> IndexingFunctions::getDual (std::vector<unsigned char> perm){
    size_t perm_size = perm.size();
    std::vector<unsigned char> dual(perm_size);

    for (size_t i = 0; i < perm_size; i++){
        dual[perm[i]] = i;
    }

    return std::move(dual);
}

size_t raw_rank (size_t perm_size, std::vector<unsigned char>& perm, std::vector<unsigned char>& inv){

    if (perm_size == 1){
        return 0;
    }
    size_t current_index = perm_size - 1;
    unsigned char aux = perm[current_index];

    std::swap(perm[current_index], perm[inv[current_index]]);
    std::swap(inv[aux], inv[current_index]);
    return (aux + perm_size * raw_rank(perm_size - 1, perm, inv));
}

size_t IndexingFunctions::rank(const std::vector<unsigned char>& perm){

    std::vector<unsigned char> perm_copy(perm);
    std::vector<unsigned char> inv = getDual(perm);

    return raw_rank(size(perm), perm_copy, inv);
}

void unrank_raw (size_t perm_size, size_t rank, std::vector<unsigned char>& id){

    if (perm_size > 0){
        std::swap(id[perm_size - 1], id[rank % perm_size]);
        unrank_raw(perm_size - 1, rank/perm_size, id);
    }
}

std::vector<unsigned char> IndexingFunctions::unrank(size_t rank, size_t perm_size){
    std::vector<unsigned char> id(perm_size);
    std::iota(id.begin(), id.end(), 0 );
    unrank_raw(perm_size, rank, id);
    return std::move(id);
}

// std::vector<unsigned char> IndexingFunctions::getInversion(const std::vector<unsigned char>& permutation){
//     size_t k{permutation.size()};
//     std::vector<unsigned char> inversion_vector(k);

//     mpz_class m;
//     mpz_ui_pow_ui(m.get_mpz_t(), 2, k);
//     m = (mpz_class(1) << k) - mpz_class(1); 

//     for (size_t i = 0; i < k; i++){

//         mpz_class bitmask = mpz_class(1) << permutation[i]; 
//         mpz_class popcount = (mpz_popcount(m.get_mpz_t())) & bitmask - mpz_class(1); 
//         inversion_vector[i] = static_cast<unsigned char>(popcount.get_ui());

//         m &= ~(bitmask);
//     }
    
//     return inversion_vector;
// }
#endif