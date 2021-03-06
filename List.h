// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

// @ Dev
// Apartment List Object
// ====================
// This class is used for the storgae of Apartment objects, and in turn, Feature objects.
// The data structure used for storage is a linear linked list with a head node as the 
// only point of entry into the data. Functions included are adding Apartment objects, 
// removing Apartment objects, displaying all objects in the list, adding a feature to 
// a given apartment, displaying all features for a given apartment, and displaying all 
// apartments for a given feature. Recursive functions used include adding an apartment
// object and displaying all apartments in the linked list. 

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

    //Display all apartments in the list
    // Recursive function
    bool display_apartment_list();
    
    // Remove an apartment from the list.
    // Pass the name of the apartment to be removed as an argument.
    bool remove_apartment(char * _name); // Iterative function

    // Add a feature to a given apartment.
    // Pass the name of the apartment that we would like to add to 
    // and the Feature object. 
    bool add_feature(char * _name, Feature & _feature);

    // Display all features for a given apartment.
    // Pass the name of the apartment complex that we would like to display for.
    bool display_feature_list(char * _name);

    // Display only apartments that have a given feature.
    bool display_feature_specific(char * _feature_to_find);
  
    // For all recursive functions we will most likely need wrapper functions.
    // Add these functions as needed during implementation.
// ============================================================================================================= 

 private:
    node * head;

    bool add_apartment(node * & head, Apartment & _apartment);
    bool display_apartment_list(node* & head);
};

#endif
