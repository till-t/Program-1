// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List


// Comments for .cpp files
// - Algorithms used
// - How you are working with the data structure
// - Aimed at the programmer maintaining the software

#include "apartment.h"

//Default constructor
Apartment::Apartment() : name(NULL), bedrooms(0), rent(0), bathrooms(0) {} 

//Deconstructor
Apartment::~Apartment()
{
  if (name != NULL)
    delete [] name;
  delete_feature_list();
}

//Parameterized constructor. 
Apartment::Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms)
{
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
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
  
void Apartment::set_apartment(char* _name, int _bedrooms, float _rent, float _bathrooms)
{
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  bedrooms = _bedrooms;
  rent = _rent;
  bathrooms = _bathrooms;
  feature_head = NULL;
}

// Getters
// ==================================================
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

// Section: Handles Feature linked list
// ==================================================

// Release all dynamic memory
void Apartment::delete_feature_list() 
{
  if (!feature_head)
        return;
    Feature_node* temp = NULL;
    while(feature_head)
    {
        temp = feature_head->next;
        delete feature_head;
        feature_head = temp;
    }

}

// Add a new apartment by passing info for apartment as arguments.
// Return an error if the apartment is already in the list.
// Recursive function
bool Apartment::add_feature(Feature & _feature)
{
  // Empty list
  if (!feature_head)
  {
    Feature_node * temp = new Feature_node;
    temp->feature.copy_entry(_feature);
    feature_head = temp;
    feature_head->next = nullptr;
    std::cout << "Empty list Feature Added!" << std::endl;
    return true;
  }

  return add_feature(feature_head, _feature);
}
bool Apartment::add_feature(Feature_node * & head, Feature & _feature)
{
  // Base case (we have hit the end of list)
  if(!head)
  {
    Feature_node * temp = new Feature_node;
    temp->feature.copy_entry(_feature);
    head = temp;
    head->next = nullptr;
    std::cout << "Base Case Feature Added!" << std::endl;
    return true;
  }

  // Feature is already in list
  if(strcmp(_feature.get_feature(), head->feature.get_feature()) == 0 )
      return false;

  // Alphatbetical add 
  if(strcmp(_feature.get_feature(), head->feature.get_feature()) < 0 )
  {
    std::cout << "Comparison Feature Added!" << std::endl;
    Feature_node * temp = head;
    head = new Feature_node;
    head->feature.copy_entry(_feature);
    head->next = temp;
    return true;
  }

  // Recursive call to next node
  return add_feature(head->next, _feature);
}

//Display all apartments in the list
// Recursive function
bool display_feature_list();
bool display_feature_list(Feature_node* & head);

// Remove an apartment from the list.
// Pass the name of the apartment to be removed as an argument.
bool remove_feature(char * _name); // Iterative function







