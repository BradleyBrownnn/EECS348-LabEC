#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

double extractNumber(const string& str);
void displayOutput(double number);

// makes the display for the given number
void displayOutput(double number) {
    std::cout << "The input is: " << std::fixed << std::setprecision(4) << number << std::endl;
}

double extractNumber(const std::string& input) {
    try {
        size_t idx = 0;
        double number = std::stod(input, &idx);

        // checks for extra characters after the number
        if (idx != input.length()) {
            return -999999.99;
        }
        if (input.find('e') != std::string::npos) {
            return -999999.99;
        }
        return number;

    } catch (const std::invalid_argument& ) {
        // Catch any exception (invalid argument or out of range)
        return -999999.99;
    } catch (const std::out_of_range&) {
        return -999999.99;
    } catch (...) {
        return -999999.99;
    }

}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string (or 'END' to quit): ";
        std::getline(std::cin, input);

        // Exit the loop if user enters "END"
        if (input == "END") {
            break;
        }

        // Extract number from the input string
        double result = extractNumber(input);

        // Check if the input is valid
        if (result == -999999.99) {
            std::cout << "The input is invalid.\n";
        } else {
            displayOutput(result);
        }
    }

    return 0;
}
