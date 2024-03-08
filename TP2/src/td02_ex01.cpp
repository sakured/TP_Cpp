#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"

/**
 * Tri par sélection
*/
void selection_sort(std::vector<int> & vec) {
    if (vec.size() > 1) {
        for (int cursor=0; cursor<vec.size(); cursor++) {
            int min = vec[cursor];
            int min_i = cursor;
            for (int i=cursor; i<vec.size(); i++) {
                if (vec[i] < min) {
                    min = vec[i];
                    min_i = i;
                }
            }
            std::swap(vec[min_i], vec[cursor]);
        }
    }
}

int main()
{
    std::vector<int> array {8, 4, 5, 7, 2, 1, 10, 9, 6};

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    selection_sort(array);

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    return 0;
}