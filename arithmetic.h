/*Lucas Christianson
CS222 Data structures
This program runs all basic arithmetic on user entered strings.
*/
#ifndef _ARITHMETIC_
#define _ARITHMETIC_

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char** argv);
string sum(string n1, string n2);
//this method returns the sum of two input strings, sum returned as a string.

void remleadingzeroes(string& n);
//This method removes any leading zeroes from the input string, ie "0068" -> "68"

string subtract(string n1, string n2);
//This method finds the difference of two strings with the assumption that n1 > n2, difference returned as string.

string times(string a, string b);
//This method multipies two strings and returns the product as a string.

string divide(string dividend, string divisor, string& remainder);
//The method returns the quotient, and the remainder is stored in the designated reference parameter)

int compare(string a, string b);
//return -1 if a < b; 0 if a==b; 1 if a > b

string GCF(string a, string b);
//returns the greatest common factor of a and b

void addFractions(string n1, string d1, string n2, string d2);
//This method adds two fractions and simplifies the sum fraction.

#endif