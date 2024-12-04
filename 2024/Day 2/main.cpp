#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to check if the vector is either strictly increasing or strictly decreasing, and adjacent differences are within 3
bool isSafeReport(const vector<int>& nums) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < nums.size() - 1; i++) {
        int diff = abs(nums[i] - nums[i + 1]);
        if (diff > 3 || diff == 0) {  // Difference must be at least 1 and at most 3
            return false;
        }
        if (nums[i] >= nums[i + 1]) {
            increasing = false;
        }
        if (nums[i] <= nums[i + 1]) {
            decreasing = false;
        }
    }

    return increasing || decreasing;  // Safe if strictly increasing or decreasing
}

// Function to check if the report can be safe by removing one element
bool canBeSafeByRemovingOne(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        vector<int> temp = nums;
        temp.erase(temp.begin() + i);
        if (isSafeReport(temp)) {
            return true;
        }
    }
    return false;
}

int main() {
    int numOfSafeReports = 0;
    ifstream inFile("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string inputLine;
    while (getline(inFile, inputLine)) {
        vector<int> nums;
        stringstream ss(inputLine);
        int num;

        // Extract numbers from the line
        while (ss >> num) {
            nums.push_back(num);
        }

        // Check if the report is safe or can be made safe by removing one element
        if (isSafeReport(nums) || canBeSafeByRemovingOne(nums)) {
            numOfSafeReports++;
        }
    }

    inFile.close();
    cout << "Number of safe reports: " << numOfSafeReports << endl;
    return 0;
}
