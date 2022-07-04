// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#include "apartment.h"

//Default constructor
Apartment::Apartment() : name(NULL), bedrooms(0), rent(0), bathrooms(0) {} 

//Deconstructor
Apartment::~Apartment()
{
  if (name != NULL)
    delete [] name;
}

//Parameterized constructor. 
Apartment::Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms)
{
  name = _name;
  bedrooms = _bedrooms;
  rent = _rent;
  bathrooms = _bathrooms;
  feature_head = NULL;
}

//Copy used to move the data into the linked list.
int Apartment::copy_entry(const Apartment & copy_from)
{
  if (name)
    delete [] name;

  name = new char[strlen(copy_from.name) + 1];
  strcpy(name, copy_from.name);
  bedrooms = copy_from.bedrooms;
  bathrooms = copy_from.bathrooms;
  rent = copy_from.rent;
  return 1;
}

//Displays information for each apartment to the console.
int Apartment::display(void)
{
  std::cout << "Name: " << name << std::endl;
  std::cout << "Number of bedrooms: " << bedrooms << std::endl;
  std::cout << "Number of bathrooms: " << bathrooms << std::endl;
  std::cout << "Cost of rent: " << rent << std::endl;
  return 1;
}
  
char * Apartment::get_name() 
{
  return name;
}

float Apartment::get_bathrooms() 
{
  return bathrooms;
}

float Apartment::get_rent() 
{
  return rent;
}

int Apartment::get_bedrooms() 
{
  return bedrooms;
}

Feature_node* Apartment::get_node() 
{
  return feature_head;
}

