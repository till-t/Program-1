// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#ifndef APARTMENT_H
#define APARTMENT_H

#include "features.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

struct Feature_node 
{
  Feature feature;
  Feature_node * next;

};

// Comments for .h files
// - Why you would want to use the data type
// - How to call the functions(args, return types)
// - Aimed at the application programmer

class Apartment
{

  public:
    Apartment();
    ~Apartment();
    Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms);
    int copy_entry(const Apartment & copy_from);
    int display(void);

    // Display only apartments that have a specific feature (also can display review)
    // Pass the name of the feature as an argument. Return error if no apartments have a matching feature.
    bool display_feature_specific(Feature_node * & head, char * feature); // Recursive function
    bool display_feature_specific(char * feature); // Iterative function
    
    // Add a feature and review for a given apartment.
    // Pass name of apartment as argument 1, and the Feature object (feature, review) that we want to add.
    bool add_feature(Feature_node * & head, char * _name, Feature & _feature); // Recursive function
    bool add_feature(char * _name, Feature & _feature); // Iterative function
    void set_apartment(char* _name, int _bedrooms, float _rent, float _bathrooms);

    // Getters 
    // ========================================================================================
    char * get_name();
    Feature_node * get_node();
    int get_bedrooms();
    float get_bathrooms();
    float get_rent();

    // Functions that handle Feature list
    // ========================================================================================
    void delete_feature_list(); // Release all dynamic memory

    // Add a new apartment by passing info for apartment as arguments.
    // Return an error if the apartment is already in the list.
    // Recursive function
    bool add_feature(Feature & _feature);
    bool add_feature(Feature_node * & head, Feature & _feature);

    //Display all apartments in the list
    // Recursive function
    bool display_feature_list();
    bool display_feature_list(Feature_node* & head);
    
    // Remove an apartment from the list.
    // Pass the name of the apartment to be removed as an argument.
    bool remove_feature(char * _name); // Iterative function
 
  // ===============================================================================================
  private:
    char * name;
    int bedrooms;
    float rent;
    float bathrooms; 
    Feature_node * feature_head;

};

#endif

