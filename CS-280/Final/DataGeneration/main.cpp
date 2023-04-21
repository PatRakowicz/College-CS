#include <iostream>
#include "invGenerator.h"

int main() {
    // configure how many pallets you want in the data
    const int NUM_PALLETS = 10;

    InventoryGenerator generator("data.csv");

    for (int i = 1; i <= NUM_PALLETS; i++) {
        Pallet pallet = generator.generate_pallet(i);
        std::cout << "Pallet " << pallet.pallet_number << ": " << pallet.state << ", " << pallet.city << ", " << pallet.weight << " pounds\n";
    }

    return 0;
}
