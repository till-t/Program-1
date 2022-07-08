// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#include "features.h"

//Default constructor
Feature::Feature() : feature(NULL), review(NULL) {}

//Deconstructor
Feature::~Feature()
{
  if (feature != NULL)
    delete [] feature;

 if (review != NULL)
    delete [] review;
}

// Parameterized constructor
Feature::Feature(char* _feature, char* _review)
{
  review = new char[strlen(_review) + 1];
  strcpy(review, _review);
  feature = new char[strlen(_feature) + 1];
  strcpy(feature, _feature);
}

// Pass character arrays as arguments which will be used
// change the values that are held in our Feature object.
void Feature::set_feature(char* _feature, char* _review)
{
  review = new char[strlen(_review) + 1];
  strcpy(review, _review);
  feature = new char[strlen(_feature) + 1];
  strcpy(feature, _feature);
}

// Copy's a feature into another Feature object. Used
// when inserting a Feature into the linked list.
int Feature::copy_entry(const Feature & copy_from)
{
  if (feature)
    delete [] feature;

  if (review)
    delete [] review;

  feature = new char[strlen(copy_from.feature) + 1];
  strcpy(feature, copy_from.feature);

  review = new char[strlen(copy_from.review) + 1];
  strcpy(review, copy_from.review);
 
  return 1;
}

// Displays Feature object to the console.
int Feature::display(void)
{
  std::cout << "Feature: " << feature << std::endl;
  std::cout << "Review: " << review << std::endl;
  return 1;
}
  
// Getters to access private values when necessary
char * Feature::get_feature() 
{
  return feature;
}

char * Feature::get_review() 
{
  return review;
}

