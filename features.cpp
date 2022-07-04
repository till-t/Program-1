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

Feature::Feature(char* f, char* r)
{
    feature = f;
    review = r;
}

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

int Feature::display(void)
{
  std::cout << "Feature: " << feature << std::endl;
  std::cout << "Review: " << review << std::endl;
  return 1;
}
  
char * Feature::get_feature() 
{
  return feature;
}

char * Feature::get_review() 
{
  return review;
}





