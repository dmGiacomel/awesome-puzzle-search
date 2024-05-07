#include "IndexFunctions.hpp"
#include <iostream>
#include <vector>

void printVector(const std::vector<unsigned char>& v){

    for (auto i : v){
        std::cout << "\t" << +i;
    }
    std::cout << std::endl;
}

int main(){

    std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({0, 1, 2})) << "\n";
    std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({0, 1, 3})) << "\n";
    std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({0, 2, 3})) << "\n";
    std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({1, 2, 3})) << "\n";
    std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({2, 3, 4})) << "\n";
    
    //std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({11, 10, 9, 8, 7, 6, 5})) << "\n";
    //std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({5, 6, 7, 8, 9, 10, 11})) << "\n";
    //std::cout << IndexingFunctions::toCombinadicBase(std::vector<size_t> ({0 ,1 ,2 ,3 ,4 ,5 ,6 })) << "\n";

    //printVector(IndexingFunctions::combinationFromRank(791, 7));

    //printVector(IndexingFunctions::combinationFromRank(0, 7));

    return 0;
}