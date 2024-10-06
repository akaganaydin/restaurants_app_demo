#include <iostream>
#include "menu.h"
#include <vector>
#include <string>

using namespace std;

// Function to show the main menu
void showMenu() {
    int choice;

    while (true) { // Loop until a valid input is received
        system("CLS"); // Clear the console before showing the main menu
        cout << "---- Menu ----" << endl;
        cout << "1. View Restaurant Menu" << endl;
        cout << "2. Menu Update" << endl;
        cout << "3. Customer Reviews" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice; // Read user input

        // Check if the input is valid
        if (choice >= 0 && choice <= 3) {
            if (choice == 0) {
                cout << "Exiting..." << endl; // Exit if choice is 0
                break; // Exit the loop
            }
            handleSelection(choice); // Call to handle the valid selection
        }
        else {
            cout << "Invalid selection! Please try again." << endl; // Error message
            system("pause"); // Pause to allow the user to read the message
        }
    }
}

// Function to handle the user's selection
void handleSelection(int choice) {
    // Switch statement to call the appropriate function based on the user's input
    switch (choice) {
    case 1:
        viewMenu();
        break;
    case 2:
        menuUpdate();
        break;
    case 3:
        customerReviews();
        break;
    case 0:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid selection!" << endl;
    }
}

// Function to display the restaurant menu
void viewMenu() {
    system("CLS"); // Clear the console before showing the restaurant menu

    cout << "---- Restaurant Menu ----" << endl;

    // Display food items dynamically from the vector
    cout << "Foods:" << endl;
    for (size_t i = 0; i < foods.size(); ++i) {
        cout << (i + 1) << ". " << foods[i] << endl; // Display food items with their index
    }

    // Display drink items dynamically from the vector
    cout << "\nDrinks:" << endl;
    for (size_t i = 0; i < drinks.size(); ++i) {
        cout << (i + 1) << ". " << drinks[i] << endl; // Display drink items with their index
    }

    cout << "-------------------------" << endl;

    // User input for food and drink selection
    int foodChoice, drinkChoice;

    // Validate food choice
    while (true) {
        cout << "Select a food item (1-" << foods.size() << "): "; // Updated to show current food count
        cin >> foodChoice;
        if (foodChoice >= 1 && foodChoice <= foods.size()) {
            break; // Valid input
        }
        else {
            cout << "Invalid selection! Please try again." << endl;
        }
    }

    // Validate drink choice
    while (true) {
        cout << "Select a drink item (1-" << drinks.size() << "): "; // Updated to show current drink count
        cin >> drinkChoice;
        if (drinkChoice >= 1 && drinkChoice <= drinks.size()) {
            break; // Valid input
        }
        else {
            cout << "Invalid selection! Please try again." << endl;
        }
    }

    // Calculate total price based on user selection
    double total = 0.0;
    // Assuming prices are stored in the string format "Food - $X.XX"
    total += stod(foods[foodChoice - 1].substr(foods[foodChoice - 1].find('$') + 1)); // Get food price
    total += stod(drinks[drinkChoice - 1].substr(drinks[drinkChoice - 1].find('$') + 1)); // Get drink price

    // Display the total price
    cout << "Total price: $" << total << endl;

    cout << "Press 0 to return to the main menu." << endl; // Return to main menu
    int choice;
    cin >> choice; // Read user input
    if (choice == 0) {
        cout << "Returning to main menu..." << endl; // Indicate return to main menu
    }
    else {
        cout << "Invalid choice! Returning to main menu..." << endl; // Invalid selection
    }
}

// List of food items and their prices
vector<string> foods = {
    "Hamburger - $10.99",
    "Pizza - $12.99",
    "Sushi - $15.99",
    "Tacos - $8.99",
    "Pasta - $11.99",
    "Paella - $14.99",
    "Dim Sum - $9.99",
    "Croissant - $3.99",
    "Curry - $13.99",
    "Spring Rolls - $6.99"
};

// List of drink items and their prices
vector<string> drinks = {
    "Sprite - $2.50",
    "Fanta - $2.50",
    "Cola - $2.75",
    "Mojito - $5.50",
    "Tea - $2.00",
    "Lemonade - $2.75",
    "Iced Coffee - $3.50",
    "Wine - $8.00"
};

// Initialize the reviews vector
std::vector<CustomerReview> reviews;

