#include <bits/stdc++.h>
using namespace std;

// LEETCODE: 46. Permutations
void stringPermutation(string &str, int i, vector<string> &per)
{
    // BC
    if (i > str.length() - 1)
    {
        per.push_back(str);
        return;
    }

    // Rec
    for (int j = i; j < str.length(); j++)
    {
        // Swap
        swap(str[i], str[j]);
        // Recursive call
        stringPermutation(str, i + 1, per);
        // Backtrack
        swap(str[i], str[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    // Convert to string
    string str;
    for (int i = 0; i < nums.size(); i++)
        str.push_back(nums[i] + '0');

    // Find all string permutations
    vector<string> stringPer;
    stringPermutation(str, 0, stringPer);

    // Convert to vector
    vector<vector<int>> ans;
    for (int i = 0; i < stringPer.size(); i++)
    {
        string currString = stringPer[i];
        vector<int> currArray;
        for (int j = 0; j < currString.size(); j++)
            currArray.push_back(currString[j] - '0');

        ans.push_back(currArray);
    }

    return ans;
}

// GFG: Rat in a maze problem 1
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

bool isSafe(vector<vector<int>> &maze, int rows, int cols,
            int i, int j, vector<vector<bool>> &visited)
{
    if ((i >= 0 && i < rows) && (j >= 0 && j < cols) &&
        (maze[i][j] == 1) && (visited[i][j] == false))
        return true;
    return false;
}

void solveMaze(vector<vector<int>> &maze, int rows, int cols, int i, int j,
               vector<vector<bool>> &visited, vector<string> &paths, string currPath)
{
    // BC
    if (i == rows - 1 && j == cols - 1)
    {
        paths.push_back(currPath);
        return;
    }

    // Rec
    // Moving in all 4 directions
    for (int k = 0; k < 4; k++)
    {
        int currX = i + dx[k];
        int currY = j + dy[k];
        char currDir = dir[k];

        if (isSafe(maze, rows, cols, currX, currY, visited))
        {
            visited[currX][currY] = true;
            solveMaze(maze, rows, cols, currX, currY, visited, paths, currPath + currDir);
            visited[currX][currY] = false;
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;
    vector<string> paths;

    // Edge case-1: Source cell is zero => return empty list
    if (mat[0][0] == 0)
        return paths;

    // Regular cases: -------------------

    solveMaze(mat, rows, cols, 0, 0, visited, paths, "");

    return paths;
}

// LEETCODE: 51. N-Queens
void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans)
{
    vector<string> currSol;
    for (int i = 0; i < board.size(); i++)
    {
        string boardRow = "";
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'Q')
                boardRow += 'Q';
            else
                boardRow += '.';
        }
        currSol.push_back(boardRow);
    }
    ans.push_back(currSol);
}

bool queenIsSafe(vector<vector<char>> &board, int i, int j, int n)
{
    int temp_i = i;
    int temp_j = j;

    // Check row (back)
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        j--;
    }

    // Check upper-diagonal (back)
    j = temp_j;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    // Check lower-diagonal (back)
    i = temp_i;
    j = temp_j;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}

void queenSolver(vector<vector<char>> &board, int j, int n, vector<vector<string>> &ans)
{
    // BC
    if (j >= n)
    {
        storeSolution(board, ans);
        return;
    }

    // Rec
    // iss j'th column mein har ek row try out krni hai
    for (int i = 0; i < n; i++)
    {
        if (queenIsSafe(board, i, j, n))
        {
            // Place queen
            board[i][j] = 'Q';
            // Recursive call
            queenSolver(board, j + 1, n, ans);
            // Backtrack
            board[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> possiblePositions;
    int j = 0; // iss column par kaam kr rha hu abhi
    queenSolver(board, j, n, possiblePositions);

    return possiblePositions;
}

//Optimising queenIsSafe() from TC: O(3n) to O(1) using Hash-Map
