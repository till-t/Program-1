// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#ifndef LIST_H
#define LIST_H

#include "apartment.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

struct node
{
  Apartment apartment;
  node * next;
};


class Apartment_list
{
  public:
    // Constructor and Destructor
    Apartment_list();
    ~Apartment_list(); // Release all dynamic memory

    // Add a new apartment by passing info for apartment as arguments.
    // Return an error if the apartment is already in the list.
    // Recursive function
    bool add_apartment(Apartment & _apartment);
    bool add_apartment(node * & head, Apartment & _apartment);

    //Display all apartments in the list
    // Recursive function
    bool display_apartment_list();
    bool display_apartment_list(node* & head);
    
    // Remove an apartment from the list.
    // Pass the name of the apartment to be removed as an argument.
    bool remove_apartment(char * _name); // Iterative function
  
    // For all recursive functions we will most likely need wrapper functions.
    // Add these functions as needed during implementation.
// ============================================================================================================= 

 private:
    node * head;

};

#endif
