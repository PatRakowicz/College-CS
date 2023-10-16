#include <iostream>

// Define a simple enumeration
enum class Colors {
    RED, GREEN, BLUE, YELLOW
};

int main() {
    Colors color1 = Colors::RED;
    Colors color2 = Colors::BLUE;

    // 1. Assignment
    // Does it work? Yes.
    // What does it do?
    // Assigns one enum value to another variable.
    // Why do you believe it does what it does?
    // Enums are data types with a set of named values. Assignment works as expected.
    color1 = Colors::GREEN;

    // 2. Comparison
    // Does it work? Yes.
    // What does it do? Compares two enum values.
    // Why do you believe it does what it does? Enumeration types can be compared for equality and inequality.
    if (color1 == color2) {
        std::cout << "Both colors are the same." << std::endl;
    }

    // 3. Casting to int
    // Does it work? Yes.
    // What does it do? Returns the underlying integer value of the enum.
    // Why do you believe it does what it does? Enums have an underlying integer type, which is implicitly set if not explicitly specified.
    int val = static_cast<int>(color1);
    std::cout << "Integer value of color1: " << val << std::endl;

    // 4. Arithmetic operations
    // Does it work? Not directly.
    // What does it do? Arithmetic operations are not directly allowed on enums.
    // Why do you believe it does what it does? Enums are not meant for arithmetic; they're meant to represent distinct values.

    // will cause problems
    // color1 = color1 + 1;

    // 5. Increment
    // Does it work? Not directly.
    // What does it do? Not supported.
    // Why do you believe it does what it does? Enums are not integers and don't support the increment operation.
    // Uncommenting the below line will cause a compilation error.
    // color1++;

    // 6. Using with switch
    // Does it work? Yes.
    // What does it do? Allows branching based on enum values.
    // Why do you believe it does what it does? Enums are meant to represent a set of distinct values, making them ideal for switches.
    switch (color2) {
        case Colors::RED:
            std::cout << "It's red." << std::endl;
            break;
        case Colors::BLUE:
            std::cout << "It's blue." << std::endl;
            break;
            // ...
    }

    // 7. Adding enums (with a twist)
    // Does it work? Yes, with casting.
    // What does it do? Adds underlying int values, then casts back to the enum.
    // Why do you believe it does what it does? Enum's underlying value can be manipulated with casting. However, this can lead to unexpected values.
    color1 = static_cast<Colors>(static_cast<int>(color1) + static_cast<int>(color2));
    // This might result in an undefined state for the enum if not careful.

    // 8. Out of range value
    // Does it work? Yes.
    // What does it do? Assigns an out-of-range value to the enum variable.
    // Why do you believe it does what it does? The underlying type of the enum can hold the value, but it's no longer a valid Colors value.
    color1 = static_cast<Colors>(100); // This is an undefined behavior.

    // 9. Looping through enums (with a twist)
    // Does it work? Yes, with casting.
    // What does it do? Iterates over all enum values.
    // Why do you believe it does what it does? With proper casting, we can iterate over all the values.
    for (int i = static_cast<int>(Colors::RED); i <= static_cast<int>(Colors::YELLOW); i++) {
        std::cout << "Color value: " << i << std::endl;
    }

    // 10. Using enums in arithmetic (with casting)
    // Does it work? Yes.
    // What does it do? Uses the underlying integer value in arithmetic.
    // Why do you believe it does what it does? With casting, the enum value can be used in arithmetic operations.
    int result = static_cast<int>(color1) * 10;
    std::cout << "Result: " << result << std::endl;

    return 0;
}

/*
 * using arithmetic on enums directory doest work, but with casting to the underlying typ , you can do
 * many unexpected operations. this may easily lead to undefined states if the programmer is not careful.*/