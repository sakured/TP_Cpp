#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
#include "ScopedTimer.hpp"

int search (std::vector<int> const & vec, int const value) {
    int left = 0;
    int right = vec.size() -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        // std::cout << middle << std::endl;
        if (vec[middle] == value) {
            return middle;
        } else if (vec[middle] < value) {
            left = middle + 1;
        } else if (vec[middle] > value) {
            right = middle - 1;
        }
    }
    return -1;
}


int main()
{
    std::vector<int> const array {1, 2, 2, 3, 4, 8, 12};
    // std::vector<int> const array {1, 2, 3, 3, 6, 14, 12, 15};
    // std::vector<int> const array {2, 2, 3, 4, 5, 8, 12, 15, 16};
    // std::vector<int> const array {5, 6, 7, 8, 9, 10, 11, 12, 13};
    // std::vector<int> const array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // std::vector<int> const array {0, 2, 3, 3, 3, 4, 5, 8, 11, 11, 11, 12, 12, 14, 14, 16, 17, 17, 18, 18, 19, 19, 21, 21, 22, 23, 24, 26, 27, 27, 28, 31, 32, 33, 34, 35, 36, 38, 41, 41, 41, 41, 42, 42, 44, 45, 45, 45, 47, 49};

    int result = search(array, 8);

    if (result == -1) {
        std::cout << "La valeur recherchee n'est pas presente dans le tableau." << std::endl;
    } else {
        std::cout << "La valeur recherchee est a l'indice " << result << std::endl;
    }

    return 0;
}