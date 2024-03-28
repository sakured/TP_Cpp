#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

int main()
{
    std::vector<int> vec { generate_random_vector(20, 100) };
    std::vector<int>::iterator begin_iterator { vec.begin() };
    std::vector<int>::iterator end_iterator { vec.end() };

    // 1. Affichage du tableau d'entiers aléatoires
    for (auto it = begin_iterator; it != end_iterator; it++) {
        std::cout << *it << ", ";
    }
    
    // 2. Demande à l'utilisateur d'entrer un nombre
    int token {};
    std::cout << "Entrez un nombre :" << std::endl;
    std::cin >> token;

    // 3. Test si la valeur entrée est comprise dans le tableau
    if (end_iterator != find(vec.begin(), vec.end(), token)) {
        std::cout << "Votre valeur est dans le tableau" << std::endl;
    } else {
        std::cout << "Votre valeur n'est pas dans le tableau" << std::endl;
    }

    // 4. Retourne le nombre d'occurences de la valeur entrée
    std::cout << "Il y a " << count(vec.begin(), vec.end(), token) << " occurrences de cette valeur" << std::endl;
    
    // 5. Tri du tableau
    sort(vec.begin(), vec.end());

    // 6. Calcul de la somme des éléments
    std::cout << "La somme des éléments du tableau vaut " << accumulate(vec.begin(), vec.end(), 0) << std::endl;

    return 0;
}