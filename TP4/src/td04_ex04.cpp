#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> v {2, 5, 1, 10, 8, 6, 9, 4, 7, 3};

    // 1. Somme des carrés
    int sum { std::accumulate(v.begin(), v.end(), 0, [](int sum, int current_element) { return sum + pow(current_element,2); }) };
    std::cout << "Somme des carres : " << sum << std::endl;

    // 2. Produit des éléments pairs
    auto is_pair = [](int number){ return number % 2 == 0; };
    int mul { std::accumulate(v.begin(), v.end(), 1, [&](int mul, int current_element) { return (is_pair(current_element)) ? mul * current_element : mul; }) };
    std::cout << "Produit des pairs : " << mul << std::endl;

    return 0;
}