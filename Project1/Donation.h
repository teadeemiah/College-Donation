/*
    Moon, Argus

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATION_H
#define DONATION_H

#include <string>

class Donation
{
public:
    // Inline parameterized constructor using an initializer list.
    Donation(const std::string& aDonorName,
             const std::string& aCollegeCode,
             double anAmount)
        : donorName(aDonorName), collegeCode(aCollegeCode), amount(anAmount) {}

    // Accessors 
    std::string getDonorName()  const;
    std::string getCollegeCode() const;
    double getAmount()      const;

private:
    std::string donorName;
    std::string collegeCode;
    double amount;
};

#endif
