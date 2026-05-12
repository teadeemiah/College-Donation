/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATIONMANAGER_H
#define DONATIONMANAGER_H

#include "Donor.h"
#include "CollegeList.h"
#include "DonationList.h"

#include <string>
#include <set>
#include <map>

const int START_ID = 3000;

class DonationManager
{
public:
    DonationManager() : nextDonorID(START_ID) {}

	//add new donor with new ID, return the assigned ID.
    int  addDonor(const std::string& donorName);

    // One statement.
    void addCollege(const std::string& collegeCode,
                    const std::string& collegeName);

    // Adds the donor to the donors set AND the donation to the donation list.
    void addDonation(const std::string& donorName,
                     const std::string& collegeCode,
                     double amount);

    void printColleges() const;

    // for each college, prints the college code, the college name, list all donors and amounts donated to a  college.
    void printDonationsByCollege() const;

    // Print ID, name, college code, college name, and amount.
    void printDonationsByDonor() const;

    // For every college, print code and total donations received.
    void printTotalsByCollege() const;

    // For every donor, print ID, name, and total amount they donated.
    void printTotalsByDonor() const;

    // Print number of donors, colleges, and donations.
    void printStatistics() const;

    void printHighestDonor() const;

    void printCollegeWithHighestTotal() const;

private:
    std::set<Donor> donors;
    CollegeList colleges;
    DonationList donations;
    int nextDonorID;

    double getDonorTotal(const std::string& donorName) const;

    double getCollegeTotal(const std::string& collegeCode) const;
};

#endif
