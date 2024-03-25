#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

enum class TokenType { OPERATOR, OPERAND };

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN };

struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value) {
    return Token {TokenType::OPERAND, value};
}

Token make_token(Operator op) {
    return Token {TokenType::OPERATOR, NULL, op};
}

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

std::string read_entry() {
    std::string words {};
    std::cout << "Entrez une expression infixe : " << std::endl;
    std::getline(std::cin, words);
    return words;
}

bool is_floating(std::string const& s) {
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> tokens;
    for (std::string w : words) {
        if (is_floating(w)) {
            tokens.push_back(make_token(stof(w)));
        } else {
            if (w == "+") {
                tokens.push_back(make_token(Operator::ADD));
            } else if (w == "-") {
                tokens.push_back(make_token(Operator::SUB));
            } else if (w == "*") {
                tokens.push_back(make_token(Operator::MUL));
            } else if (w == "/") {
                tokens.push_back(make_token(Operator::DIV));
            } else if (w == "^") {
                tokens.push_back(make_token(Operator::POW));
            } else if (w == "(") {
                tokens.push_back(make_token(Operator::OPEN_PAREN));
            } else if (w == ")") {
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
            }   
        }
    }
    return tokens;
}

float calculate (float leftOperand, float rightOperand, Operator op) {
    switch(op)
    {
    case Operator::ADD :
        return leftOperand + rightOperand;
    case Operator::SUB :
        return leftOperand - rightOperand;
    case Operator::MUL :
        return leftOperand * rightOperand;
    case Operator::DIV :
        return leftOperand / rightOperand;
    case Operator::POW :
        return pow(leftOperand,rightOperand);
    default:
        std::cout << "Operateur inconnu" << std::endl;
        return 0.f;
    }
}

float npi_evaluate(std::vector<Token> const& tokens) {
    // Calcul de l'expression NPI
    std::stack<float> operandStack;
    for (Token const token : tokens) {
        if (token.type == TokenType::OPERAND) {
            operandStack.push(token.value);
        } else {
            float rightOperand { operandStack.top() };
            operandStack.pop();

            float leftOperand { operandStack.top() };
            operandStack.pop();

            Operator op { token.op };
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

size_t operator_precedence(Operator const op) {
    switch(op)
    {
    case Operator::ADD :
        return 1;
    case Operator::SUB :
        return 1;
    case Operator::MUL :
        return 2;
    case Operator::DIV :
        return 2;
    case Operator::POW :
        return 3;
    default:
        return 0;
    }
}

std::vector<Token> infix_to_npi_tokens(std::vector<Token> const& expression) {
    std::vector<Token> output {};
    std::stack<Token> operatorStack {};
    for (Token token : expression) {
        // Nombre -> on ajoute le token à la sortie
        if (token.type == TokenType::OPERAND) {
            output.push_back(token);
        // Opérateur ou parenthèse
        } else {
            // Pile des opérateurs vide ou token = parenthèse ouvrante ou opétateur avec plus petite priorité
            // que l'opérateur précédent -> on ajoute le token à la pile des opérateurs
            if (operatorStack.empty() || token.op == Operator::OPEN_PAREN || operator_precedence(token.op) >= operator_precedence(operatorStack.top().op)) {
                operatorStack.push(token);
            // Parenthèse fermante -> on dépile jusqu'à la parenthèse ouvrante
            } else if (token.op == Operator::CLOSE_PAREN) {
                while (operatorStack.top().op != Operator::OPEN_PAREN) {
                    output.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                // On enlève la parenthèse ouvrante
                operatorStack.pop();
            // Opérateur avec plus grande priorité que le précédent -> on dépile
            } else {
                output.push_back(operatorStack.top());
                operatorStack.pop();
                operatorStack.push(token);
            }
        }
    }
    // On dépile les opérateurs restants
    while (!operatorStack.empty()) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
    }
    return output;
}

int main()
{
    std::string entry_line {read_entry()};
    std::vector<std::string> entry_vec {split_string(entry_line)};
    std::vector<Token> token_vec {tokenize(entry_vec)};
    std::vector<Token> npi_token_vec {infix_to_npi_tokens(token_vec)};
    float result = npi_evaluate(npi_token_vec);
    std::cout << "Resultat = " << result;
    return 0;
}