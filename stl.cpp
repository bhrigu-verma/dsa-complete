#include <iostream> // Include the iostream library for input and output
using namespace std;
int main() {
    // Declare variables to hold the user input
    int num1, num2, sum;

    // Prompt the user for input
    std::cout << "Enter the first number: ";
    std::cin >> num1; // Read the first number

    std::cout << "Enter the second number: ";
    std::cin >> num2; // Read the second number

    // Calculate the sum of the two numbers
    sum = num1 + num2;

    // Display the result
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << "." << std::endl;

    return 0; // Indicate that the program ended successfully
}
#for stl follow this following cheatsheet 
# https://www.geeksforgeeks.org/cpp-stl-cheat-sheet/?ref=shm