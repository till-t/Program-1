// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#include <iostream>
#include "List.h"
#include "apartment.h"
#include "features.h"

void get_name(char* & _name);
void get_feature(char* & _feature);
void get_review(char* & _review);
void get_bedrooms(int & _bedrooms);
void get_bathrooms(float & _bathrooms);
void get_rent(float & _rent);
Apartment make_apartment();

const int SIZE = 100;

int main()
{
  Apartment_list list;
  Apartment A1 = make_apartment();

  bool success = list.add_apartment(A1);
  if (success)
    std::cout << "Added successfully!" << std::endl;
  list.display_apartment_list();

  Apartment A2 = make_apartment();
  success = list.add_apartment(A2);
  if (success)
    std::cout << "Added successfully!" << std::endl;

  list.display_apartment_list();

  char* name = new char[SIZE];
  get_name(name);
  list.remove_apartment(name);
  list.display_apartment_list();
  delete [] name;
  
/*
  delete [] feature;
  delete [] name;
  delete [] review;
*/

  return 0;
}

// Function definitions that may go into a header file.
// ======================================================================================

Apartment make_apartment(void)
{
  char* name = new char[SIZE];
  //char* feature = new char[SIZE];
  //char* review  = new char[SIZE];
  int bedrooms;
  float bathrooms;
  float rent;

  get_name(name);
  //get_feature(feature);
  //get_review(review);
  get_bedrooms(bedrooms);
  get_bathrooms(bathrooms);
  get_rent(rent);
  Apartment _apartment(name, bedrooms, rent, bathrooms);
  return _apartment;

}

void get_name(char* & _name)
{
  std::cout << "Please enter the name of the apartment complex: ";
  std::cin.get(_name, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

void get_feature(char * & _feature)
{
  std::cout << "Please enter the feature that you would like to review: ";
  std::cin.get(_feature, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

void get_review(char* & _review)
{
  if (_review != NULL)

  _review = new char[SIZE];
  std::cout << "Please enter the review: ";
  std::cin.get(_review, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

void get_bedrooms(int & _bedrooms)
{
  std::cout << "Please enter the number of bedrooms: ";
  std::cin.clear();
  std::cin >> _bedrooms;
  std::cin.ignore(SIZE, '\n');
}

void get_bathrooms(float & _bathrooms)
{
  std::cout << "Please enter the number of bathrooms: ";
  std::cin.clear();
  std::cin >> _bathrooms;
  std::cin.ignore(SIZE, '\n');
}

void get_rent(float& _rent)
{
  std::cout << "Please enter the cost of rent per month: ";
  std::cin >> _rent;
  std::cin.ignore(SIZE, '\n');
}


