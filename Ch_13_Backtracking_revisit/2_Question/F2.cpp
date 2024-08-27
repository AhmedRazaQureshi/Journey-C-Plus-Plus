#include <bits/stdc++.h>
using namespace std;

//Just continuing Ques#03: n-Queens problem
//Optimising queenIsSafe() from TC: O(3n) to O(1) using Hash-Map
unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperDiagCheck;
unordered_map<int,bool> lowerDiagCheck;

bool isSafe(vector<vector<char>>& board, int i, int j, int n)
{
    if(rowCheck[i]==true || upperDiagCheck[n-1+j-i]==true || lowerDiagCheck[i+j]==true)
        return false;

    return true;
}

void storeSolution(vector<vector<char>>& board, vector<vector<string>>& ans)
{
    vector<string> currSol;

    for(int i=0; i<board.size(); i++)
    {
        string currRow = "";
        for(int j=0; j<board[i].size(); j++)
        {
            currRow += board[i][j];
        }
        currSol.push_back(currRow);
    }

    ans.push_back(currSol);
}

void queenSolver(vector<vector<char>>& board, int& n, int j, vector<vector<string>>& ans)
{
    //BC
    if(j >= n)
    {
        storeSolution(board, ans);
        return;
    }

    //Rec
    for(int i=0; i<n; i++)
    {
        if(isSafe(board, i, j, n))
        {
            //Place 'Q'
            board[i][j] = 'Q';
            rowCheck[i]=true;
            upperDiagCheck[n-1+j-i]=true;
            lowerDiagCheck[i+j]=true;

            //Recursive call
            queenSolver(board, n, j+1, ans);

            //Back-track
            board[i][j] = '.';
            rowCheck[i]=false;
            upperDiagCheck[n-1+j-i]=false;
            lowerDiagCheck[i+j]=false;


        }

    }
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n,'.'));
    vector<vector<string>> possiblePositions;
    int j=0;
    queenSolver(board, n, j, possiblePositions);

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