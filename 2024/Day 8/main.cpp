#include <iostream> // For input/output
#include <fstream> // For file handling
#include <vector> // To store lists of antenna positions
#include <set> // To track unique antinodes
#include <map> // To organize antennas by frequency
#include <cctype> // To identify alphanumeric characters
#include <string> // To manipulate strings

using namespace std;

int main() {
    ifstream inFile("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");
    string inputLine;

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Read the grid
    vector<string> grid;
    while (getline(inFile, inputLine)) {
        grid.push_back(inputLine);
    }

    int rows = grid.size(); // The number of rows in the grid
    int cols = grid[0].size(); // Number of columns in the grid

    // Store antenna positions by frequency
    map<char, vector<pair<int, int>>> antennas;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (isalnum(grid[i][j])) {  // Check if the character is an antenna
                antennas[grid[i][j]].emplace_back(i, j);
            }
        }
    }

    // Set to store unique antinode positions
    set<pair<int, int>> antinodes;

    // Process each frequency
    for (const auto& antenna : antennas) {
        char freq = antenna.first;
        const auto& positions = antenna.second;
        int n = positions.size();

        // Every antenna contributes as an antinode unless it is the only one
        if (n > 1) {
            for (const auto& pos : positions) {
                antinodes.emplace(pos.first, pos.second);
            }
        }

        // Check every pair of antennas
        for (int i = 0; i < n; ++i) {
            int x1 = positions[i].first;
            int y1 = positions[i].second;

            for (int j = i + 1; j < n; ++j) {
                int x2 = positions[j].first;
                int y2 = positions[j].second;

                // Check for all points in line with the two antennas
                int dx = x2 - x1;
                int dy = y2 - y1;

                for (int k = 1;; ++k) {
                    int xk = x1 - k * dx; // Extend backward
                    int yk = y1 - k * dy;
                    if (xk >= 0 && xk < rows && yk >= 0 && yk < cols) {
                        antinodes.emplace(xk, yk);
                    }
                    else {
                        break;
                    }
                }

                for (int k = 1;; ++k) {
                    int xk = x2 + k * dx; // Extend forward
                    int yk = y2 + k * dy;
                    if (xk >= 0 && xk < rows && yk >= 0 && yk < cols) {
                        antinodes.emplace(xk, yk);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

    cout << "Total Unique Antinodes: " << antinodes.size() << endl;

    return 0;
}
