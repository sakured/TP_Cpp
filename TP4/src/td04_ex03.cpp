#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

bool is_palindrome(std::string const& str) {
    return std::equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
    std::string str {};
    std::cout << "Entrez un mot :" << std::endl;
    std::cin >> str;
    if (is_palindrome(str))  {
        std::cout << "C'est un palindrome" << std::endl;
    } else {
        std::cout << "Ce n'est pas un palindrome" << std::endl;
    }

    return 0;
}