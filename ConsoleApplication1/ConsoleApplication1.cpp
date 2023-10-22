/*
* Jason Pullara
* CS-210
* Project Three
* 10/14/23
*/
#include "GroceryData.h"

using namespace std;

int main() {
    int input = 0;
    string searchInput;
    GroceryData* groceryData = nullptr;

    // GroceryData will throw a string as an error
    // catch it, display the error, and quit.
    try {
        groceryData = new GroceryData();
    }
    catch (string e) {
        cout << "Error: " << e << endl;
        return -1;
    }

    // loop the menu until the user quits
    while (input != 4) {
        cout << "1) Search" << endl;
        cout << "2) List Frequency" << endl;
        cout << "3) Frequency Histogram" << endl;
        cout << "4) Quit" << endl;
        cout << "Selection> ";
        // input validation, if we don't get the proper input, error and repeat
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Numbers only. Try again> ";
        }
        switch (input) {
        case 1: // Search
            cout << "Search term> ";
            cin >> searchInput;
            groceryData->t_printSearch(searchInput);
            break;
        case 2: // List Frequency
            groceryData->t_printList();
            break;
        case 3: // Frequency Histogram
            groceryData->t_printHistogram();
            break;
        default:    // all other options don't process any data so we loop.
                    // quitting doesn't need a special case since it's caught in the while loop
            break;
        }
    }
    return 0;
}
