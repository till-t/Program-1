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
    node* temp = head;
    while(head->next)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete head;
    head = NULL;
}

// @ Dev
// Add apartment to list alphabetically with lower case characters.
// Upper case characters will not work due to ASCII values being 
// greater for upper case letters than they are for lower case 
// letters. This function uses recursion through a wrapper and 
// recursive function.

// Wrapper
bool Apartment_list::add_apartment(Apartment & _apartment)
{
  // Empty list
  if (!head)
  {
    node * temp = new node;
    temp->apartment.copy_entry(_apartment);
    head = temp;
    std::cout << "Empty list Apartment Added!" << std::endl;
    return true;
  }

  return add_apartment(head, _apartment);
}

// Recursive 
bool Apartment_list::add_apartment(node * & head, Apartment & _apartment)
{
  // Base case (we have hit the end of list)
  if(!head)
  {
    node * temp = new node;
    temp->apartment.copy_entry(_apartment);
    head = temp;
    std::cout << "Base Case Apartment Added!" << std::endl;
    return true;
  }

  
  // Alphatbetical add 
  if(strcmp(_apartment.get_name(), head->apartment.get_name()) < 0 )
  {
    std::cout << "Comparison Apartment Added!" << std::endl;
    node * temp = head;
    head = new node;
    head->apartment.copy_entry(_apartment);
    head->next = temp;
    return true;
  }

  return add_apartment(head->next, _apartment);
}

// @ Dev
// Recursive function that displays all nodes in a list.
// This function uses recursion through a wrapper and 
// recursive function.

// Wrapper
bool Apartment_list::display_apartment_list()
{
  // Empty list
  if (!head)
    return false;

  return display_apartment_list(head);
}

// Recursive
bool Apartment_list::display_apartment_list(node* & head)
{
  // Base case
  if(!head)
    return true;

  head->apartment.display();
  return display_apartment_list(head->next);
}

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
    // Covers both nodes that are "sandwhiched" and the tail node case.
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
