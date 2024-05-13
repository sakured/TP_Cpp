#include <iostream>
#include <vector>
#include "graph.hpp"

int main()
{

    // -------------------------------------------------- EXERCICE 1 --------------------------------------------------

    std::cout << "-------------------- EXERCICE 1 --------------------" << std::endl;
    
    std::cout << "Verification du graphe avec adjacency_list_from_adjacency_matrix()";

    std::vector<std::vector<float>> adjacency_matrix {{0.f, 1.1, 2.5, 0.f},
                                                      {0.f, 0.f, 0.f, 1.1},
                                                      {0.f, 0.f, 0.5, 0.f},
                                                      {0.f, 1.1, 0.f, 0.f}};

    // std::vector<std::vector<float>> adjacency_matrix {{0.f, 1.f, 2.f, 0.f, 0.f},
    //                                                   {0.f, 0.f, 1.f, 5.f, 0.f},
    //                                                   {0.f, 0.f, 0.f, 3.f, 6.f},
    //                                                   {0.f, 0.0f, 0.f, 0.f, 2.f},
    //                                                   {0.f, 0.f, 0.f, 0.f, 0.f}};

    Graph::WeightedGraph result_graph { Graph::adjacency_list_from_adjacency_matrix(adjacency_matrix) };

    // Affichage pour vérifier le contenu du graphe (le poid des liens est entre parenthèses)
    for (std::pair<int, std::vector<Graph::WeightedGraphEdge>> pair : result_graph.adjacency_list) {
        std::cout << std::endl << "Voisins du noeud d'indice " << pair.first << " :  ";
        for (Graph::WeightedGraphEdge link : pair.second) {
            std::cout << link.to << " (" << link.weight << ")  ";
        }
    }

    std::cout << std::endl << std::endl << "Verification d'un graphe cree a la main";

    Graph::WeightedGraph mano_graph {};

    mano_graph.add_vertex(0);
    mano_graph.add_vertex(1);
    mano_graph.add_vertex(2);
    mano_graph.add_vertex(3);
    mano_graph.add_directed_edge(0, 1, 1.1);
    mano_graph.add_directed_edge(0, 2, 2.5);
    mano_graph.add_directed_edge(2, 2, 0.5);
    mano_graph.add_directed_edge(1, 3, 1.1);
    mano_graph.add_directed_edge(3, 1, 1.1);

    // Affichage pour vérifier le contenu du graphe (le poid des liens est entre parenthèses)
    for (std::pair<int, std::vector<Graph::WeightedGraphEdge>> pair : result_graph.adjacency_list) {
        std::cout << std::endl << "Voisins du noeud d'indice " << pair.first << " :  ";
        for (Graph::WeightedGraphEdge link : pair.second) {
            std::cout << link.to << " (" << link.weight << ")  ";
        }
    }
    
    if (result_graph == mano_graph) {
        std::cout << std::endl << std::endl << "Les graphes sont egaux" << std::endl;
    } else {
        std::cout << std::endl << std::endl << "Les graphes ne sont pas egaux" << std::endl;
    }


    // -------------------------------------------------- EXERCICE 2 --------------------------------------------------

    std::cout << std::endl << "-------------------- EXERCICE 2 --------------------" << std::endl;

    std::cout << "Affichage en profondeur : ";
    result_graph.print_DFS(0);

    std::cout << std::endl << "Affichage en largeur : ";
    result_graph.print_BFS(0);

    // -------------------------------------------------- DIJKSTRA --------------------------------------------------

    std::cout << std::endl << std::endl << "-------------------- Dijkstra --------------------" << std::endl;

    std::vector<std::vector<float>> adjacency_matrix_dijkstra {{0.f, 1.f, 5.f, 2.f, 0.f, 0.f},
                                                               {0.f, 0.f, 4.f, 5.f, 0.f, 0.f},
                                                               {0.f, 0.f, 0.f, 0.f, 3.f, 4.f},
                                                               {0.f, 0.f, 2.f, 0.f, 5.f, 0.f},
                                                               {0.f, 0.0f, 0.f, 0.f, 0.f, 3.f},
                                                               {0.f, 0.f, 0.f, 0.f, 0.f, 0.f}};

    Graph::WeightedGraph result_graph_dijkstra { Graph::adjacency_list_from_adjacency_matrix(adjacency_matrix_dijkstra) };

    std::unordered_map<int, std::pair<float, int>> distances { Graph::dijkstra(result_graph_dijkstra, 0, 5) };

    // VERIFICATION DE DIJKSTRA
    for (std::pair<int, std::pair<float, int>> pair : distances) {
        std::cout << std::endl << "Noeud " << pair.first << " ( " << pair.second.first << " , " << pair.second.second << " ) " << std::endl; 
    }


    return 0;
}

