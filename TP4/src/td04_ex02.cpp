#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

auto const is_space = [](char letter){ return letter == ' '; };

int number_of_letters(std::string const & str) {
    auto it = std::find_if(str.begin(), str.end(),is_space);
    return std::distance(str.begin(), it);
}

std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> vec {};
    auto it_begin { str.begin() };
    while (it_begin != str.end()) {
        std::string word {};
        auto it_space = std::find_if(it_begin, str.end(), is_space);
        int distance = std::distance(it_begin, it_space);
        for (auto it = it_begin; it != it_space; it++) {
            word += *it;
        }
        vec.push_back(word);
        (it_space != str.end()) ? it_begin = it_space + 1 : it_begin = str.end();
    }
    return vec;
}

// Je n'ai pas trop compris si on était obligé d'utiliser les fonctions "find_if" et "distance" pour faire 
// la question 2 alors j'ai codé un algo avec (voir ci-dessus), et un algo sans qui est beaucoup plus 
// simple et compréhensible
std::vector<std::string> easy_split_string(std::string const& str) {
    std::vector<std::string> vec {};
    std::string word {};
    for (auto it = str.begin(); it != str.end(); it++) {
        if (is_space(*it)) {
            vec.push_back(word);
            word = "";
        } else {
            word += *it;
        }
    }
    vec.push_back(word);
    return vec;
}

int main()
{
    std::string str {"Bonjour je suis fan du C plus plus"};

    // 1. Affichage du  nombre de lettres dans le premier mot
    std::cout << "Nombre de lettres 1er mot : " << number_of_letters(str) << std::endl;

    // 2. Affichage des mots du tableau une fois la phrase splitée
    std::vector<std::string> vec { split_string(str) };
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }

    // 2.bis. Affichage des mots du tableau une fois la phrase splitée avec l'algo plus simple
    std::vector<std::string> vec2 { easy_split_string(str) };
    std::cout << std::endl;
    for (auto it = vec2.begin(); it != vec2.end(); it++) {
        std::cout << *it << " ";
    }

    return 0;
}