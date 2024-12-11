/*
* My first time using std::bind
* - std::bind creates a callable object (a function object) by binding some of the parameters of a function to specific values.
* - In this case, comparePages needs three arguments (a, b, and rulesList), but sort can only provide two arguments (a and b).
* - std::bind allows us to pre-specify the rulesList and leave a and b to be provided by sort.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <functional>  // For std::bind?

using namespace std;

// Function to determine if 'a' should come before 'b' based on rules
bool comesBefore(int a, int b, map<int, set<int>>& rulesList) {
    return rulesList[a].count(b) > 0;
}

// Comparator function for sorting pages
bool comparePages(int a, int b, map<int, set<int>>& rulesList) {
    return comesBefore(a, b, rulesList);
}

// Function to sort the pages based on the rules using a custom comparator
vector<int> sortPages(vector<int>& pages, map<int, set<int>>& rulesList) {
    // Use std::bind to pass the rulesList to the comparator function
    sort(pages.begin(), pages.end(), bind(comparePages, placeholders::_1, placeholders::_2, ref(rulesList)));
    /*
    * This is equilavent to this lambda expression
    * sort(pages.begin(), pages.end(), [&](int a, int b) {
    return comesBefore(a, b, rulesList);
});
    */
    return pages;
}

int main() {
    ifstream inFile;
    inFile.open("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string inputLine;
    vector<string> rules;
    vector<string> updates;
    vector<string> badUpdates;
    bool firstPart = true;
    int sumMiddlePages = 0;
    int sumCorrectedMiddlePages = 0;

    while (getline(inFile, inputLine)) {
        if (inputLine.empty()) {
            firstPart = false;
            continue;
        }
        if (firstPart) {
            rules.push_back(inputLine);
        }
        else {
            updates.push_back(inputLine);
        }
    }

    map<int, set<int>> rulesList;
    string tmp;

    for (string rule : rules) {
        stringstream ss(rule);
        int left, right;

        try {
            getline(ss, tmp, '|');
            left = stoi(tmp);

            getline(ss, tmp, '|');
            right = stoi(tmp);
        }
        catch (const invalid_argument& e) {
            cout << "Invalid number format in rule: " << rule << endl;
            return 1;
        }

        rulesList[left].insert(right);
    }

    for (string update : updates) {
        stringstream ss(update);
        vector<int> pages;
        string pageStr;

        try {
            while (getline(ss, pageStr, ',')) {
                pages.push_back(stoi(pageStr));
            }
        }
        catch (const invalid_argument& e) {
            cout << "Invalid number format in update: " << update << endl;
            return 1;
        }

        bool isValid = true;

        for (int j = 0; j < pages.size(); j++) {
            for (int k = j + 1; k < pages.size(); k++) {
                int page1 = pages[j];
                int page2 = pages[k];

                if (rulesList[page1].count(page2) > 0) {
                    continue;
                }

                if (rulesList[page2].count(page1) > 0) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) {
                break;
            }
        }

        if (isValid) {
            int middleIndex = pages.size() / 2;
            sumMiddlePages += pages[middleIndex];
        }
        else {
            badUpdates.push_back(update);
        }
    }

    // PART 2 - process and "fix" bad updates
    for (string badUpdate : badUpdates) {
        stringstream ss(badUpdate);
        vector<int> badPages;
        string pageStr;

        try {
            while (getline(ss, pageStr, ',')) {
                badPages.push_back(stoi(pageStr));
            }
        }
        catch (const invalid_argument& e) {
            cout << "Invalid number format in Bad Update: " << badUpdate << endl;
            return 1;
        }

        vector<int> sortedBadPages = sortPages(badPages, rulesList);
        int middleIndex = sortedBadPages.size() / 2;
        sumCorrectedMiddlePages += sortedBadPages[middleIndex];
    }

    cout << "SUM MIDDLE PAGES: " << sumMiddlePages << endl;
    cout << "SUM CORRECTED MIDDLE PAGES: " << sumCorrectedMiddlePages << endl;
    inFile.close();

    return 0;
}
