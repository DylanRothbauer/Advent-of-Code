#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

int validateXMASShape(vector<vector<char>>& list, int i, int k) {
    int count = 0;

    // Check bounds for the 3x3 (X) grid
    if (i - 1 >= 0 && i + 1 < list.size() && k - 1 >= 0 && k + 1 < list[i].size()) {
        // Orientation 1: M (top-left), S (bottom-right), S (top-right), M (bottom-left)
        if (list[i - 1][k - 1] == 'M' && list[i + 1][k + 1] == 'S' &&
            list[i - 1][k + 1] == 'S' && list[i + 1][k - 1] == 'M') {
            count++;
        }

        // Orientation 2: S (top-left), M (bottom-right), M (top-right), S (bottom-left)
        if (list[i - 1][k - 1] == 'S' && list[i + 1][k + 1] == 'M' &&
            list[i - 1][k + 1] == 'M' && list[i + 1][k - 1] == 'S') {
            count++;
        }

        // Orientation 3: M (top-right), S (bottom-left), M (top-left), S (bottom-right)
        if (list[i - 1][k + 1] == 'M' && list[i + 1][k - 1] == 'S' &&
            list[i - 1][k - 1] == 'M' && list[i + 1][k + 1] == 'S') {
            count++;
        }

        // Orientation 4: S (top-right), M (bottom-left), S (top-left), M (bottom-right)
        if (list[i - 1][k + 1] == 'S' && list[i + 1][k - 1] == 'M' &&
            list[i - 1][k - 1] == 'S' && list[i + 1][k + 1] == 'M') {
            count++;
        }
    }

    return count;
}

int validateXMAS(vector<vector<char>>& list, int i, int k) {
    int runningSum = 0;

    // Check horizontal (left, right)
    if (k - 3 >= 0) { // LEFT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i][k - p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    if (k + 3 < list[i].size()) { // RIGHT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i][k + p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    // Check vertical (up, down)
    if (i - 3 >= 0) { // UP
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i - p][k];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    if (i + 3 < list.size()) { // DOWN
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i + p][k];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    // Check diagonals
    if (i - 3 >= 0 && k + 3 < list[i - 3].size()) { // TOP RIGHT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i - p][k + p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    if (i - 3 >= 0 && k - 3 >= 0) { // TOP LEFT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i - p][k - p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    if (i + 3 < list.size() && k - 3 >= 0) { // BOTTOM LEFT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i + p][k - p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    if (i + 3 < list.size() && k + 3 < list[i + 3].size()) { // BOTTOM RIGHT
        string tmp = "";
        for (int p = 1; p < 4; p++) {
            tmp += list[i + p][k + p];
        }
        if (tmp == "MAS") {
            cout << "YAY! VALID!" << endl;
            cout << "LOCATION AT: " << "[" << i << "]" << " " << "[" << k << "]" << endl;
            runningSum++;
            cout << "RUNNING SUM: " << runningSum << endl;
        }
    }

    return runningSum;
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
    vector<vector<char>> list;
    int accuranceXMAS = 0;
    int accuranceXMASShape = 0;

    // Populate my list
    while (getline(inFile, inputLine)) {
        //cout << inputLine << endl;
        vector<char> tmp;
        for (int i = 0; i < inputLine.length(); i++) {
            tmp.push_back(inputLine[i]);
        }
        list.push_back(tmp);
    }

    /* string inputTest = "MMMSXXMASM\nMSAMXMSMSA\nAMXSXMAAMM\nMSAMASMSMX\nXMASAMXAMM\nXXAMMXXAMA\nSMSMSASXSS\nSAXAMASAAA\nMAMMMXMMMM\nMXMXAXMASX\n";
     vector<vector<char>> testList;
     vector<char> ch;
     for (int i = 0; i < inputTest.length(); i++) {
         if (inputTest[i] == '\n') {
             testList.push_back(ch);
             ch.clear();
         }
         else {
             ch.push_back(inputTest[i]);
         }

     }*/


     // Testing output of vector
     /*for (int i = 0; i < testList.size(); i++) {
         for (int k = 0; k < testList.size(); k++) {
             cout << testList[i][k] << " ";
         }
         cout << endl;
     }*/

     // PART 1
    for (int i = 0; i < list.size(); i++) {
        for (int k = 0; k < list[i].size(); k++) {
            //cout << "LIST[i].SIZE(): " << list[i].size() << endl;
            if ((list[i][k]) == 'X') {
                accuranceXMAS += validateXMAS(list, i, k);
            }
            else {
                // Just continue
            }
        }
    }

    cout << "ACCURANCE OF VALID XMAS: " << accuranceXMAS << endl;

    // PART 2
    for (int i = 0; i < list.size(); i++) {
        for (int k = 0; k < list[i].size(); k++) {
            if (list[i][k] == 'A') {
                accuranceXMASShape += validateXMASShape(list, i, k);
            }
            else {
                // Just continue
            }

        }
    }

    cout << "ACCURANCE OF VALID X-MAS PATTERNS: " << accuranceXMASShape << endl;


    inFile.close();
    return 0;
}
