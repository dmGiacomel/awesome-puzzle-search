#include <iostream>
#include <vector>
#include <string>

int fact (unsigned n){
    return (n == 0 || n == 1) ? 1 : n * fact(n - 1);
}

size_t rank (size_t perm_size, std::vector<unsigned char>& perm, std::vector<unsigned char>& inv){

    if (perm_size == 1){
        return 0;
    }
    size_t current_index = perm_size - 1;
    unsigned char aux = perm[current_index];

    std::swap(perm[current_index], perm[inv[current_index]]);
    std::swap(inv[aux], inv[current_index]);
    return (aux + perm_size * rank(--perm_size, perm, inv));
}

void unrank (size_t perm_size, size_t rank, std::vector<unsigned char>& id){

    if (perm_size > 0){
        std::swap(id[perm_size - 1], id[rank % perm_size]);
        unrank(--perm_size, rank/perm_size, id);
    }
}


std::vector<unsigned char> getDual (std::vector<unsigned char> perm){
    size_t perm_size = perm.size();
    std::vector<unsigned char> dual(perm_size);

    for (size_t i = 0; i < perm_size; i++){
        dual[perm[i]] = i;
    }

    return dual;
}

void printVector (std::vector<unsigned char> v){

    for (auto i : v){
        std::cout << +i << "\t"; 
    }
    std::cout << std::endl;
}

int main(int argc, char **argv){

    size_t r = std::atoi(argv[1]);
    std::vector<unsigned char> id({0, 1, 2, 3});

    std::cout << "rank: " << r << "\n";
    unrank(id.size(), r, id);

    std::cout << "corresponding permutation: " << "\n"; 
    printVector(id);

    std::vector<unsigned char> dual = getDual(id);
    std::cout << "ranking the permutation (should be the same initial value): " << rank(id.size(), id, dual) << "\n";
    return 0;
}