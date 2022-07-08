// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

// @ Dev
// ====================
// This class is used for the storage of data pertaining to features at a given apartment complex.
// Data stored includes the name of the feature (character array), and the review of the given 
// feature (character array). Functions available for this class include setting a feature object
// given client input, displaying a feature and review, and copying one Feature object to another. 
// This class is implemented inside of a linked list which is controlled by the Apartment class. 

#ifndef FEATURE_H 
#define FEATURE_H 

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

class Feature
{
  private:
    char * feature;
    char * review;

  public:
    Feature();
    ~Feature();
    Feature(char* f, char* r);
    void set_feature(char* _review, char* _feature);
    int copy_entry(const Feature & copy_from);
    int display(void);
    char * get_feature();
    char * get_review();
};

#endif

