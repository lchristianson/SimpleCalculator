/* Lucas Christianson
* CS222 Data Structures
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Arithmetic.h"
using namespace std;

int main(int argc, char** argv) {

	cout << "Please enter the first numerator:  ";
	string n1;
	getline(cin, n1);
	cout << "Please enter the first denominator:  ";
	string d1;
	getline(cin, d1);
	cout << "Please enter the second numerator:  ";
	string n2;
	getline(cin, n2);
	cout << "Please enter the second denominator:  ";
	string d2;
	getline(cin, d2);
	addFractions(n1, d1, n2, d2);
	cout << endl;
	
	system("pause");
	return 0;
}

string sum(string n1, string n2) {
	remleadingzeroes(n1);
	remleadingzeroes(n2);
	while (n1.length() < n2.length())
		n1 = "0" + n1;
	while (n2.length() < n1.length())
		n2 = "0" + n2;
	n1 = "0" + n1;
	n2 = "0" + n2;
	int carry = 0;
	string sum = "";
	for (int i = n1.length() - 1; i >= 0; i--) {
		int d1 = n1[i] - '0';
		int d2 = n2[i] - '0';
		int dsum = d1 + d2 + carry;
		carry = dsum / 10;
		char sd = dsum % 10 + '0';
		sum = sd + sum; // + is doing string concatenation.
	}
	remleadingzeroes(sum);
	return sum;


}

void remleadingzeroes(string& n) {

	while (n.length() > 1 && n[0] == '0')
		n = n.substr(1);

	//substr(x) returns the substring beginning at position x and ending at the end of the string
	//if n is "0025"  n.substr(1) is "025"
}

string subtract(string n1, string n2) {
	//Assume that n1 >= n2

	remleadingzeroes(n1);
	remleadingzeroes(n2);
	while (n2.length() < n1.length())
		n2 = "0" + n2;
	for (int i = 0; i < (int)n2.length(); i++)
		n2[i] = '9' - n2[i] + '0';
	string diff = sum("1", sum(n1, n2));
	diff = diff.substr(1);
	remleadingzeroes(diff);
	return diff;



}

string times(string a, string b) {

	remleadingzeroes(a);
	remleadingzeroes(b);
	string runningsum = "0";
	for (int i = 0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++) {
			string prod = to_string((a[i] - '0') * (b[j] - '0'));
			for (int k = 0; k < a.length() - i - 1 + b.length() - j - 1; k++)
				prod += "0";
			runningsum = sum(runningsum, prod);

		}
	return runningsum;


}

string divide(string numerator, string denominator, string& remainder) {
	remleadingzeroes(numerator);
	remleadingzeroes(denominator);
	vector<string> denominators;
	string quotient = "0";
	string r = numerator;
	if (compare(numerator, denominator) >= 0) {
		while (compare(denominator, numerator) <= 0) {
			denominators.push_back(denominator);
			denominator = times(denominator, "2");
		}
		for (int i = denominators.size() - 1; i >= 0; i--) {
			if (compare(denominators[i], r) <= 0) {
				r = subtract(r, denominators[i]);
				quotient = sum(times(quotient, "2"), "1");
			}
			else {
				quotient = times(quotient, "2");
			}
		}
		remainder = r;
	}
	else {
		remainder = numerator;
	}
	return quotient;

}

int compare(string a, string b) {
	remleadingzeroes(a);
	remleadingzeroes(b);
	if (a.length() > b.length())
		return 1;
	if (a.length() < b.length())
		return -1;
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] > b[i])
				return 1;
			if (a[i] < b[i])
				return -1;
		}
		return 0;
	}
	/*
	Comparing numeric strings is not the same as comparing alphabetic strings.  C++ compares strings in alphabetical order and that's not what you want here.
	For example:

	5 < 23
	"23" < "5"
	When you compare numeric strings, you need to take the length of the string into account.




	*/


}

string GCF(string numerator, string denominator) {
	string num = numerator;
	string den = denominator;
	string remainder;
	while (den != "0") {
		divide(num, den, remainder);
		num = den;
		den = remainder;
	}
	return num;
}

void addFractions(string n1, string d1, string n2, string d2) {
	remleadingzeroes(n1);
	remleadingzeroes(n2);
	remleadingzeroes(d1);
	remleadingzeroes(d2);
	string n3 = sum(times(n1, d2), times(n2, d1));
	string d3 = times(d1, d2);
	string rem1;
	string rem2;
	string gcf = GCF(n3, d3);
	n3 = divide(n3, gcf, rem1);
	d3 = divide(d3, gcf, rem2);
	cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = " << n3 << "/" << d3 << endl;
}
/*

How do I convert a char to an int?

ASCII codes / code points

'A' = 65; 'a' = 97
'0' = 48; '1' = 49... '9' = 57

5 = 53 - 48 = '5' - '0'
7 = '7' - '0'


sum = 12.  12/10 = 1.  sum = 7.  7/10 = 0.

25%10 = 5.  32%10 = 2.
*/