#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>
#include <queue>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

std::string readNPI() {
    std::string token {};
    std::cout << "Entrez une expression en NPI : " << std::endl;
    std::getline(std::cin, token);
    return token;
}

bool is_floating(std::string const& s) {
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

float calculate (float leftOperand, float rightOperand, char op) {
    switch(op)
        {
        case '+':
            return leftOperand + rightOperand;
        case '-':
            return leftOperand - rightOperand;
        case '*':
            return leftOperand * rightOperand;
        case '/':
            return leftOperand / rightOperand;
        case '^':
            return pow(leftOperand,rightOperand);
        default:
            std::cout << "Unknown operator" << std::endl;
            return 0.f;
        }
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    // Calcul de l'expression NPI
    std::stack<float> operandStack;
    for (std::string const token : tokens) {
        if (is_floating(token)) {
            operandStack.push(stof(token));
        } else {
            float rightOperand { operandStack.top() };
            operandStack.pop();

            float leftOperand { operandStack.top() };
            operandStack.pop();

            char op { token[0] };
            operandStack.push(calculate(leftOperand, rightOperand, op));
        }
    }

    // Vérification de la validité de l'expression NPI et renvoie du résultat
    float res { operandStack.top() };
    operandStack.pop();
    if (!operandStack.empty()) {
        std::cout << "Erreur de notation NPI" << std::endl;
    }
    return res;
}

int main()
{
    std::string NPI_line {readNPI()};
    std::vector<std::string> NPI_vec {split_string(NPI_line)};
    float result = npi_evaluate(NPI_vec);
    std::cout << "Resultat = " << result;

    return 0;
}