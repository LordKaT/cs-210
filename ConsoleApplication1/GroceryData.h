#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class GroceryData {
public:
    GroceryData();
    ~GroceryData();

    void t_printSearch(string phrase);
    void t_printList();
    void t_printHistogram();

private:
    string t_lowercase(string phrase);
    map<string, int> m_groceryMap;
    map<string, int>::iterator m_mapIter;
};
