#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
#include "ScopedTimer.hpp"


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
    // std::vector<int> array {8, 4, 5, 7, 2, 1, 10, 9, 6};
    // std::vector<int> array {generate_random_vector(50, 50)};
    std::vector<int> array { 41, 17, 34, 0, 19, 24, 28, 8, 12, 14, 5, 45, 31, 27, 11, 41, 45, 42, 27, 36, 41, 4, 2, 3, 42, 32, 21, 16, 18, 45, 47, 26, 21, 38, 19, 12, 17, 49, 35, 44, 3, 11, 22, 33, 23, 14, 41, 11, 3, 18 };


    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    {
        // Calcul du temps d'exécution du tri par sélection
        ScopedTimer timer("Temps tri par selection : ");
        selection_sort(array);   
    }

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    return 0;
}