#include <iostream>
#include <string>

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash = 0;
    for (char c : s) {
        hash += c;
    }
    return hash % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash = 0;
    for (int i=0; i<s.size(); i++) {
        hash += s[i] * (i + 1); // on met i+1 pour différencer le premier caractère (sinon son hash sera toujours 0)
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash = 0;
    size_t power = 1;
    for (int i=0; i<s.size(); i++) {
        hash += s[i] * pow(p,i);
        power *= p;
    }
    return hash % m;
}

int main()
{
    size_t max = 1024;
    size_t p = 10;
    std::string str1 = {"bonjour"};
    std::string str2 = {"jourbon"};
    std::string str3 = {"anticonstitution"};

    std::cout << "Hash de " << str1 << " : " << folding_string_hash(str1, max) << std::endl;
    std::cout << "Hash de " << str2 << " : " << folding_string_hash(str2, max) << std::endl;
    std::cout << "Hash de " << str3 << " : " << folding_string_hash(str3, max) << std::endl << std::endl;

    std::cout << "Hash de " << str1 << " : " << folding_string_ordered_hash(str1, max) << std::endl;
    std::cout << "Hash de " << str2 << " : " << folding_string_ordered_hash(str2, max) << std::endl;
    std::cout << "Hash de " << str3 << " : " << folding_string_ordered_hash(str3, max) << std::endl << std::endl;

    std::cout << "Hash de " << str1 << " : " << polynomial_rolling_hash(str1, p, max) << std::endl;
    std::cout << "Hash de " << str2 << " : " << polynomial_rolling_hash(str2, p, max) << std::endl;
    std::cout << "Hash de " << str3 << " : " << polynomial_rolling_hash(str3, p, max) << std::endl;
    return 0;
}