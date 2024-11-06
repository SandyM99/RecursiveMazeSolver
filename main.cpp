#include <iostream>
#include <vector>
using namespace std;

// Constants for default maze dimensions (modifiable by user input)
const int WIDTH = 5;
const int HEIGHT = 5;

vector<vector<int>> maze; // Maze representation (2D vector)
int startX, startY, endX, endY; // Start and end coordinates

// Function to print the maze with the solution path
void printMaze() {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[0].size(); ++j) {
            if (maze[i][j] == 1)
                cout << "# ";  // Wall
            else if (maze[i][j] == 2)
                cout << ". ";  // Solution path
            else
                cout << "  ";  // Open space
        }
        cout << endl;
    }
}

// Recursive function to solve the maze
bool solveMaze(int x, int y) {
    // Base cases: Check if (x, y) is out of bounds or a wall
    if (x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || maze[x][y] != 0) {
        return false;
    }

    // Mark current cell as part of the solution path
    maze[x][y] = 2;

    // Check if we have reached the goal
    if (x == endX && y == endY) {
        return true;
    }

    // Recursive calls to move in each direction: right, down, left, up
    if (solveMaze(x, y + 1) || solveMaze(x + 1, y) ||
        solveMaze(x, y - 1) || solveMaze(x - 1, y)) {
        return true;
    }

    // Backtrack: If no path is found, reset the cell to open
    maze[x][y] = 0;
    return false;
}

// Function to initialize the maze based on user input
void initializeMaze() {
    cout << "Enter the dimensions of the maze (e.g., 5 5): ";
    int rows, cols;
    cin >> rows >> cols;
    maze.resize(rows, vector<int>(cols));

    cout << "Enter the maze layout (0 for open, 1 for wall):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> maze[i][j];
        }
    }

    cout << "Enter start coordinates (e.g., 0 0): ";
    cin >> startX >> startY;
    cout << "Enter end coordinates (e.g., 4 4): ";
    cin >> endX >> endY;
}

int main() {
    initializeMaze(); // Initialize the maze based on user input

    // Start solving from the custom start coordinates
    if (solveMaze(startX, startY)) {
        cout << "Path found:\n";
    } else {
        cout << "No path found.\n";
    }

    printMaze();  // Display the maze with the solution path
    return 0;
}
