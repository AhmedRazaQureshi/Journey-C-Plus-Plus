#include <iostream>
#include <vector>
using namespace std;

//Ques#01: Permutations of a string
void stringPermutation(string& str, int i, vector<string>& per)
{
    //BC
    if(i > str.length()-1)
    {
        per.push_back(str);
        return;
    }

    //Rec
    for(int j=i; j<str.length(); j++)
    {
        //Swap
        swap(str[i],str[j]);
        //Recursive call
        stringPermutation(str, i+1, per);
        //Backtrack
        swap(str[i],str[j]);
    }
}

//Ques#02: Rat in a maze
bool isSafe(vector<vector<int>>& maze, int i, int j, int rows, int cols, vector<vector<bool>>& visited)
{
    if( (i>=0 && i<rows) &&(j>=0 && j<cols) && 
        (maze[i][j] == 1) && (visited[i][j] == false) )
        return true;
    
    return false;
}


void solveMaze(vector<vector<int>>& maze, int rows, int cols, int i, int j, vector<vector<bool>>& visited, 
               vector<string>& paths, string currPath)
{
    //BC
    if(i == rows-1 && j == cols-1)
    {
        paths.push_back(currPath);
        return;
    }

    //Rec
    //Saare moves chal-chal k dekhunga
    //Down: i+1 , j
    if(isSafe(maze, i+1, j, rows, cols, visited))
    {
        visited[i+1][j] = true;
        //Recursive call
        solveMaze(maze, rows, cols, i+1, j, visited, paths, currPath+"D");
        //Backtrack
        visited[i+1][j] = false;
    }
    //Left: i , j-1
    if(isSafe(maze, i, j-1, rows, cols, visited))
    {
        visited[i][j-1] = true;
        //Recursive call
        solveMaze(maze, rows, cols, i, j-1, visited, paths, currPath+"L");
        //Backtrack
        visited[i][j-1] = false;
    }
    //Right: i , j+1
    if(isSafe(maze, i, j+1, rows, cols, visited))
    {
        visited[i][j+1] = true;
        solveMaze(maze, rows, cols, i, j+1, visited, paths, currPath+"R");
        visited[i][j+1] = false;
    }
    //Up: i-1 , j
    if(isSafe(maze, i-1, j, rows, cols, visited))
    {
        visited[i-1][j] = true;
        solveMaze(maze, rows, cols, i-1, j, visited, paths, currPath+"U");
        visited[i-1][j] = false;
    }
    
}

//Ques#03: n-Queens problem
void storeSolution(vector<vector<char>>& board, vector<vector<string>>& ans)
{
    vector<string> currSol;
    for(int i=0; i<board.size(); i++)
    {
        string boardRow = "";
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'Q')
                boardRow += 'Q';
            else
                boardRow += '.';
        }
        currSol.push_back(boardRow);
    }
    ans.push_back(currSol);
}

bool queenIsSafe(vector<vector<char>>& board, int i, int j, int n)
{
    int temp_i = i;
    int temp_j = j;

    //Check row (back)
    while(j >= 0)
    {
        if(board[i][j] == 'Q')
            return false;

        j--;
    }

    //Check upper-diagonal (back)
    j = temp_j;
    while(i>=0 && j>=0)
    {
        if(board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    //Check lower-diagonal (back)
    i = temp_i;
    j = temp_j;
    while(i<n && j>=0)
    {
        if(board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}

void queenSolver(vector<vector<char>>& board, int j, int n, vector<vector<string>>& ans)
{
    //BC
    if(j >= n)
    {
        storeSolution(board, ans);
        return;
    }

    //Rec
    //iss j'th column mein har ek row try out krni hai
    for(int i=0; i<n; i++)
    {
        if(queenIsSafe(board, i, j, n))
        {
            //Place queen
            board[i][j] = 'Q';
            //Recursive call
            queenSolver(board, j+1, n, ans);
            //Backtrack
            board[i][j] = '.';
        }
    }
}



int main()
{
    //Ques#01: Permutations of a string
    string s1 = "abc";
    vector<string> per;
    stringPermutation(s1, 0, per);
    for(auto i: per)
        cout<<i<<",";
    cout<<endl;

    //Ques#02: Rat in a maze
    vector<vector<int>> maze = { {1,0,0,0},
                                 {1,1,1,0},
                                 {0,1,1,0},
                                 {0,1,1,1} };
    vector<string> paths;
    int rows = 4;
    int cols = 4;
    vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
    visited[0][0] = true; //starting position of mouse

    //Edge case-1: No rat in maze (maze[0][0] is false)
    if(maze[0][0] == false)
        cout<<"No path exists"; //solveMaze ko call na karna fir
    
    solveMaze(maze, rows, cols, 0, 0, visited, paths, "");
    for(auto i: paths)
        cout<<i<<",";
    cout<<endl;


    //Ques#03: n-Queens problem
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> possiblePositions;
    int j = 0; //iss column par kaam kr rha hu abhi
    queenSolver(board, j, n, possiblePositions);

    for(int i=0; i<possiblePositions.size(); i++)
    {
        for(int j=0; j<possiblePositions[i].size(); j++)
        {
            cout<<possiblePositions[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}