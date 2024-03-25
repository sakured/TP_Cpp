#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

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
    for (auto it = begin_iterator; it != end_iterator; it++) {
        std::cout << *it << ", ";
    }
    // std::cout << begin_iterator << std::endl;
    // for (int v : vec) {
    //     std::cout << v << std::endl;
    // }

    return 0;
}