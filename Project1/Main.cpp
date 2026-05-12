/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include <iomanip>
#include <map>

#include "Donor.h"
#include "CollegeList.h"
#include "Donation.h"
#include "DonationList.h"
#include "DonationManager.h"
#include "FileLoader.h"

using namespace std;

int main()
{

cout << "===== PHASE 1: Testing Donor =====\n\n";

// Test parameterized constructor + all accessors.
Donor d1("Argus Moon", 3000);
Donor d2("Hanh Tran", 3001);
cout << "-- Testing parameterized constructor + accessors --\n";
cout << "Input: (\"Argus Moon\", 3000)\n";
cout << "Expected name: Argus Moon  Actual: " << d1.getDonorName() << "\n";
cout << "Expected ID:   3000        Actual: " << d1.getDonorID() << "\n\n";

// Test Donor::operator<.
cout << "-- Testing operator< --\n";
cout << "Comparing ID 3000 < 3001 => Expected: 1  Actual: " << (d1 < d2) << "\n";
cout << "Comparing ID 3001 < 3000 => Expected: 0  Actual: " << (d2 < d1) << "\n";


cout << "\n===== PHASE 2: Testing CollegeList =====\n\n";

// Create CollegeList object.
CollegeList myCollegeList;

// Test CollegeList::addCollege.
cout << "-- Testing addCollege --\n";
myCollegeList.addCollege("OCC", "Orange Coast College");
myCollegeList.addCollege("GWC", "Golden West College");
myCollegeList.addCollege("IVC", "Irvine Valley College");
cout << "Added 3 colleges (OCC, GWC, IVC).\n\n";

// Test CollegeList::getCollegeName with an existing college code.
cout << "-- Testing getCollegeName --\n";
cout << "Expected: Orange Coast College\n";
cout << "Actual:   " << myCollegeList.getCollegeName("OCC") << "\n\n";

// Test CollegeList::printColleges.
cout << "-- Testing printColleges (sorted by code) --\n";
myCollegeList.printColleges();

// Test CollegeList::getColleges.
cout << "\n-- Testing getColleges --\n";
const map<string, string>& cMap = myCollegeList.getColleges();
cout << "Expected size: 3\n";
cout << "Actual size:   " << cMap.size() << "\n";


cout << "\n===== PHASE 3: Testing Donation =====\n\n";

// Test parameterized constructor + all accessors.
Donation don1("Argus Moon", "OCC", 100.0);
cout << "-- Testing parameterized constructor + accessors --\n";
cout << "Input: (\"Argus Moon\", \"OCC\", 100.0)\n";
cout << "Expected donor:   Argus Moon  Actual: " << don1.getDonorName() << "\n";
cout << "Expected college: OCC         Actual: " << don1.getCollegeCode() << "\n";
cout << "Expected amount:  100.00      Actual: " << fixed << setprecision(2)
<< don1.getAmount() << "\n";


cout << "\n===== PHASE 4: Testing DonationList =====\n\n";

// Create DonationList object.
DonationList myList;

// Test DonationList::getNumOfDonations on an empty list.
cout << "-- Testing getNumOfDonations on empty list --\n";
cout << "Expected: 0\n";
cout << "Actual:   " << myList.getNumOfDonations() << "\n\n";

// Test DonationList::getFirst and DonationList::getLast on an empty list.
// Both return nullptr when the list is empty.
cout << "-- Testing getFirst and getLast on empty list --\n";
cout << "Expected getFirst: nullptr  Actual: "
<< (myList.getFirst() == nullptr ? "nullptr" : "not null") << "\n";
cout << "Expected getLast:  nullptr  Actual: "
<< (myList.getLast() == nullptr ? "nullptr" : "not null") << "\n\n";

// Create and add a few Donation objects to the list.
Donation don2("Hanh Tran", "SCC", 50.0);
Donation don3("Cassie", "GWC", 75.0);
myList.addDonation(don1);   // Argus Moon / OCC / 100
myList.addDonation(don2);   // Hanh Tran  / SCC /  50
myList.addDonation(don3);   // Cassie     / GWC /  75

// Test DonationList::getNumOfDonations after adding donations.
cout << "-- Testing getNumOfDonations after adding 3 donations --\n";
cout << "Expected: 3\n";
cout << "Actual:   " << myList.getNumOfDonations() << "\n\n";

// Test DonationList::getFirst.
cout << "-- Testing getFirst --\n";
DonationNode* firstNode = myList.getFirst();
cout << "Expected: Argus Moon, OCC, 100.00\n";
cout << "Actual:   "
<< firstNode->data.getDonorName() << ", "
<< firstNode->data.getCollegeCode() << ", "
<< fixed << setprecision(2)
<< firstNode->data.getAmount() << "\n\n";

// Test DonationList::getLast.
// Print the data stored in the last node.
cout << "-- Testing getLast --\n";
DonationNode* lastNode = myList.getLast();
cout << "Expected: Cassie, GWC, 75.00\n";
cout << "Actual:   "
<< lastNode->data.getDonorName() << ", "
<< lastNode->data.getCollegeCode() << ", "
<< fixed << setprecision(2)
<< lastNode->data.getAmount() << "\n\n";

// Traverse the DonationList manually using getFirst and next.
cout << "-- Traversing DonationList manually --\n";
DonationNode* current = myList.getFirst();
while (current != nullptr)
{
    cout << current->data.getDonorName() << ", "
        << current->data.getCollegeCode() << ", $"
        << fixed << setprecision(2)
        << current->data.getAmount() << "\n";
    current = current->next;
}


cout << "\n===== PHASE 5: Testing DonationManager with manual data =====\n\n";

// Create DonationManager object.
DonationManager mgr;

// Test DonationManager::addCollege by adding several colleges.
cout << "-- Testing addCollege --\n";
mgr.addCollege("OCC", "Orange Coast College");
mgr.addCollege("GWC", "Golden West College");
mgr.addCollege("IVC", "Irvine Valley College");
cout << "Added OCC, GWC, IVC.\n\n";

// Test DonationManager::printColleges.
cout << "-- Testing printColleges --\n";
mgr.printColleges();

// Test DonationManager::addDonor by adding several donors.
cout << "\n-- Testing addDonor (IDs start at 3000) --\n";
cout << "Expected ID: 3000  Actual: " << mgr.addDonor("Ada Lovelace") << "\n";
cout << "Expected ID: 3001  Actual: " << mgr.addDonor("Alan Turing") << "\n";
cout << "Expected ID: 3002  Actual: " << mgr.addDonor("Grace Hopper") << "\n\n";

// Test DonationManager::addDonation by adding several donations.
cout << "-- Testing addDonation (fresh manager) --\n";
DonationManager mgr2;
mgr2.addCollege("OCC", "Orange Coast College");
mgr2.addCollege("GWC", "Golden West College");
mgr2.addCollege("IVC", "Irvine Valley College");

mgr2.addDonation("Marie Curie", "OCC", 500.0);
mgr2.addDonation("Isaac Newton", "GWC", 300.0);
mgr2.addDonation("Charles Darwin", "IVC", 750.0);
cout << "Added 3 donations.\n\n";

// Test DonationManager::printDonationsByCollege.
cout << "-- Testing printDonationsByCollege --\n";
mgr2.printDonationsByCollege();

// Test DonationManager::printDonationsByDonor.
cout << "\n-- Testing printDonationsByDonor --\n";
mgr2.printDonationsByDonor();

// Test DonationManager::printTotalsByCollege.
cout << "\n-- Testing printTotalsByCollege --\n";
mgr2.printTotalsByCollege();

// Test DonationManager::printTotalsByDonor.
cout << "\n-- Testing printTotalsByDonor --\n";
mgr2.printTotalsByDonor();

// Test DonationManager::printStatistics.
cout << "\n-- Testing printStatistics --\n";
cout << "Expected: 3 donors, 3 colleges, 3 donations\n";
mgr2.printStatistics();

// Test DonationManager::printHighestDonor.
cout << "\n-- Testing printHighestDonor --\n";
cout << "Expected: Charles Darwin  $750.00\n";
mgr2.printHighestDonor();

// Test DonationManager::printCollegeWithHighestTotal.
cout << "\n-- Testing printCollegeWithHighestTotal --\n";
cout << "Expected: IVC - Irvine Valley College  $750.00\n";
mgr2.printCollegeWithHighestTotal();


cout << "\n===== PHASE 6: Testing FileLoader with colleges.csv and donations.csv =====\n\n";

// Create DonationManager object.
DonationManager fileMgr;

// Test loadCollegesFromFile.
cout << "-- Testing loadCollegesFromFile --\n";
loadCollegesFromFile("colleges.csv", fileMgr);

// After calling loadCollegesFromFile, test DonationManager::printColleges.
cout << "\n-- printColleges after loading colleges.csv --\n";
fileMgr.printColleges();

// Test loadDonationsFromFile.
cout << "\n-- Testing loadDonationsFromFile --\n";
loadDonationsFromFile("donations.csv", fileMgr);

// After calling loadDonationsFromFile, test all report functions:
// printDonationsByCollege
cout << "\n-- printDonationsByCollege --\n";
fileMgr.printDonationsByCollege();

// printDonationsByDonor
cout << "\n-- printDonationsByDonor --\n";
fileMgr.printDonationsByDonor();

// printTotalsByCollege
cout << "\n-- printTotalsByCollege --\n";
fileMgr.printTotalsByCollege();

// printTotalsByDonor
cout << "\n-- printTotalsByDonor --\n";
fileMgr.printTotalsByDonor();

// printStatistics
cout << "\n-- printStatistics --\n";
cout << "Expected: 10 donors, 7 colleges, 10 donations\n";
fileMgr.printStatistics();

// printHighestDonor
cout << "\n-- printHighestDonor --\n";
cout << "Expected: Marie Curie  $1000.00\n";
fileMgr.printHighestDonor();

// printCollegeWithHighestTotal
cout << "\n-- printCollegeWithHighestTotal --\n";
cout << "Expected: IVC - Irvine Valley College  $1700.00\n";
fileMgr.printCollegeWithHighestTotal();


cout << "\n===== All tests completed. =====\n";

cout << endl;
system("Pause");
return 0;
}