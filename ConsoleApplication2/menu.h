#ifndef MENU_H
#define MENU_H

#include <vector> // for vectors
#include <string> // for strings


// Function to display the menu
void showMenu();

// Function to handle the user's menu selection
void handleSelection(int choice);

// Functions corresponding to each menu option
void viewMenu();
void menuUpdate();
void option3();

extern std::vector<std::string> foods; // Food items vector
extern std::vector<std::string> drinks; // Drink items vector

#endif
