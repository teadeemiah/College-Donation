/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATIONLIST_H
#define DONATIONLIST_H

#include "Donation.h"

#include <string>

struct DonationNode
{
    Donation data;
    DonationNode* next;

    DonationNode(const Donation& donation)
        : data(donation), next(nullptr) {}
};

class DonationList
{
public:
    // Inline default constructor
    DonationList() : first(nullptr), last(nullptr), numOfDonations(0) {}

    // Adds a new Donation node to the end of the list.
    int addDonation(const Donation& donation);

    // Returns the number of donations.
    int getNumOfDonations() const;

    // Returns a pointer to the first node 
    DonationNode* getFirst() const;

    // Returns a pointer to the last node
    DonationNode* getLast() const;

    // Destructor
    ~DonationList();

private:
    DonationNode* first;
    DonationNode* last;
    int numOfDonations;
};

#endif
