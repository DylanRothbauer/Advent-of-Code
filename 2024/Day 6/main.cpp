#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

// Function to move the guard based on its direction and track visited positions
void moveGuard(vector<vector<char>>& grid, int row, int col, char direction, set<pair<int, int>>& visited) {
    while (true) {
        // Boundary check: stop if the guard moves out of bounds
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            break;  // Exit the loop if out of bounds
        }

        // Mark the current position as visited
        visited.insert({ row, col });

        // Determine the next position based on the current direction
        int nextRow = row;
        int nextCol = col;

        if (direction == '^') {
            nextRow = row - 1;
        }
        else if (direction == '>') {
            nextCol = col + 1;
        }
        else if (direction == 'v') {
            nextRow = row + 1;
        }
        else if (direction == '<') {
            nextCol = col - 1;
        }

        // Check if the next position is an obstacle
        if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && grid[nextRow][nextCol] == '#') {
            // Turn right if there's an obstacle
            if (direction == '^') {
                direction = '>';
            }
            else if (direction == '>') {
                direction = 'v';
            }
            else if (direction == 'v') {
                direction = '<';
            }
            else if (direction == '<') {
                direction = '^';
            }
        }
        else {
            // Move to the next position
            row = nextRow;
            col = nextCol;
        }
    }
}

// Function to move the guard and check if it's looping
bool moveGuardAndCheckLoop(vector<vector<char>>& grid, int row, int col, char direction) {
    set<tuple<int, int, char>> visitedStates;  // Track visited positions and directions

    while (true) {
        // Boundary check: stop if the guard moves out of bounds
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return false;
        }

        // If the current state (position + direction) has been visited, a loop is detected
        if (visitedStates.count(tuple<int, int, char>(row, col, direction))) {
            return true;
        }

        visitedStates.insert(tuple<int, int, char>(row, col, direction));

        // Determine the next position based on the current direction
        int nextRow = row;
        int nextCol = col;

        if (direction == '^') {
            nextRow = row - 1;
        }
        else if (direction == '>') {
            nextCol = col + 1;
        }
        else if (direction == 'v') {
            nextRow = row + 1;
        }
        else if (direction == '<') {
            nextCol = col - 1;
        }

        // Check if the next position is an obstacle
        if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && grid[nextRow][nextCol] == '#') {
            // Turn right if there's an obstacle
            if (direction == '^') {
                direction = '>';
            }
            else if (direction == '>') {
                direction = 'v';
            }
            else if (direction == 'v') {
                direction = '<';
            }
            else if (direction == '<') {
                direction = '^';
            }
        }
        else {
            // Move to the next position
            row = nextRow;
            col = nextCol;
        }
    }
}

// Function to find valid positions to place an obstacle and check for loops
int countLoopingObstacles(vector<vector<char>> grid, pair<int, int> guardPos, char direction) {
    int loopCount = 0;

    // Iterate through all positions in the grid
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            // Skip the guard's starting position and existing obstacles
            if ((i == guardPos.first && j == guardPos.second) || grid[i][j] == '#') {
                continue;
            }

            // Place an obstacle at (i, j)
            grid[i][j] = '#';

            // Check if placing the obstacle causes the guard to loop
            if (moveGuardAndCheckLoop(grid, guardPos.first, guardPos.second, direction)) {
                loopCount++;
            }

            // Remove the obstacle to restore the grid for the next iteration
            grid[i][j] = '.';
        }
    }

    return loopCount;
}

// Function to find the guard's starting position and direction
pair<pair<int, int>, char> findGuard(const vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            char cell = grid[i][j];
            if (cell == '^' || cell == '>' || cell == 'v' || cell == '<') {
                return { {i, j}, cell };
            }
        }
    }
    return { {-1, -1}, ' ' };  // Return invalid position if guard is not found
}

int main() {
    ifstream inFile("C:\\Users\\RothbauerDylan\\Downloads\\Input.txt");
    string inputLine;

    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<vector<char>> grid;
    while (getline(inFile, inputLine)) {
        vector<char> row(inputLine.begin(), inputLine.end());
        grid.push_back(row);
    }

    inFile.close();

    // Find the guard's starting position and direction
    pair<pair<int, int>, char> guardInfo = findGuard(grid);
    pair<int, int> guardPos = guardInfo.first;
    char direction = guardInfo.second;

    if (guardPos.first == -1) {
        cout << "Guard not found!" << endl;
        return 1;
    }

    // Track visited positions
    set<pair<int, int>> visited;
    moveGuard(grid, guardPos.first, guardPos.second, direction, visited);

    // Output the number of distinct positions visited
    cout << "Distinct positions visited: " << visited.size() << endl;

    // Check for looping obstacles
    int loopCount = countLoopingObstacles(grid, guardPos, direction);

    // Output the number of looping obstacles
    cout << "Number of positions that cause the guard to loop: " << loopCount << endl;

    return 0;
}
