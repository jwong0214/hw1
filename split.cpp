/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void appendRecursive(Node*& list, Node* node);

void split(Node*& in, Node*& odds, Node*& evens)
{
  // WRITE YOUR CODE HERE
  if (in == NULL) {
    return;
  }

  // Save the current node and move input pointer forward
  Node* curr = in;
  in = in->next;
  curr->next = NULL;

  // Place the current node into the correct list (odd/even)
  if (curr->value % 2 == 0) {
    appendRecursive(evens, curr)
  } else {
    appendRecursive(odds, curr)
  }

  // Recursive call on the remainder of the list
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void appendRecursive(Node*& list, Node* node) {
  if (list == NULL) {
    list = node;
  } else {
    appendRecursive(list->next, node)
  }
}