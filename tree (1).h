#ifndef TREE_H
#define TREE_H

#include "node.h"

class BinaryTree {
public:
    BinaryTree();

    void insert(int key);
    void normal_remove(int key);
    void jr_remove(int key);
    int height();
    void print_tree(std::ostream& out);

private:
    Node* root;

    Node* insert(Node* node, int key);
    Node* normal_remove(Node* node, int key);
    Node* find_min(Node* node);
    Node* remove_min(Node* node);
    Node* jr_remove(Node* node, int key);
    int height(Node* node);
    void print_tree(Node* node, std::ostream& out);
};

#endif
