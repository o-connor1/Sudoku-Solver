#include<bits/stdc++.h>
using namespace std;
void readpuzzle (int grid[][9]){
  cout << "Enter a Sudoku puzzle:" << endl;
  for(int i=0;i<9;i++)
    for (int j=0;j<9;j++)
      cin>>grid[i][j];
}
bool isValid1(int i,int j,int grid[][9]){
  for(int column = 0; column < 9; column++)
    if (column!=j and grid[i][column]==grid[i][j])
      return false;
  for(int row = 0; row < 9; row++)
    if (row!=i and grid[row][j]==grid[i][j])
      return false;
  for(int row=(i/3)*3;row<(i/3)*3+3;row++)
    for(int col=(j/3)*3;col<(j/3)*3+3;col++)
      if(row!=i and col!=j and grid[row][col]==grid[i][j])
        return false;
  return true;
}
bool isValid(int grid[][9]) {
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      if(grid[i][j] != 0)
        if(!isValid1(i, j, grid))
          return false;
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      if((grid[i][j] < 0) or (grid[i][j] > 9))
        return false;
  return true;
}
int main(){
    int grid [9][9];
    readpuzzle (grid);
    bool ans=isValid(grid);
    if(!ans)
      cout << "Sudoku is not valid" << endl;
    else if(ans)
      cout<<"Sudoku is valid\n";
  return 0;
}
