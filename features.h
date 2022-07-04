// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

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
    int copy_entry(const Feature & copy_from);
    int display(void);
    char * get_feature();
    char * get_review();
};

#endif

