// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List


//
//@ Dev
// Apartment object
// ====================
// This class is used for the storage and manipulation of data related to apartments. 
// Data stored includes the name of the apartment complex (character array), 
// the number of bedrooms(integer), the number of bathrooms(float), the cost of 
// rent(float), and whether or not the apartment has air conditioning(integer/boolean).
// This class also controls the head node of a linked list. The linked list in this 
// class is used for storage of features pertaining to each apartment complex. The functions
// available to use on this linked list of features includes adding, removing, displaying
// and determining if the feature is present at the apartment complex.

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
    Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms, int _air_conditioning);
    int copy_entry(const Apartment & copy_from);
    int display(void);

    // Display only apartments that have a specific feature (also can display review)
    // Pass the name of the feature as an argument. Return error if no apartments have a matching feature.
    bool display_feature_specific(char * feature); // Iterative function
    
    // Add a feature and review for a given apartment.
    // Pass a feature object as an argument. Returns false if the feature is already in the list. 
    bool add_feature(Feature & _feature); 
    
    // Allows client to change the values stored in an apartment object.
    // Returns true for success and false for failure
    bool set_apartment(char* _name, int _bedrooms, float _rent, float _bathrooms, int _air_conditioning);
    float round(float arg);

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

    //Display all apartments in the list
    // Recursive function
    bool display_feature_list();
    
    // Remove an apartment from the list.
    // Pass the name of the apartment to be removed as an argument.
    int remove_feature(char * _name);

    // Checks to see if an apartment has a given feature. 
    // Returns binary value to indicate whether the feature is present or not.
    int has_feature(char * to_find);
 
  // ===============================================================================================
  private:
    char * name;
    int bedrooms;
    float rent;
    float bathrooms; 
    int air_conditioning;
    Feature_node * feature_head;

    bool display_feature_specific(Feature_node * & head, char * feature_name); // Recursive function
    bool display_feature_list(Feature_node* & head);
    bool add_feature(Feature_node * & head, Feature & _feature);// Recursive function
};

#endif

