#include "IndexFunctions.hpp"
#include <iostream>
#include <vector>

void printVector(std::vector<unsigned char>& v){

    for (auto i : v){
        std::cout << "\t" << +i;
    }
    std::cout << std::endl;
}

int main(){
    std::vector<unsigned char> perm = {0, 1, 2};
    std::cout << IndexingFunctions::toCombinadicBase(perm) << "\n";
    size_t k = 7;
    size_t n_combs = IndexingFunctions::binomialCoef(16, k);

    for (size_t i = 0; i < n_combs; i++){
        std::vector<unsigned char> combination = IndexingFunctions::combinationFromRank(i, k);
        //std::cout << "Combination of rank " << i << ":";
        printVector(combination);
        //std::cout << "rank from this vector: " << IndexingFunctions::toCombinadicBase(combination) << std::endl; 
    }
    

    return 0;
}