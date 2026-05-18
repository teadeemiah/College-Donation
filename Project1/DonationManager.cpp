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

//New PartB overload - locate the donor associated with the given donor ID, 
//retrieve the donor’s name, create a Donation object, and add it to the list of donations
void DonationManager::addDonation(int donorID,
    const string& collegeCode,
    double amount)
{
    string donorName = "";

    for (const Donor& donor : donors)
    {
        if (donor.getDonorID() == donorID)
        {
            donorName = donor.getDonorName();
            break;
        }
    }
}

void DonationManager::printColleges() const
{
	const map<string, string>& collegeMap = colleges.getColleges();

	for (const auto& entry : collegeMap)
        cout << "\t" << entry.first << " - " << entry.second << "\n";
}

void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();


    for (const auto& entry : collegeMap)
    {
        // entry.first = college code, entry.second = college name
        cout << "\t" << entry.first << " - " << entry.second << "\n";

		bool hasDonations = false;
        DonationNode* current = donations.getFirst();

        while (current != nullptr)
        {
            if (current->data.getCollegeCode() == entry.first)
            {
                cout << "\t\t" << current->data.getDonorName()
                     << " | Amount: $" << fixed << setprecision(2)
                     << current->data.getAmount() << "\n";
                hasDonations = true;
            }
            current = current->next;
        }

        if (!hasDonations)
			cout << "\t\t(No donation)" << endl;
    }
}

void DonationManager::printDonationsByDonor() const
{
    for (const Donor& donor : donors)
    {
        cout << "\tID " << donor.getDonorID()
            << " - " << donor.getDonorName() << endl;

        DonationNode* current = donations.getFirst();
        while (current != nullptr)
        {
            if (current->data.getDonorName() == donor.getDonorName())
            {
				string code = current->data.getCollegeCode();

                cout << "\t\t" << colleges.getCollegeName(code)
                    << " (" << code << ")" << endl;
				cout << "\t\tAmount: $" << fixed << setprecision(2)
					<< current->data.getAmount() << "\n";
                break; 
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
        cout << "\t" << entry.first << " - " << entry.second << endl;
        cout << "\t\tTotal donation amount: $" << fixed << setprecision(2)
             << getCollegeTotal(entry.first) << "\n";
    }
}

void DonationManager::printTotalsByDonor() const
{
    for (const Donor& donor : donors)
    {
		cout << "\t(ID " << donor.getDonorID() << ") "
             << donor.getDonorName() << " | $"
             << fixed << setprecision(2)
             << getDonorTotal(donor.getDonorName()) << "\n";
    }
}

void DonationManager::printStatistics() const
{
    cout << "\tNumber of donors: " << donors.size()                    << "\n";
    cout << "\tNumber of colleges: " << colleges.getColleges().size()    << "\n";
    cout << "\tNumber of donations: " << donations.getNumOfDonations()    << "\n";
}

void DonationManager::printHighestDonor() const
{
    double highestTotal = -1.0;

    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > highestTotal)
        {
            highestTotal = total;
        }
    }

    cout << "\tHighest donor(s): " << endl;

    for (const Donor& donor : donors)
    {
        if (getDonorTotal(donor.getDonorName()) == highestTotal)
            cout << "\t\t" << fixed << setprecision(2) << donor.getDonorName() << "\n";
    }

	cout << "\t\tHighest amount donated: $" << fixed << setprecision(2) << highestTotal << "\n";
}

void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();

    double highestTotal = -1.0;

    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        if (total > highestTotal)
            highestTotal = total;
    }

    cout << "\tCollege(s) with highest total donation:" << endl;

    for (const auto& entry : collegeMap)
    {
        if (getCollegeTotal(entry.first) == highestTotal)
            cout << "\t\t" << entry.second << " (" << entry.first << ")\n";
    }
    
	cout << "\t\tHighest total received: $" << fixed << setprecision(2) << highestTotal << "\n";
         
}

double DonationManager::getDonorTotal(const string& donorName) const
{
    DonationNode* current = donations.getFirst();

    while (current != nullptr)
    {
        if (current->data.getDonorName() == donorName)
            return current->data.getAmount();
        current = current->next;
    }

    return 0.0;
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
