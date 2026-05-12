/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "CollegeList.h"

#include <iostream>

using namespace std;

// Inserts a college into the map using code as key, name as value.
void CollegeList::addCollege(const string& code, const string& name)
{
    colleges[code] = name;
}

// Given a college code, returns the college's full name.
string CollegeList::getCollegeName(const string& code) const
{
    return colleges.at(code);
}

// Prints all college codes and names using a range-based for loop.
void CollegeList::printColleges() const
{
    for (const auto& entry : colleges)
        cout << entry.first << " : " << entry.second << "\n";
}

// Returns a const reference object
const map<string, string>& CollegeList::getColleges() const
{
    return colleges;
}
