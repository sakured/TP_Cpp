#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "graph.hpp"

bool Graph::WeightedGraph::is_existing(int const id) {
    if (this->adjacency_list.find(id) != this->adjacency_list.end()) {
        return true;
    }
    return false;
}

void Graph::WeightedGraph::add_vertex(int const id) {
    std::vector<Graph::WeightedGraphEdge> list_edges {};
    if (!this->is_existing(id)) {
        this->adjacency_list.insert(std::make_pair(id, list_edges));
    }
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
    this->add_vertex(from);
    this->add_vertex(to);
    auto key { this->adjacency_list.find(from) };
    (*key).second.push_back({to, weight}); 
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
    this->add_vertex(from);
    this->add_vertex(to);
    auto key_from { this->adjacency_list.find(from) };
    (*key_from).second.push_back({to, weight});
    auto key_to { this->adjacency_list.find(to) };
    (*key_to).second.push_back({from, weight}); 
}

Graph::WeightedGraph Graph::adjacency_list_from_adjacency_matrix (std::vector<std::vector<float>> const& adjacency_matrix) {
    Graph::WeightedGraph graph {};
    for (int from=0; from<adjacency_matrix.size(); from++) {
        for (int to=0; to<adjacency_matrix[from].size(); to++) {
            if (adjacency_matrix[from][to] != 0) {
                graph.add_directed_edge(from, to, adjacency_matrix[from][to]);
            }
        }
    }
    return graph;
}

void Graph::WeightedGraph::print_DFS(int const start) const {
    std::vector<int> already_printed {};
    std::stack<int> stack {};
    stack.push(start);
    while (!stack.empty()) {
        int curent_node { stack.top() };
        std::cout << curent_node << " ";
        stack.pop();
        already_printed.push_back(curent_node);
        for (Graph::WeightedGraphEdge link : this->adjacency_list.find(curent_node)->second) {
            if (find(already_printed.begin(), already_printed.end(), link.to) == already_printed.end()) {
                stack.push(link.to);
            }
        }
    }
}

void Graph::WeightedGraph::print_BFS(int const start) const {
    std::vector<int> already_printed {};
    std::queue<int> queue {};
    queue.push(start);
    while (!queue.empty()) {
        int curent_node { queue.front() };
        std::cout << curent_node << " ";
        queue.pop();
        already_printed.push_back(curent_node);
        for (Graph::WeightedGraphEdge link : this->adjacency_list.find(curent_node)->second) {
            if (find(already_printed.begin(), already_printed.end(), link.to) == already_printed.end()) {
                queue.push(link.to);
            }
        }
    }
}

// bool is_in_stack(std::stack<int> stack, int target) {
//     while (!stack.empty()) {
//         if (stack.top() == target) {
//             return true; 
//         }
//         stack.pop();
//     }
//     return false;
// }

// bool is_in_queue(std::queue<int> queue, int target) {
//     while (!queue.empty()) {
//         if (queue.front() == target) {
//             return true; 
//         }
//         queue.pop();
//     }
//     return false;
// }
