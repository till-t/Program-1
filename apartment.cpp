// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List


// Comments for .cpp files
// - Algorithms used
// - How you are working with the data structure
// - Aimed at the programmer maintaining the software

#include "apartment.h"

//Default constructor
Apartment::Apartment() : name(NULL), bedrooms(0), rent(0), bathrooms(0), air_conditioning(0) {} 

//Deconstructor
Apartment::~Apartment()
{
  if (name != NULL)
    delete [] name;
  delete_feature_list();
}

//Parameterized constructor. 
Apartment::Apartment(char* _name, int _bedrooms, float _rent, float _bathrooms, int _air_conditioning)
{
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  bedrooms = _bedrooms;
  rent = _rent;
  bathrooms = _bathrooms;
  air_conditioning = _air_conditioning;
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
  air_conditioning = copy_from.air_conditioning;
  return 1;
}

//Displays information for each apartment to the console.
int Apartment::display(void)
{
  std::cout << "Name: " << name << std::endl;
  std::cout << "Number of bedrooms: " << bedrooms << std::endl;
  std::cout << "Number of bathrooms: " << bathrooms << std::endl;
  std::cout << "Cost of rent: $" << round(rent) << std::endl;
  if (air_conditioning > 0)
    std::cout << "Air Conditioning: Yes"  << std::endl;
  else
    std::cout << "Air Conditioning: No"  << std::endl;
  return 1;
}
  
// Used to make an apartment object. 
// Takes data for all member values and passes them to local apartment object.
bool Apartment::set_apartment(char* _name, int _bedrooms, float _rent, float _bathrooms, int _air_conditioning)
{
  if(!_name)
    return false;
  name = new char[strlen(_name) + 1];
  strcpy(name, _name);
  bedrooms = _bedrooms;
  rent = _rent;
  bathrooms = _bathrooms;
  air_conditioning = _air_conditioning;
  feature_head = NULL;
  return true;
}

// Used for rounding the rent cost to 2 decimal places for dollar amount formatting.
float Apartment::round(float arg)
{
  float value = (int) (arg * 100 + .5);
  return (float)value / 100;
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
    //std::cout << "Empty list Feature Added!" << std::endl;
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
    //std::cout << "Base Case Feature Added!" << std::endl;
    return true;
  }

  // Feature is already in list
  if(strcmp(_feature.get_feature(), head->feature.get_feature()) == 0 )
      return false;

  // Alphatbetical add 
  if(strcmp(_feature.get_feature(), head->feature.get_feature()) < 0 )
  {
    //std::cout << "Comparison Feature Added!" << std::endl;
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
bool Apartment::display_feature_list()
{
  // Empty list
  if (!feature_head)
    return false;

  return display_feature_list(feature_head);
}

bool Apartment::display_feature_list(Feature_node* & head)
{
  // Base case
  if(!head)
    return true;

  std::cout << "==============================" << std::endl;
  head->feature.display();
  std::cout << std::endl;
  return display_feature_list(head->next);
}

int Apartment::has_feature(char * to_find) 
{
  // Empty list
  if (!feature_head)
        return false;

  //std::cout << "Looking for feature" << std::endl;

    Feature_node* temp = feature_head;
    while(temp)
    {
      if (strcmp(temp->feature.get_feature(), to_find) == 0)
         return 1;
      temp = temp->next;
    }

    return 0;
}
// Remove an apartment from the list.
// Pass the name of the apartment to be removed as an argument.
// Iterative function
int Apartment::remove_feature(char * _name)
{
    // Five cases 
    // ========================================
    // List is empty
    // Head is the apartment 
    // Apartment is in between two other Apartments
    // Tail is apartment
    // Apartment is not in list

    // Empty list
    if (!feature_head)
        return 0;
    
    // Head node holds apartment
    if(strcmp(feature_head->feature.get_feature(), _name) == 0)
    {
        Feature_node * temp = feature_head->next;
        delete feature_head;
        feature_head = temp;
        return 1;
    }

    // Search the list for the node;
    // Covers both nodes that are "sandwiched" and the tail node case.
    Feature_node * current = feature_head;
    Feature_node * prev = feature_head;
    while(current->next)
    {
        prev = current;
        current = current->next;
       if (strcmp(current->feature.get_feature(), _name) == 0)
        {
            prev->next = current->next;
            delete current;
            return 1;
        }
    }
    
    //Apartment name not in list.
    return 0;
}







