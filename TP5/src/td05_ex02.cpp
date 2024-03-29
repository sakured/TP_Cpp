#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> fixes_map {};
    for (std::pair<std::string, float> pair : robots_fixes) {
        std::vector<float> fixes_vec {};
        auto key = (fixes_map.find(pair.first));
        if (key == fixes_map.end()) {
            fixes_vec.push_back(pair.second);
            fixes_map.insert(std::make_pair(pair.first,fixes_vec));
        } else {
            (*key).second.push_back(pair.second);
        }
    }
    return fixes_map;
}

float sum_fixes(std::vector<float> vec) {
    float sum {0};
    for (float value : vec) {
        sum += value;
    }
    return sum;
}

int main()
{
    size_t size = 50;
    std::vector<std::pair<std::string, float>> robots_fix { get_robots_fix(size) };
    std::unordered_map<std::string, std::vector<float>> robots_fix_map { robots_fixes_map(robots_fix) };

    // Afficher le contenu de robots_fix_map et la somme des réparations par robot
    for (std::pair<std::string, std::vector<float>> pair : robots_fix_map) {
        std::cout << pair.first << " ";
        for (float f : pair.second) {
            std::cout << f << " ";
        }
        // Somme des cout des réparations par robot
        std::cout << "-> Somme des reparations : " << sum_fixes(pair.second) << std::endl;
    }

    return 0;
}