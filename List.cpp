// Tyler Taormina CS163
// June, 2022
// Program 1- Apartment Shopping List

#include "List.h"

// Default constructor
Apartment_list::Apartment_list() : head(NULL){}

// Deconstructor
Apartment_list::~Apartment_list() 
{
    if (!head)
        return;
    node* temp = NULL;
    while(head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// @ Dev
// Add apartment to list alphabetically with lower case characters.
// Upper case characters will not work due to ASCII values being 
// greater for upper case letters than they are for lower case 
// letters. This function uses recursion through a wrapper and 
// recursive function.

// Wrapper function
bool Apartment_list::add_apartment(Apartment & _apartment)
{
  // Empty list
  if (!head)
  {
    node * temp = new node;
    temp->apartment.copy_entry(_apartment);
    head = temp;
    head->next = nullptr;
    //std::cout << "Empty list Apartment Added!" << std::endl;
    return true;
  }

  return add_apartment(head, _apartment);
}

// Recursive function
bool Apartment_list::add_apartment(node * & head, Apartment & _apartment)
{
  // Base case (we have hit the end of list)
  if(!head)
  {
    node * temp = new node;
    temp->apartment.copy_entry(_apartment);
    head = temp;
    head->next = nullptr;
    //std::cout << "Base Case Apartment Added!" << std::endl;
    return true;
  }

  // Name is already in list
  if(strcmp(_apartment.get_name(), head->apartment.get_name()) == 0 )
      return false;

  // Alphatbetical add 
  if(strcmp(_apartment.get_name(), head->apartment.get_name()) < 0 )
  {
    //std::cout << "Comparison Apartment Added!" << std::endl;
    node * temp = head;
    head = new node;
    head->apartment.copy_entry(_apartment);
    head->next = temp;
    return true;
  }

  // Recursive call to next node
  return add_apartment(head->next, _apartment);
}

// @ Dev
// Recursive function that displays all nodes in a list.
// This function uses recursion through a wrapper and 
// recursive function.

// Wrapper function
bool Apartment_list::display_apartment_list()
{
  // Empty list
  if (!head)
    return false;

  return display_apartment_list(head);
}

// Recursive function
bool Apartment_list::display_apartment_list(node* & head)
{
  // Base case
  if(!head)
    return true;

  std::cout << std::endl;
  std::cout << "==========================================" << std::endl;
  head->apartment.display();
  std::cout << std::endl;
  return display_apartment_list(head->next);
}

// @Dev
// Removes an apartment based on a match of the name. 
// Matching names is case sensitive at the moment. 
// Consider adding a check of ascii values during input 
// and convert to either lower or upper case for accurate 
// matching. 
bool Apartment_list::remove_apartment(char * _name) 
{  
    // Five cases 
    // ========================================
    // List is empty
    // Head is the apartment 
    // Apartment is in between two other Apartments
    // Tail is apartment
    // Apartment is not in list

    // Empty list
    if (!head)
        return false;
    
    // Head node holds apartment
    if(strcmp(head->apartment.get_name(), _name) == 0)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        return true;
    }

    // Search the list for the node;
    // Covers both nodes that are "sandwiched" and the tail node case.
    node * current = head;
    node * prev = head;
    while(current->next)
    {
        prev = current;
        current = current->next;
       if (strcmp(current->apartment.get_name(), _name) == 0)
        {
            prev->next = current->next;
            delete current;
            return true;
        }
    }
    
    //Apartment name not in list.
    return false;
}

// Pass the name of the apartment that we want to add a feature for 
// along with a feature object. Returns true if the apartment is found 
// and false if not. 
// Returns false if empty of if character array is set to null.
    
bool Apartment_list::add_feature(char * _name, Feature & _feature)
{
    if (!head || !_name)
        return false;
    
    node *temp = head;
    while(temp)
    {
        if(strcmp(temp->apartment.get_name(), _name) == 0)
        {
            temp->apartment.add_feature(_feature);
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool Apartment_list::display_feature_list(char * _name)
{
    bool success = false;
    if (!head || !_name)
        return success;
    
    node *temp = head;
    while(temp)
    {
        if(strcmp(temp->apartment.get_name(), _name) == 0)
        {
            //std::cout << "Found Apartment" << std::endl;
            temp->apartment.display_feature_list();
            success = true;
        }
        temp = temp->next;
    }

    return success;
}

bool Apartment_list::display_feature_specific(char * _feature_to_find)
{
    bool success = false;
    if (!head || !_feature_to_find)
        return success;
    
    node *temp = head;
    while(temp)
    {
        if(temp->apartment.has_feature(_feature_to_find))
        {
            //std::cout << "Found feature" << std::endl;
            std::cout << "==========================================" << std::endl;
            temp->apartment.display();
            std::cout << std::endl;
            success = true;
        }
        temp = temp->next;
    }

    return success;
}
