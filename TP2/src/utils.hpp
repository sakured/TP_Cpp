#pragma once
#include <vector>
#include <cstdlib>
#include <algorithm>

/**
 * Savoir si un tableau d'entiers est trié
*/
bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

/**
 * Savoir si un tableau de flottants est trié
*/
bool is_sorted(std::vector<float> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

/**
 * Afficher un tableau d'entiers
*/
void display_array(std::vector<int> const& vec) {
    std::cout << "{ ";
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "}" << std::endl;
}

/**
 * Afficher un tableau de flottants
*/
void display_array(std::vector<float> const& vec) {
    std::cout << "{ ";
    for (int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << "}" << std::endl;
}

/**
 * Générer un tableau d'entiers aléatoires
*/
std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}