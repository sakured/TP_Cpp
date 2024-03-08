#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

/**
 * Tri fusion
*/

// Étape de fusion
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    
}

// Étape de merge
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    size_t const middle = (left + right) / 2;
    if (vec.size() > 1) {
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
    } else {
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}


int main()
{
    std::vector<float> array {8.5, 4.5, 5.5, 7.5, 2.5, 1.5, 10.5, 9.5, 6.5};

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    merge_sort(array);

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    return 0;
}