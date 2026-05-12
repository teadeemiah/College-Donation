/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor
{
public:
    // Inline parameterized constructor using initializer list.
    Donor(const std::string& aDonorName, int aDonorID)
        : donorName(aDonorName), donorID(aDonorID) {}

    std::string getDonorName() const;

    int getDonorID() const;

    // Overloaded < operator.
    bool operator<(const Donor& other) const;

private:
    std::string donorName;
    int donorID;
};

#endif
