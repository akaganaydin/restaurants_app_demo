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
void customerReviews();
void addCustomerReview();
void viewCustomerReviews();
void deleteCustomerReview();

extern std::vector<std::string> foods; // Food items vector
extern std::vector<std::string> drinks; // Drink items vector

// Structure to hold customer reviews
struct CustomerReview {
    std::string username; // Customer's name
    double rating;        // Rating between 0 to 5
    std::string comment;  // Customer's comment
};

// Vector to hold all customer reviews
extern std::vector<CustomerReview> reviews; // Vector to store customer reviews

#endif
