// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List


// Requirements for test plan
// - 
//

#include <iostream>
#include "List.h"
#include "apartment.h"
#include "features.h"

void displayMenu(int& menu_choice);
void processChoice (bool& flag, int menu_choice, Apartment_list & _list);
void get_input(char* & _name);
void get_input(char* & _feature);
void get_input(char* & _review);
void get_input(int & _bedrooms);
void get_input(float & _bathrooms);
void get_input(float & _rent);
void make_apartment(Apartment & _apartment);
void make_feature(Feature& _feature);

const int SIZE = 100;

int main()
{
  Apartment_list list;
  int menu_choice;
  bool flag = true;
  
  while(flag)
    {
        displayMenu(menu_choice);
        processChoice(flag, menu_choice, list);
    }

  return 0;
}

// Function definitions that may go into a header file.
// ======================================================================================


//Displays the menu of functions for the user to choose from.
void displayMenu(int& menu_choice) {
    std::cout << "==================================================================\n";
    std::cout << "                         MENU" << std::endl;
    std::cout << "==================================================================\n";

    std::cout << "1) Add an apartment.\n";
    std::cout << "2) Remove an apartment.\n";
    std::cout << "3) Display apartments.\n";
    std::cout << "4) Add a feature for an apartment.\n";
    std::cout << "5) Display apartments with feature.\n";
    std::cout << "6) Display all features for an apartment.\n";
    std::cout << "7) Exit.\n";
    std::cout << "Enter: ";
    std::cin >> menu_choice;
    std::cin.ignore(SIZE, '\n');
    if (menu_choice > 7 || menu_choice < 1) 
    {
      std::cout << "Invalid Entry. Please enter a number from the options list provided.\n\n\n\n" << std::endl;
        displayMenu(menu_choice);
    }
}

//Provides option processing for the menu 
void processChoice (bool& flag, int menu_choice, Apartment_list & _list)
{
  //Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 1:
        {
          Apartment _apartment;
          make_apartment(_apartment);

          bool success = _list.add_apartment(_apartment);
          if (!success)
            std::cout << "Error encountered." << std::endl;
          break;
        }

      case 2: 
        {
        char* name = new char[SIZE];
        std::cout << "Please enter the name of the apartment complex that we want to remove: ";
        get_input(name);
        bool success = _list.remove_apartment(name);
        std::cout << "Removing apartment..." << std::endl;
        if (!success)
          std::cout << "Error encountered. Error cases are an empty list, the character array is set to null, or the apartment is not in the list." << std::endl;


        delete [] name;
        break;
        }

      case 3:
        {
          std::cout << "Here is all the apartments we have so far: ";
          std::cout << std::endl;
          _list.display_apartment_list();
          break;
        }

      case 4: 
        {
          Feature _feature;
          std::cout << "Please enter the name of the apartment complex that you would like to add a feature for: ";
          char* name = new char[SIZE];
          get_input(name);
          make_feature(_feature);
          std::cout << "Adding feature..." << std::endl;
          bool success = _list.add_feature(name, _feature);
          if (!success)
            std::cout << "Error encountered. Error cases are an empty list or the character array set to null." << std::endl;

          delete [] name;
          break;
        }

      case 5: 
        {
          std::cout << "Please enter the name of the feature that you would like in your apartment: ";
          char* name = new char[SIZE];
          get_input(name);
          std::cout << std::endl;
          std::cout << "These apartments have a " << name << std::endl;
          bool success = _list.display_feature_specific(name);
          if (!success)
            std::cout << "Error encountered. Error cases are an empty list, character array set to null, or the feature is not included with any apartment." << std::endl;
          delete [] name;

          break;
        }

      case 6: 
        {
          std::cout << "Please enter the name of the apartment complex to see its features: ";
          char* name = new char[SIZE];
          get_input(name);
          std::cout << std::endl;
          std::cout << "Here are " << name << " features and reviews." << std::endl;
          bool success = _list.display_feature_list(name);
          if (!success)
            std::cout << "Error encountered. Error cases are an empty list, character array set to null, or the feature is not included with any apartment." << std::endl;
          delete [] name;

          break;
        }


      case 7: 
            {
            std::cout << "Are you sure you want to exit?" << std::endl;
            proceed = no;
            break;
            }

      default:
          break;
    }

    if (proceed == no)
    {
      std::cout << "Enter 0 to end program.\n" << std::endl;
      std::cout << "Enter any other number to continue program.\n" << std::endl;
      std::cin >> flag;
      std::cin.ignore(SIZE, '\n');
    }
}

void make_apartment(Apartment & _apartment)
{
  char* name = new char[SIZE];
  //char* feature = new char[SIZE];
  //char* review  = new char[SIZE];
  int bedrooms;
  float bathrooms;
  float rent;
  int air_conditioning;

  std::cout << "Please enter the name of the apartment complex: ";
  get_input(name);
  //std::cout << "Please enter the feature that you would like to review: ";
  //get_feature(feature);
  //std::cout << "Please enter the review: ";
  //get_review(review);
  std::cout << "Please enter the number of bedrooms: ";
  get_input(bedrooms);
  std::cout << "Please enter the number of bathrooms: ";
  get_input(bathrooms);
  std::cout << "Please enter the cost of rent per month: ";
  get_input(rent);
  std::cout << "Please enter whether the apartment has air conditioning or not. (1 for yes, 0 for no): ";
  get_input(air_conditioning);
  _apartment.set_apartment(name, bedrooms, rent, bathrooms, air_conditioning);
  delete [] name;
}

void make_feature(Feature& _feature)
{
  char* feature = new char[SIZE];
  char* review  = new char[SIZE];
  std::cout << "Please enter the feature that you would like to review: ";
  get_input(feature);
  std::cout << "Please enter the review: ";
  get_input(review);
  _feature.set_feature(feature, review);
  delete [] feature;
  delete [] review;
}


void get_input(char* & _value)
{
  std::cin.get(_value, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
}

void get_input(int & _value)
{
  std::cin >> _value;
  std::cin.ignore(SIZE, '\n');
}

void get_input(float & _value)
{
  std::cin >> _value;
  std::cin.ignore(SIZE, '\n');
}

