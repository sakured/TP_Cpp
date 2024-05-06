#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"

int max (int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value) {
    return { new Node {value, nullptr, nullptr}};
}

bool Node::is_leaf() const {
    return this->left == nullptr && this->right == nullptr;
}

void Node::insert(int value) {
    Node* new_node { create_node(value) };
    if (value < this->value) {
        this->left = new_node;
    } else {
        this->right = new_node;
    }
}

/**
 * Je n'était pas sûre d'avoir bien compris l'objectif de la fonction insert (c'est-à-dire insérer une valeur sous un
 * noeud donné). J'ai donc créé une fonction insert_from_root qui insère un noeud à la bonne place depuis la racine 
 * d'un arbre ou d'un sous-arbre
*/
void Node::insert_from_root(int value) {
    if (value < this->value) {
        if (this->left == nullptr) {
            Node* new_node { create_node(value) };
            this->left = new_node;
        } else {
            this->left->insert_from_root(value);
        }
    } else {
        if (this->right == nullptr) {
            Node* new_node { create_node(value) };
            this->right = new_node;
        } else {
            this->right->insert_from_root(value);
        }
    }
}

int Node::height() const {
    if (this == nullptr) {
        return 0;
    } else {
        return 1 + max(this->left->height(), this->right->height());
    }
}

void Node::delete_childs() {
    if (this->left != nullptr) {
        this->left->delete_childs();
        this->left = nullptr;
        delete this->left;
    }
    if (this->right != nullptr) {
        this->right->delete_childs();
        this->right = nullptr;
        delete this->right;
    }
}

void Node::display_infixe() const {
    if (this == nullptr) {
        return;
    }
    this->left->display_infixe();
    std::cout << this->value << " ";
    this->right->display_infixe();
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> nodes {};
    nodes.push_back(this);
    if (this->left) {
        auto left_nodes { left->prefixe() };
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    } if (this->right) {
        auto right_nodes { right->prefixe() };
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

/**
 * Dans le cas où l'on créé un arbre en utilisant la fonction insert_from_root, l'arbre binaire est forcément trié, 
 * et par conséquent le minimum est le noeud le plus à gauche, et le maximum est le noeud le plus à droite. On peut donc 
 * utiliser les fonctions most_left et most_right pour trouver les valeurs minimales et maximales.
*/

Node*& most_left(Node*& node) {
    if (node->left == nullptr) {
        return *&node;
    } else {
        return most_left(node->left);
    }
}

Node*& most_right(Node*& node) {
    if (node->right == nullptr) {
        return *&node;
    } else {
        return most_right(node->right);
    }
}

bool remove(Node*& node, int value) {
    // On se déplace jusqu'au noeud à enlever
    if (node != nullptr && value < node->value) {
        remove(node->left, value);
    } else if (node != nullptr && value > node->value) {
        remove(node->right, value);

    // Noeud à enlever non trouvé
    } else if (node == nullptr) {
        return false;
    
    // Cas où le noeud est une feuille
    } else if (node->is_leaf()) {
        delete node;
        node = nullptr;
        return true;

    // Cas où le noeud a juste un fils gauche
    } else if (node->left != nullptr && node->right == nullptr) {
        node = node->left;
        delete node->left;
        return true;

    // Cas où le noeud a juste un fils droit
    } else if (node->left == nullptr && node->right != nullptr) {
        node = node->right;
        delete node->right;
        return true;

    // Cas où le noeud a deux fils
    } else if (node->left != nullptr && node->right != nullptr) {
        Node *&leftest { most_left(node->right) };
        node->value = leftest->value;
        remove(leftest, leftest->value);
        return true;
    }
}

void delete_tree(Node* node) {
    node->delete_childs();
    delete node;
}