// Function to update the menu
void menuUpdate() {
    system("CLS"); // Clear the console

    int updateChoice;
    cout << "---- Menu Update ----" << endl;
    cout << "1. Add Food or Drink" << endl;
    cout << "2. Remove Food or Drink" << endl;
    cout << "0. Return to Main Menu" << endl; // Return option
    cout << "Choose an option: ";
    cin >> updateChoice;

    if (updateChoice == 1) {
        int typeChoice;
        cout << "1. Add Food" << endl;
        cout << "2. Add Drink" << endl;
        cout << "Choose type to add: ";
        cin >> typeChoice;

        if (typeChoice == 1) { // Add Food
            string newFood;
            cout << "Enter the food name and price (e.g. Pizza - $12.99): ";
            cin.ignore(); // Clear the newline character from input buffer
            getline(cin, newFood);
            foods.push_back(newFood);
            cout << "Food added successfully!" << endl;
        }
        else if (typeChoice == 2) { // Add Drink
            string newDrink;
            cout << "Enter the drink name and price (e.g. Cola - $2.75): ";
            cin.ignore(); // Clear the newline character from input buffer
            getline(cin, newDrink);
            drinks.push_back(newDrink);
            cout << "Drink added successfully!" << endl;
        }
        else {
            cout << "Invalid selection! Please try again." << endl; // Handle invalid type choice
        }
    }
    else if (updateChoice == 2) {
        int typeChoice;
        cout << "1. Remove Food" << endl;
        cout << "2. Remove Drink" << endl;
        cout << "Choose type to remove: ";
        cin >> typeChoice;

        if (typeChoice == 1) { // Remove Food
            if (foods.empty()) {
                cout << "No food items available to remove." << endl; // Check if the vector is empty
            }
            else {
                cout << "Select food item to remove (1-" << foods.size() << "): ";
                int foodChoice;
                cin >> foodChoice;

                if (foodChoice > 0 && foodChoice <= foods.size()) {
                    foods.erase(foods.begin() + (foodChoice - 1)); // Remove selected food
                    cout << "Food removed successfully!" << endl;
                }
                else {
                    cout << "Invalid selection! Please try again." << endl; // Handle invalid selection
                }
            }
        }
        else if (typeChoice == 2) { // Remove Drink
            if (drinks.empty()) {
                cout << "No drink items available to remove." << endl; // Check if the vector is empty
            }
            else {
                cout << "Select drink item to remove (1-" << drinks.size() << "): ";
                int drinkChoice;
                cin >> drinkChoice;

                if (drinkChoice > 0 && drinkChoice <= drinks.size()) {
                    drinks.erase(drinks.begin() + (drinkChoice - 1)); // Remove selected drink
                    cout << "Drink removed successfully!" << endl;
                }
                else {
                    cout << "Invalid selection! Please try again." << endl; // Handle invalid selection
                }
            }
        }
        else {
            cout << "Invalid selection! Please try again." << endl; // Handle invalid type choice
        }
    }
    else if (updateChoice == 0) {
        // Return to Main Menu, no action needed as we just exit the function
    }
    else {
        cout << "Invalid selection! Please try again." << endl; // Handle invalid main option
    }

    system("pause"); // Pause before returning to the menu
}

// Function for customer reviews
void customerReviews() {
    int choice;
    while (true) {
        system("CLS"); // Clear the console
        cout << "---- Customer Reviews ----" << endl;
        cout << "1. Add Review" << endl;
        cout << "2. View Reviews" << endl;
        cout << "3. Delete Review" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomerReview(); // Call the function to add a review
            break;
        case 2:
            viewCustomerReviews(); // Yet to be implemented
            break;
        case 3:
            deleteCustomerReview(); // Yet to be implemented
            break;
        case 0:
            return; // Return to main menu
        default:
            cout << "Invalid selection! Please try again." << endl;
            break;
        }
    }
}

// Function for adding customer reviews
void addCustomerReview() {
    system("CLS"); // Clear the console before showing the review form

    CustomerReview newReview;

    cout << "Enter your name: ";
    cin >> newReview.username; // Get the username

    // Get the rating and validate input
    while (true) {
        cout << "Rate us (0 - 5): ";
        cin >> newReview.rating;
        if (newReview.rating >= 0 && newReview.rating <= 5) {
            break; // Valid input
        }
        else {
            cout << "Invalid rating! Please enter a number between 0 and 5." << endl;
        }
    }

    cout << "Write your comment: ";
    cin.ignore(); // Clear the newline character from input buffer
    getline(cin, newReview.comment); // Get the comment

    // Add the new review to the vector
    reviews.push_back(newReview);
    cout << "Your review has been added successfully!" << endl;

    system("pause"); // Pause before returning to the customer reviews menu
}

// Function to view costumer reviews
void viewCustomerReviews() {
    system("CLS"); // Clear the console

    cout << "---- Customer Reviews ----" << endl;

    // Check if there are any reviews
    if (reviews.empty()) {
        cout << "No reviews available." << endl;
    }
    else {
        // Iterate through and display each review
        for (size_t i = 0; i < reviews.size(); ++i) {
            cout << i + 1 << ". " << reviews[i].username << " rated us "
                << reviews[i].rating << "/5" << endl;
            cout << "Comment: " << reviews[i].comment << endl << endl;
        }
    }

    cout << "Press any key to return to the previous menu..." << endl;
    cin.ignore(); // Clear the newline character from input buffer
    cin.get(); // Wait for a key press
}

// Function for deleting costumer reviews
void deleteCustomerReview() {
    system("CLS"); // Clear the console

    cout << "---- Delete Customer Review ----" << endl;

    // Check if there are any reviews to delete
    if (reviews.empty()) {
        cout << "No reviews available to delete." << endl;
        cout << "Press any key to return to the previous menu..." << endl;
        cin.ignore();
        cin.get();
        return; // Return to the previous menu
    }

    // Display existing reviews
    for (size_t i = 0; i < reviews.size(); ++i) {
        cout << i + 1 << ". " << reviews[i].username << " rated us "
            << reviews[i].rating << "/5" << endl;
        cout << "Comment: " << reviews[i].comment << endl << endl;
    }

    int reviewIndex;
    cout << "Select the number of the review you want to delete (1-"
        << reviews.size() << "): ";
    cin >> reviewIndex;

    // Validate the selected index
    if (reviewIndex >= 1 && reviewIndex <= reviews.size()) {
        reviews.erase(reviews.begin() + (reviewIndex - 1)); // Remove the selected review
        cout << "Review deleted successfully!" << endl;
    }
    else {
        cout << "Invalid selection! No review deleted." << endl;
    }

    cout << "Press any key to return to the previous menu..." << endl;
    cin.ignore(); // Clear the newline character from input buffer
    cin.get(); // Wait for a key press
}
