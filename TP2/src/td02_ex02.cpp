#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
#include "ScopedTimer.hpp"

/**
 * Tri fusion
*/

// Étape de fusion
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    size_t const left_size { middle - left + 1 };
    size_t const right_size = { right - middle };
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index {0};
    size_t right_index {0};

    size_t index {left};

     // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] <= right_vec[right_index]) {
            vec[index] = left_vec[left_index];
            left_index ++;
        } else {
            vec[index] = right_vec[right_index];
            right_index ++;
        }
        index ++;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size) {
        vec[index] = left_vec[left_index];
        left_index ++;
        index ++;
    }
    while (right_index < right_size) {
        vec[index] = right_vec[right_index];
        right_index ++;
        index ++;
    }
}

// Étape de merge
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    size_t const middle = (left + right) / 2;
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);
    merge_sort_merge(vec, left, middle, right);
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}


int main()
{
    std::vector<float> array {7.5, 2.5, 1.5, 10.5, 9.5, 6.5};
    
    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    {
        // Calcul du temps d'exécution du tri fusion
        ScopedTimer timer("Temps tri fusion : ");
        merge_sort(array);   
    }

    display_array(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    return 0;
}