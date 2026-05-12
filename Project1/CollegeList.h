/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef COLLEGELIST_H
#define COLLEGELIST_H

#include <map>
#include <string>

class CollegeList
{
public:
    // Inserts a college into the map using code as key, name as value.
    void addCollege(const std::string& code, const std::string& name);

    // Given a college code, returns the college's full name.
    std::string getCollegeName(const std::string& code) const;

    // Prints all college codes and names using a range-based for loop.
    void printColleges() const;

    // Returns a const reference object
    const std::map<std::string, std::string>& getColleges() const;

private:
    std::map<std::string, std::string> colleges;
};

#endif
