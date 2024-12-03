#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int AddLists(vector<int> &list1, vector<int> &list2) {
	
	int total = 0;

	for (int i = 0; i < list1.size(); i++) {
		total += abs(list1[i] - list2[i]);
	}
	cout << "TOTAL: " << total << endl;

	return total;
}

int AddFrequency(vector<int>& list1, vector<int>& list2) {
	int total = 0;

	for (int i = 0; i < list1.size(); i++) {
		int target = list1[i];
		int num;
		num = count(list2.begin(), list2.end(), target);
		list1[i] = list1[i] * num;
	}

	for (int i = 0; i < list1.size(); i++) {
		total += list1[i];
	}

	cout << "TOTAL FREQUENCY: " << total << endl;

	return total;
}


void AddToLists(string line, vector<int> &list1, vector<int> &list2) {

	string first = line.substr(0, line.find("   "));
	cout << "FIRST: " << first << " ";
	list1.push_back(stoi(first));
	
	string second = line.substr(line.find("   "), line.length());
	cout << "SECOND: " << second << endl;
	list2.push_back(stoi(second));

}

int main() {
	vector<int> list1;
	vector<int>list2;
	ifstream inFile;
	inFile.open("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");

	if (!inFile) {
		cout << "Error opening file" << endl;
		return 1;
	}

	string inputLine;
	while (getline(inFile, inputLine)) {
		AddToLists(inputLine, list1, list2);
	}

	// SortLists
	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());

	AddFrequency(list1, list2);
	AddLists(list1, list2);

	inFile.close();

	return 0;
}