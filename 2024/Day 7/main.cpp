#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// Helper function to recursively generate all combinations of '+', '*', and '||'
void generateCombinations(vector<char>& current, int n, vector<vector<char>>& allCombinations) {
    if (current.size() == n) {
        allCombinations.push_back(current);
        return;
    }

    // Add '+' and recurse
    current.push_back('+');
    generateCombinations(current, n, allCombinations);
    current.pop_back();

    // Add '*' and recurse
    current.push_back('*');
    generateCombinations(current, n, allCombinations);
    current.pop_back();

    // Add '||' and recurse
    current.push_back('|');
    generateCombinations(current, n, allCombinations);
    current.pop_back();
}

// Simplified concatenation function
long long concatenate(long long a, long long b) {
    return stoll(to_string(a) + to_string(b));
}

// Function to evaluate the result of applying the operators
long long evaluateExpression(const vector<long long>& numbers, const vector<char>& operators) {
    long long result = numbers[0];
    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        }
        else if (operators[i] == '*') {
            result *= numbers[i + 1];
        }
        else if (operators[i] == '|') { // Concatenation operator
            result = concatenate(result, numbers[i + 1]);
        }
    }
    return result;
}

int main() {
    ifstream inFile("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");
    string inputLine;
    long long totalCalibration = 0;

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    while (getline(inFile, inputLine)) {
        stringstream ss(inputLine);
        string target, rightHandSide;

        try {
            // Extract the target value and numbers
            if (getline(ss, target, ':') && getline(ss, rightHandSide)) {
                long long targetValue;
                try {
                    targetValue = stoll(target); // Convert the left-hand side to a long long
                }
                catch (const invalid_argument& e) {
                    cerr << "Error: Invalid target value in input: " << target << endl;
                    continue; // Skip this line
                }
                catch (const out_of_range& e) {
                    cerr << "Error: Target value out of range: " << target << endl;
                    continue; // Skip this line
                }

                // Extract numbers from the right-hand side
                stringstream numbersStream(rightHandSide);
                vector<long long> numbers;
                long long number;

                while (numbersStream >> number) {
                    numbers.push_back(number);
                }

                if (numbers.empty()) {
                    cerr << "Error: No numbers found on the right-hand side for input: " << inputLine << endl;
                    continue; // Skip this line
                }

                // Generate all combinations of operators
                vector<vector<char>> allCombinations;
                vector<char> current;
                int operatorCount = numbers.size() - 1;
                generateCombinations(current, operatorCount, allCombinations);

                // Check all combinations
                bool isPossible = false;
                for (const auto& operators : allCombinations) {
                    try {
                        long long result = evaluateExpression(numbers, operators);
                        if (result == targetValue) {
                            isPossible = true;
                            break;
                        }
                    }
                    catch (const exception& e) {
                        cerr << "Error evaluating expression: " << e.what() << endl;
                        continue; // Ignore invalid expressions
                    }
                }

                // Add to the total calibration if possible
                if (isPossible) {
                    totalCalibration += targetValue;
                }
            }
            else {
                cerr << "Error: Invalid input format in line: " << inputLine << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Unexpected error while processing line: " << inputLine << "\n"
                << "Error: " << e.what() << endl;
        }
    }

    inFile.close();

    cout << "TOTAL CALIBRATION RESULT: " << totalCalibration << endl;
    return 0;
}
