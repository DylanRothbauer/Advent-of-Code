#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

bool isValidNumber(const string& str) {
    if (str.empty()) {
        return false;
    }

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
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
        //inputLine = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";
    //inputLine = "why()$mul(5,5)don't()mul(5,5)do()mul(2,2)^?!what()";
        int pos = 0;

        while (pos < inputLine.length()) {
            // Check for do() and don't()
            if (inputLine.substr(pos, 7) == "don't()") {
                mulEnabled = false;
                pos += 7;
                //cout << "POS: " << pos << endl;
            } else if (inputLine.substr(pos, 4) == "do()") {
                mulEnabled = true;
                pos += 4;
                //cout << "POS: " << pos << endl;
            } else if (inputLine.substr(pos, 4) == "mul(" && mulEnabled) {
                int start = pos + 4;
                //cout << "POS: " << pos << endl;
                int openBrackets = 1;
                int end = start;

                // Find the closing parenthesis of this mul()
                while (end < inputLine.length() && openBrackets > 0) {
                    if (inputLine[end] == '(') openBrackets++;
                    else if (inputLine[end] == ')') openBrackets--;
                    end++;
                }

                if (openBrackets == 0) {  // Valid "mul()"
                    string mulExpr = inputLine.substr(start, end - start - 1);  // Extract inside mul()
                    size_t commaPos = mulExpr.find(',');

                    if (commaPos != string::npos) {
                        string num1_str = mulExpr.substr(0, commaPos);
                        string num2_str = mulExpr.substr(commaPos + 1);

                        if (isValidNumber(num1_str) && isValidNumber(num2_str)) {
                            int num1 = stoi(num1_str);
                            int num2 = stoi(num2_str);
                            cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                            sum += (num1 * num2);
                        }
                    }
                }
                pos = end; // Move past the current "mul()"
            }
            else {
                pos++;  // Move  to the next character
            }
        }
    }

    cout << "Sum of valid mul results: " << sum << endl;
    inFile.close();
    return 0;
}
