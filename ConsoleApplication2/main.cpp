#include <iostream>
#include "menu.h"

using namespace std;

int main() {
    int choice;  // Variable to store the user's selection

    // Loop until the user chooses to exit (i.e., choice == 0)
    do {
        showMenu();  // Display the menu
        cin >> choice;  // Get the user's input
        handleSelection(choice);  // Process the input and call the appropriate function
    } while (choice != 0);  // Continue until the user enters 0 to exit

    return 0;  // End the program
}
