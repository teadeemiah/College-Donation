/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"

#include <iostream>
#include <iomanip>

using namespace std;

int DonationManager::addDonor(const string& donorName)
{
    int assignedID = nextDonorID;
    donors.insert(Donor(donorName, assignedID));
    ++nextDonorID;
    return assignedID;
}

void DonationManager::addCollege(const string& collegeCode,
                                  const string& collegeName)
{
    colleges.addCollege(collegeCode, collegeName);
}

void DonationManager::addDonation(const string& donorName,
                                   const string& collegeCode,
                                   double amount)
{
    addDonor(donorName);
    donations.addDonation(Donation(donorName, collegeCode, amount));
}

void DonationManager::printColleges() const
{
    colleges.printColleges();
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();

    for (const auto& entry : collegeMap)
    {
        // entry.first = college code, entry.second = college name
        cout << "\n" << entry.first << " : " << entry.second << "\n";

        DonationNode* current = donations.getFirst();
        while (current != nullptr)
        {
            if (current->data.getCollegeCode() == entry.first)
            {
                cout << "  " << current->data.getDonorName()
                     << "  $" << fixed << setprecision(2)
                     << current->data.getAmount() << "\n";
            }
            current = current->next;
        }
    }
}

void DonationManager::printDonationsByDonor() const
{
    for (const Donor& donor : donors)
    {
        DonationNode* current = donations.getFirst();
        while (current != nullptr)
        {
            if (current->data.getDonorName() == donor.getDonorName())
            {
                cout << donor.getDonorID()
                     << "  " << donor.getDonorName()
                     << "  " << current->data.getCollegeCode()
                     << " - " << colleges.getCollegeName(
                                    current->data.getCollegeCode())
                     << "  $" << fixed << setprecision(2)
                     << current->data.getAmount() << "\n";
                break; // Each donor makes only one donation.
            }
            current = current->next;
        }
    }
}

void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();

    for (const auto& entry : collegeMap)
    {
        cout << entry.first << " : " << entry.second
             << "  Total: $" << fixed << setprecision(2)
             << getCollegeTotal(entry.first) << "\n";
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const Donor& donor : donors)
    {
        cout << donor.getDonorID()
             << "  " << donor.getDonorName()
             << "  Total: $" << fixed << setprecision(2)
             << getDonorTotal(donor.getDonorName()) << "\n";
    }
}

void DonationManager::printStatistics() const
{
    cout << "Number of donors:    " << donors.size()                    << "\n";
    cout << "Number of colleges:  " << colleges.getColleges().size()    << "\n";
    cout << "Number of donations: " << donations.getNumOfDonations()    << "\n";
}

void DonationManager::printHighestDonor() const
{
    string highestName;
    double highestTotal = -1.0;

    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > highestTotal)
        {
            highestTotal = total;
            highestName  = donor.getDonorName();
        }
    }

    cout << "Highest donor: " << highestName
         << "  $" << fixed << setprecision(2) << highestTotal << "\n";
}

void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();

    string highestCode;
    double highestTotal = -1.0;

    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        if (total > highestTotal)
        {
            highestTotal = total;
            highestCode  = entry.first;
        }
    }

    cout << "College with highest total: "
         << highestCode << " - " << colleges.getCollegeName(highestCode)
         << "  $" << fixed << setprecision(2) << highestTotal << "\n";
}

double DonationManager::getDonorTotal(const string& donorName) const
{
    double total  = 0.0;
    DonationNode* current = donations.getFirst();

    while (current != nullptr)
    {
        if (current->data.getDonorName() == donorName)
        {
            total += current->data.getAmount();
            break; 
        }
        current = current->next;
    }

    return total;
}

double DonationManager::getCollegeTotal(const string& collegeCode) const
{
    double total  = 0.0;
    DonationNode* current = donations.getFirst();

    while (current != nullptr)
    {
        if (current->data.getCollegeCode() == collegeCode)
            total += current->data.getAmount();

        current = current->next;
    }

    return total;
}
