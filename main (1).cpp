/**
 *  CS-102 Project 07: C++ BST implementationn of two different remove methods 
 *  @file main.cpp
 *  @author Javier Garcia
 *  @collaborators 
 *  @date 4/20/2023
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "tree.h"

int main() {
    BinaryTree tree1;
    BinaryTree tree2;
    std::ifstream input_file("input.txt");

    if (input_file.is_open()) {
        std::string line;
        
        // Read and process the first line
        if (std::getline(input_file, line)) {
            //std::cout << line << std::endl;
            std::istringstream iss(line);
            int value;

            while (iss >> value) {
                tree1.insert(value);
                tree2.insert(value);
            }
        }
        
        // Read and process the second line
        if (std::getline(input_file, line)) {
            int value_to_remove = std::stoi(line);
            std::cout << "Tree before normal remove:\n";
            tree1.print_tree(std::cout);
            std::cout << "\n";
            tree1.normal_remove(value_to_remove);
            std::cout << "Tree after normal remove:\n";
            tree1.print_tree(std::cout);
            std::cout << "\nHeight after normal remove: " << tree1.height() << "\n\n";

            
            

            // Remove key from second row using JR-remove
            std::cout << "Tree before JR-remove:\n";
            tree2.print_tree(std::cout);
            std::cout << "\n";
            tree2.jr_remove(value_to_remove);
            std::cout << "Tree after JR-remove:\n";
            tree2.print_tree(std::cout);
            std::cout << "\nHeight after JR-remove: " << tree2.height() << "\n\n";
        }
    }

    return 0;
}