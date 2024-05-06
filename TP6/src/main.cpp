#include <iostream>
#include <vector>
#include "node.hpp"

int main()
{

    // -------------------------------------------------- EXERCICE 1 --------------------------------------------------

    std::cout << "-------------------- EXERCICE 1 --------------------" << std::endl;

    // QUESTION 1
    Node* root { create_node(2) };

    // QUESTION 2
    std::cout << "root->is_leaf() : " << root->is_leaf() << std::endl << std::endl;

    // QUESTION 3
    // root->insert(4);
    // root->insert(1);
    // root->right->insert(3);
    // root->left->insert(0);
    // root->left->left->insert(1);
    // root->right->left->insert(3);
    // root->right->left->right->insert(6);
    // root->right->left->right->insert(2);
    // root->right->left->right->insert(3);
    root->insert_from_root(4);
    root->insert_from_root(1);
    root->insert_from_root(3);
    root->insert_from_root(0);
    root->insert_from_root(1);
    root->insert_from_root(3);
    root->insert_from_root(6);
    root->insert_from_root(2);
    root->insert_from_root(3);
    root->insert_from_root(7);
    pretty_print_left_right(*root);

    // QUESTION 4
    std::cout << "root->height() : " << root->height() << std::endl << std::endl;

    // QUESTION 5
    root->right->left->right->delete_childs();
    pretty_print_left_right(*root);
    std::cout << "Apres suppression : root->height() : " << root->height() << std::endl;

    // QUESTION 6
    std::cout << "Infixe : ";
    root->display_infixe();
    std::cout << std::endl;

    // QUESTION 7
    std::cout << "Prefixe : ";
    std::vector<Node const*> nodes = root->prefixe();
    for (Node const* node : nodes) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    // QUESTION 9
    Node *&leftest { most_left(*&root) };
    std::cout << "Most left : " << leftest->value << std::endl << std::endl;

    // QUESTION 10
    remove(root, 4);
    pretty_print_left_right(*root);
    std::cout << "Apres suppresion du noeud 4 " << std::endl;

    // QUESTION 11
    delete_tree(root);
    std::cout << "Suppression de l'arbre effectuee" << std::endl;

    // QUESTION 12
    // Utilisation des fonctions most_left et most_right


    // -------------------------------------------------- EXERCICE 2 --------------------------------------------------

    std::cout << std::endl << "-------------------- EXERCICE 2 --------------------" << std::endl;

    Node* tree_root { create_node(5) };
    tree_root->insert_from_root(3);
    tree_root->insert_from_root(7);
    tree_root->insert_from_root(2);
    tree_root->insert_from_root(4);
    tree_root->insert_from_root(6);
    tree_root->insert_from_root(8);
    tree_root->insert_from_root(1);
    tree_root->insert_from_root(9);
    tree_root->insert_from_root(0);

    pretty_print_left_right(*tree_root);

    tree_root->display_infixe();

    Node * node_min { most_left(tree_root) };
    Node * node_max { most_right(tree_root) };
    std::cout << std::endl << "Min : " << node_min->value << " Max : " << node_max->value << std::endl;

    std::vector<Node const*> tree_nodes = tree_root->prefixe();
    int sum {0};
    for (Node const* node : tree_nodes) {
        sum += node->value;
    }
    std::cout << "Somme : " << sum << std::endl;

    std::cout << "Hauteur : " << tree_root->height() << std::endl;

    return 0;
}

