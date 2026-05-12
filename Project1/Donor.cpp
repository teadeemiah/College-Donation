/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "Donor.h"

using namespace std;

// Returns the donor's name.
string Donor::getDonorName() const
{
    return donorName;
}

// Returns the donor's ID number.
int Donor::getDonorID() const
{
    return donorID;
}

bool Donor::operator<(const Donor& other) const
{
    return donorID < other.donorID;
}
