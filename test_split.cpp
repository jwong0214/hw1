/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <sstream>
#include <cstddef>

// Build a linked list from command line arguments
Node* buildListFromArgs(int argc, char* argv[]) {
    if (argc <= 1) return NULL; // no numbers given

    Node* head = new Node{std::stoi(argv[1]), NULL};
    Node* curr = head;

    for (int i = 2; i < argc; i++) {
        curr->next = new Node{std::stoi(argv[i]), NULL};
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void freeList(Node* head) {
    if (head == NULL) return;
    freeList(head->next);
    delete head;
}

int main(int argc, char* argv[]) {
    // Build list from command-line input
    Node* in = buildListFromArgs(argc, argv);

    Node* odds = NULL;
    Node* evens = NULL;

    split(in, odds, evens);

    std::cout << "Odds: ";
    printList(odds);
    std::cout << "Evens: ";
    printList(evens);

    // Free memory
    freeList(odds);
    freeList(evens);

    return 0;
}
