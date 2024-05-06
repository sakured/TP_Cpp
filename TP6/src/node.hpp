struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    void insert_from_root(int value);
    int Node::height() const;
    void Node::delete_childs();
    void Node::display_infixe() const;
    std::vector<Node const*> Node::prefixe() const;
};

int max (int a, int b);

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);

void pretty_print_left_right(Node const& node);

Node* create_node(int value);

Node*& most_left(Node*& node);

Node*& most_right(Node*& node);

bool remove(Node*& node, int value);

void delete_tree(Node* node);
