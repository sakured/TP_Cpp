#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.hpp"
#include "ScopedTimer.hpp"


int main()
{
    // std::vector<int> array {8, 4, 5, 7, 2, 1, 10, 9, 6};
    // std::vector<int> array {generate_random_vector(50, 50)};
    std::vector<int> array { 41, 17, 34, 0, 19, 24, 28, 8, 12, 14, 5, 45, 31, 27, 11, 41, 45, 42, 27, 36, 41, 4, 2, 3, 42, 32, 21, 16, 18, 45, 47, 26, 21, 38, 19, 12, 17, 49, 35, 44, 3, 11, 22, 33, 23, 14, 41, 11, 3, 18 };

    {
        // Calcul du temps d'exécution du tri par sélection
        ScopedTimer timer("Temps tri implemente par C++ : ");
        std::sort(array.begin(), array.end());  
    }
    
    display_array(array);

    return 0;
}

/*
On voit que l'algorithme de tri implémenté directement par C++ met environ entre 20 et 40 us (soit entre 0.02 et 0.04 ms) 
pour être exécuté.

Pour trier le même tableau, l'algorithme de tri par sélection met environ entre 25 et 65 us (soit entre 0.025 et 0.065 ms)
pour être executé.

On peut donc conclure que l'algorithme le plus optimisé en terme de temps d'exécution est l'algorithme implémenté directement
par C++.

Par ailleurs, je n'ai pas réussi à terminer l'algorithme de tri-fusion, mais j'imagine que c'est le plus rapide de tous.
*/