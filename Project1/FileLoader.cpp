/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "FileLoader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void loadCollegesFromFile(const string& fileName,
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;

        // Read one complete line at a time.
        while (getline(inFile, line))
        {
            stringstream lineStream(line);

            string collegeCode;
            string collegeName;

            getline(lineStream, collegeCode, ',');

            getline(lineStream, collegeName);

            // Remove trailing \r
            if (!collegeName.empty() && collegeName.back() == '\r')
                collegeName.pop_back();

            manager.addCollege(collegeCode, collegeName);
        }

        inFile.close();
        cout << "=> College data loaded...\n";
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}

void loadDonationsFromFile(const string& fileName,
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        string line;

        while (getline(inFile, line))
        {
            stringstream lineStream(line);

            string donorName;
            string collegeCode;
            string amountStr;

            getline(lineStream, donorName,   ',');
            getline(lineStream, collegeCode, ',');
            getline(lineStream, amountStr);

            // Remove trailing \r 
            if (!amountStr.empty() && amountStr.back() == '\r')
                amountStr.pop_back();

            // Convert the amount text to a double.
            double amount = stod(amountStr);

            manager.addDonation(donorName, collegeCode, amount);
        }

        inFile.close();
        cout << "=> Donation data loaded...\n";
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}
