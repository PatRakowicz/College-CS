// Patrick Rakowicz
// CS 330
// HW1 - BinDecHex.cpp

#include <iostream>
#include <string>

using namespace std;

string decimalToBinary(int n) {
	string binary = "";

	for (int i = 7; i >= 0; i--) {
		binary += (n & (1 << i)) ? '1' : '0';
	}
	return binary;
}

string decimalToHex(int n) {
	const char hexDigits[] = "0123456789ABCDEF";
	string hex = "0x";

	int mostSig4Bits = (n & 240) >> 4;
    	hex += hexDigits[mostSig4Bits];
	
	int lestSig4Bits = n & 15;
	hex += hexDigits[lestSig4Bits];

	return hex;
}

int binaryToDecimal(const string &binary) {
	int decimal = 0;
	for (int i = 0; i < 8; i++) {
		decimal = decimal * 2 + (binary[i] - '0');
	}
	return decimal;
}

int hexToDecimal(const string &hex) {
	int decimal = 0;
	for (int i = 2; i < 4; i++) {
		char digit = hex[i];
		if ('0' <= digit && digit  <= '9') {
			decimal = decimal * 16 + (digit - '0');
		} else {
			decimal = decimal * 16 + (10 + digit - 'A');
		}
	}
	return decimal;
}

int stringToDecimal(const string &str) {
	int val = 0;
	for (const char &c : str) {
		if (c < '0' || c > '9') {
			cout << "Invalid Entry!";
			exit (1);
		}
		val = val * 10 + (c - '0');
	}
	return val;
}

int main() {
	string input;
	cout << "Enter a number to convert: ";
	cin >> input;

	int decimal;

	if (input[0] == 'b' && input.size() == 9) {
		decimal = binaryToDecimal(input.substr(1));
	} else if (input.substr(0, 2) == "0x" && input.size() == 4) {
		decimal = hexToDecimal(input);
	} else {
		decimal = stringToDecimal(input);
		if (decimal < 0 || decimal > 255) {
			cout << "Invalid Entry!";
			return 1;
		}
	}

	cout << "Decimal : " << decimal << endl;
	cout << "Binary  : " << decimalToBinary(decimal) << endl;
	cout << "HEX     : " << decimalToHex(decimal) << endl;

	return 0;
}
