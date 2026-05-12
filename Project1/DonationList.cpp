/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationList.h"

int DonationList::addDonation(const Donation& donation)
{
    DonationNode* newNode = new DonationNode(donation);

    if (first == nullptr)
    {
        // List was empty
        first = newNode;
        last  = newNode;
    }
    else
    {
        // List has nodes
        last->next = newNode;
        last       = newNode;
    }

    ++numOfDonations;
    return numOfDonations;
}

int DonationList::getNumOfDonations() const
{
    return numOfDonations;
}

DonationNode* DonationList::getFirst() const
{
    return first;
}

DonationNode* DonationList::getLast() const
{
    return last;
}

//destructor
DonationList::~DonationList()
{
    DonationNode* current = first;

    while (current != nullptr)
    {
        DonationNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    // Reset to empty-list state.
    first           = nullptr;
    last            = nullptr;
    numOfDonations  = 0;
}
