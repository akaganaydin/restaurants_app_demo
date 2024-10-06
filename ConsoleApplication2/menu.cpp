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
        cout << "3. Option 3" << endl;
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
        option3();
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

// Function for option 3
void option3() {
    cout << "You selected Option 3." << endl;
}
