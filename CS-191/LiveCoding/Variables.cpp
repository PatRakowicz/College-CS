#include <iostream>
#include <string>

// You own  a furnature stre
// Goal: Take a
// product
// price
// tax
// installation fee
// Output: total price

int main () {
	std::string product;
	product = "couch";
	float price = 999.99;
	float tax = 0.09;
	float install = 100;

	float total = (price + install) * (1 + tax);

	std::cout << "Your " << product << " cost " << total << "\n";	
}
