#include <iostream>
#include "tree.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insert(int key) {
    root = insert(root, key);
}

Node* BinaryTree::insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node;
    } else {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
    return node;
}

void BinaryTree::normal_remove(int key) {
    root = normal_remove(root, key);
}

Node* BinaryTree::normal_remove(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = normal_remove(node->left, key);
    } else if (key > node->key) {
        node->right = normal_remove(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        node->key = find_min(node->right)->key;
        node->right = remove_min(node->right);
    }
    return node;
}

Node* BinaryTree::find_min(Node* node) {
    if (node->left == nullptr) {
        return node;
    }
    return find_min(node->left);
}

Node* BinaryTree::remove_min(Node* node) {
    if (node->left == nullptr) {
        Node* temp = node->right;
        delete node;
        return temp;
    }
    node->left = remove_min(node->left);
    return node;
}

void BinaryTree::jr_remove(int key) {
    root = jr_remove(root, key);
}
Node* BinaryTree::jr_remove(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = jr_remove(node->left, key);
    } else if (key > node->key) {
        node->right = jr_remove(node->right, key);
    } else {
        if (node->left != nullptr && node->right != nullptr) {
            Node* y = find_min(node->right);
            std::cout << node->key << "\n";
            //std::cout << y->key << "\n";
            //std::cout << node->left->key << "\n";
            y->left = node->left;
            node->left->parent = y;
            if (y->parent != node) {
                y->parent->left = y->right;
                y->right = node->right;
            }
            
            if (node->parent == nullptr) {
                //std::cout << "okie 1\n";
                //node->right->parent = nullptr;
                root = y;
            }
            else if (node->parent->left == node) {
                //std::cout << "okie 2\n";
                node->parent->left = node->left;
                node->left->parent = node->parent;
            }
            else {
                std::cout << "okie 3\n";
                node->parent->right = node->right;
                node->right->parent = node->parent;
            }
            y->parent = node->parent;
            //delete node;
            node = y;

            /*
            
            
              
            y->parent = node->parent;
            delete node;
            */
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            node->key = find_min(node->right)->key;
            node->right = remove_min(node->right);
        }
    }
    return node;
}
int BinaryTree::height() {
    return height(root);
}

int BinaryTree::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return std::max(left_height, right_height) + 1;
}

void BinaryTree::print_tree(std::ostream& out) {
    print_tree(root, out);
}

void BinaryTree::print_tree(Node* node, std::ostream& out) {
    if (node == nullptr) {
        return;
    }
    print_tree(node->left, out);
    out << node->key << " ";
    print_tree(node->right, out);
}
