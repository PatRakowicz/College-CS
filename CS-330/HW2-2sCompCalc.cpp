/* Patrick Rakowicz
 * CS 330
 * HW2-2sCompCalc.cpp
*/

#include <iostream>
#include <string>

using namespace std;

string addBinary(const string& a, const string& b) {
	string result = "";
	char carry = '0';

	for (int i = 7; i >= 0; --i) {
		int sum = (a[i] - '0') 
			+ (b[i] - '0') 
			+ (carry - '0');
		
		if (sum % 2 == 0) { result = '0' + result; } 
		else { result = '1' + result; }

		if (sum > 1) { carry = '1'; }
		else { carry = '0'; }
	}
	return result;
}

string getTwosComp(const string& binary) {
	string onesComp = "";
	for (char bit : binary) { onesComp += (bit == '0') ? '1' : '0'; }
	string one = "00000001";
	return addBinary(onesComp, one);
}

int BinToDec(const string& binary) {
	int decimal = 0;
	int base = 1;

	for (int i = 7; i >= 1; --i) {
		decimal += (binary[i] - '0') * base;
		base *= 2;
	}

	if (binary[0] == '1') { decimal -= 128; };

	return decimal;
}

int main() {
	string a, b, op;
	string result;

	cout << "Enter Equation: ";
	cin >> a >> op >> b;

	if (op == "+") { result = addBinary(a,b); } 
	else if (op == "-") { result = addBinary(a, getTwosComp(b)); }

	int decimalA = BinToDec(a);
	int decimalB = BinToDec(b);
	int decimalResult = BinToDec(result);

	cout << a << " (" << decimalA << ")\n";
    	cout << op << " " << b << " (" << decimalB << ")\n";
    	cout << "===========================\n";
    	cout << result << " (" << decimalResult << ")\n";

    	return 0;
}
