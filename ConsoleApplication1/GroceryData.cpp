#include "GroceryData.h"

// Constructor will load data and create a backup file
GroceryData::GroceryData() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    ofstream backupFile("frequency.dat");
    string line;

    if (!inputFile.is_open())
        throw "Cannot open input file.";
    if (!backupFile.is_open())
        throw "Cannot open backup file.";

    // scan through each line of the file and place it in a map
    // this way we aren't constantly scanning through a file when
    // performing operations
    while (getline(inputFile, line)) {
        // convert everything to lowercase for ease of use
        line = this->t_lowercase(line);
        // check to see if the item is already in the map
        this->m_mapIter = this->m_groceryMap.find(line);
        if (this->m_mapIter == this->m_groceryMap.end())
            this->m_groceryMap.insert({ line, 1 }); // if not, add it to the map
        else
            this->m_groceryMap[line]++; // otherwise increment the count
    }
    inputFile.close();

    this->m_mapIter = this->m_groceryMap.begin();

    // create the backup file from the mapped data
    while (this->m_mapIter != this->m_groceryMap.end()) {
        backupFile << this->m_mapIter->first << " " << this->m_mapIter->second << endl;
        this->m_mapIter++;
    }

    backupFile.close();
}

GroceryData::~GroceryData() { }

// searches for an item and prints the amount
void GroceryData::t_printSearch(string phrase) {
    // convert the phrase to lowercase to match the map key.
    string lowercasePhrase = this->t_lowercase(phrase);
    int iCount = 0; // we need this in case the map search comes up empty
    // find the phrase in the map
    this->m_mapIter = this->m_groceryMap.find(lowercasePhrase);
    if (this->m_mapIter != this->m_groceryMap.end())
        iCount = this->m_mapIter->second; // if we find it, set the count
    cout << phrase << " " << iCount << endl; // print the count
}

// this is just a basic print function similar to how we wrote the backup file
void GroceryData::t_printList() {
    this->m_mapIter = this->m_groceryMap.begin();
    while (this->m_mapIter != this->m_groceryMap.end()) {
        cout << this->m_mapIter->first << " " << this->m_mapIter->second << endl;
        this->m_mapIter++;
    }
}

// similar to above only we do some slightly fancier string formatting to print a histogram
void GroceryData::t_printHistogram() {
    this->m_mapIter = this->m_groceryMap.begin();
    while (this->m_mapIter != this->m_groceryMap.end()) {
        cout << this->m_mapIter->first << " " << string(this->m_mapIter->second, '*') << endl;
        this->m_mapIter++;
    }
}

// utility function to convert std::string's to all lowercase
// may not work in all utf-8 circumstances... probably doesn't work with kanji or mandarin characters
string GroceryData::t_lowercase(string s) {
    string lower;
    lower.resize(s.size());
    transform(s.begin(), s.end(), lower.begin(), tolower);
    return lower;
}
