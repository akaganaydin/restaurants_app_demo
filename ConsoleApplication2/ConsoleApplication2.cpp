// menu.cpp
#include <iostream>  // Include the input-output stream library

   // Function to display the main menu
void showMainMenu() {
    std::cout << "Main Menu:\n";  // Print main menu header
    std::cout << "1. Show Sub Menu\n";  // Option to show the sub menu
    std::cout << "2. Exit\n";  // Option to exit
    std::cout << "Please make your selection: ";  // Prompt user for selection
}

// Function to display the sub menu
void showSubMenu() {
    std::cout << "Sub Menu:\n";  // Print sub menu header
    std::cout << "1. Operation A\n";  // Option for Operation A
    std::cout << "2. Operation B\n";  // Option for Operation B
    std::cout << "3. Show Main Menu\n";  // Option to return to the main menu
    std::cout << "Please make your selection: ";  // Prompt user for selection
}

// Function to handle the main menu selection
void handleMainMenuChoice(int choice) {
    switch (choice) {
    case 1:
        showSubMenu();  // Show the sub menu
        break;
    case 2:
        std::cout << "Exiting...\n";  // Exit message
        exit(0);  // Exit the program
    default:
        std::cout << "Invalid selection! Please try again.\n";  // Invalid selection message
    }
}

// Function to handle the sub menu selection
void handleSubMenuChoice(int choice) {
    switch (choice) {
    case 1:
        std::cout << "Operation A executed.\n";  // Message for Operation A
        break;
    case 2:
        std::cout << "Operation B executed.\n";  // Message for Operation B
        break;
    case 3:
        std::cout << "Returning to Main Menu...\n";  // Message for returning to the main menu
        break;
    default:
        std::cout << "Invalid selection! Please try again.\n";  // Invalid selection message
    }
}
