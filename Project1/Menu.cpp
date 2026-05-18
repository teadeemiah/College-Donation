/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "Menu.h"

#include <iostream>
#include <string>

using namespace std;

void displayMenu()
{
    cout << endl;
    cout << "============= DONATION MENU =============" << endl;
    cout << endl;
    cout << "\t1. Add college" << endl;
    cout << "\t2. Add donation" << endl;
    cout << "\t3. Print colleges" << endl;
    cout << "\t4. Print donations by college" << endl;
    cout << "\t5. Print donations by donor" << endl;
    cout << "\t6. Print totals by college" << endl;
    cout << "\t7. Print totals by donor" << endl;
    cout << "\t8. Print statistics" << endl;
    cout << "\t9. Print highest donor" << endl;
    cout << "\t10. Print highest-funded college" << endl;
    cout << "\t0. Exit" << endl;
}

void processUserChoices(DonationManager& manager)
{
    int choice;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Choice 0: Exit
        if (choice == 0)
        {
            cout << endl;
            cout << "\t\t>>>Logging out..." << endl;   // NO space after >>>
            cout << endl;
            system("pause");
            break;
        }

        // Choice 1: Add college
        else if (choice == 1)
        {
            cout << endl;

            string code, name;

            cout << "Enter college code: ";
            cin >> code;
            cin.ignore(); // discard the \n left after the code

            cout << "Enter college name: ";
            getline(cin, name); 

            manager.addCollege(code, name);

            cout << endl;
            cout << "\t\t>>> College added." << endl;
            cout << endl;
            system("pause");
        }

        // Choice 2: Add donation
        else if (choice == 2)
        {
            cout << endl;

            string donorName;

            cin.ignore(); // discard the \n from cin >> choice
            cout << "Enter new donor name: ";
            getline(cin, donorName); 

			int donorID = manager.addDonor(donorName); // Get the assigned donor ID.

            cout << endl;
            cout << "\t\t>>> New donor ID: " << donorID << endl;
            cout << endl;

            string collegeCode;
            cout << "Enter college code: ";
            cin >> collegeCode;

            double amount;
            cout << "Enter donation amount: ";
            cin >> amount;

            manager.addDonation(donorID, collegeCode, amount);

            cout << endl;
            cout << "\t\t>>> Donation added." << endl;
            cout << endl;
            system("pause");
        }

        // Choice 3: Print colleges 
        else if (choice == 3)
        {
            cout << endl;
            manager.printColleges();
            cout << endl;
            system("pause");
        }

        // Choice 4: Print donations by college 
        else if (choice == 4)
        {
            cout << endl;
            manager.printDonationsByCollege();
            cout << endl;
            system("pause");
        }

        // Choice 5: Print donations by donor 
        else if (choice == 5)
        {
            cout << endl;
            manager.printDonationsByDonor();
            cout << endl;
            system("pause");
        }

        // Choice 6: Print totals by college 
        else if (choice == 6)
        {
            cout << endl;
            manager.printTotalsByCollege();
            cout << endl;
            system("pause");
        }

        // Choice 7: Print totals by donor 
        else if (choice == 7)
        {
            cout << endl;
            manager.printTotalsByDonor();
            cout << endl;
            system("pause");
        }

        // Choice 8: Print statistics 
        else if (choice == 8)
        {
            cout << endl;
            manager.printStatistics();
            cout << endl;
            system("pause");
        }

        // Choice 9: Print highest donor
        else if (choice == 9)
        {
            cout << endl;
            manager.printHighestDonor();
            cout << endl;
            system("pause");
        }

        // Choice 10: Print highest-funded college 
        else if (choice == 10)
        {
            cout << endl;
            manager.printCollegeWithHighestTotal();
            cout << endl;
            system("pause");
        }
    }
}