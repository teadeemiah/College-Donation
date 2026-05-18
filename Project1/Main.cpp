/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include <iomanip>
#include <map>

#include "Menu.h"
#include "DonationManager.h"
#include "FileLoader.h"

using namespace std;

int main()
{
	DonationManager manager;

	cout << fixed << setprecision(2);

	loadCollegesFromFile("colleges.csv", manager);
	loadDonationsFromFile("donations.csv", manager);

	processUserChoices(manager);

	cout << endl;
	system("pause");
	return 0;
}