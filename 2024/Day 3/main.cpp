#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

bool isValidNumber(const string& str) {

    if (str.empty()) {
        return false;
    }

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int processMul(const string& content) {
    // Check if another "mul(" exists inside the content; if so, abandon processing
    if (content.find("mul(") != string::npos) {
        return 0;  // Invalid due to nested "mul("
    }

    int commaPos = content.find(',');
    if (commaPos != string::npos && content.find(',', commaPos + 1) == string::npos) {
        string num1_str = content.substr(0, commaPos);
        string num2_str = content.substr(commaPos + 1);

        if (isValidNumber(num1_str) && isValidNumber(num2_str)) {
            int num1 = stoi(num1_str);
            int num2 = stoi(num2_str);
            return num1 * num2;
        }
    }
    return 0;  // Return 0 if invalid
}

int main() {
    ifstream inFile("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string inputLine;
    int sum = 0;
    bool mulEnabled = true;

    while (getline(inFile, inputLine)) {
        int pos = 0;

        while (pos < inputLine.length()) {
            if (inputLine.substr(pos, 7) == "don't()") {
                mulEnabled = false;
                pos += 7;
            }
            else if (inputLine.substr(pos, 4) == "do()") {
                mulEnabled = true;
                pos += 4;
            }
            else if (inputLine.substr(pos, 4) == "mul(" && mulEnabled) {
                int start = pos + 4;
                int openBrackets = 1;
                int end = start;

                // Find the closing parenthesis of this mul()
                while (end < inputLine.length() && openBrackets > 0) {
                    if (inputLine[end] == '(') openBrackets++;
                    else if (inputLine[end] == ')') openBrackets--;
                    end++;
                }

                if (openBrackets == 0) {  // Valid "mul()"
                    string mulExpr = inputLine.substr(start, end - start - 1);
                    sum += processMul(mulExpr);  // Process the extracted content
                }
                // pos = end | This worked before, but changed to pos++ to not abandon nested mul('s
                pos++;  // Move past the current "mul()"
            }
            else {
                pos++;
            }
        }
    }

    cout << "Sum of valid mul results: " << sum << endl;
    inFile.close();
    return 0;
}
