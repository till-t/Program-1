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


class Apartment
{
  private:
    char * name;
    int bedrooms;
    float rent;
    float bathrooms; 
    Feature_node * feature_head;

  public:
    Apartment();
    ~Apartment();
    Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms);
    int copy_entry(const Apartment & copy_from);
    int display(void);
    char * get_name();
    Feature_node * get_node();
    int get_bedrooms();
    float get_bathrooms();
    float get_rent();

};

#endif

