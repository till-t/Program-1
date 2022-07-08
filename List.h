// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

// @ Dev
// Apartment List Object
// ====================
//  

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

};

#endif
