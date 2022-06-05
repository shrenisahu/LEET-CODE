class Solution {
public:
    int totalNQueens(int n) {
      
        int count=0;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        NQueen(board,0,n,count);
       
        return count;
    }
    
    void NQueen(vector<vector<char>>&board,int currRow,int n, int &count)
    {
        if(currRow==n)
        {
            count++;
           
            return ;
        }
        
        for(int currCol=0;currCol<n;currCol++)
        {
            if(isValid(board,currRow,currCol,n))
            {
                board[currRow][currCol]='Q';
                NQueen(board,currRow+1,n,count);
                board[currRow][currCol]='.';
            }
        }
        return;
    }
    
    
     bool isValid( vector<vector<char>>&board,int currRow,int currCol,int n)
    {
        
        return isRowValid(board,currRow,n)&& isColValid(board,currCol,n)&& isDiagonalValid(board,currRow,currCol,n);
        
    }
    
    bool isRowValid( vector<vector<char>>&board,int currRow,int n)
    {
        for(int currCol=0;currCol<n;currCol++)
        {
            if(board[currRow][currCol]=='Q')
                return false;
        }
        return true;
    }
    
    bool isColValid(vector<vector<char>>&board,int currCol,int n)
    {
        for(int currRow=0;currRow<n;currRow++)
        {
            if(board[currRow][currCol]=='Q')
                return false;
        }
        return true;
    }
    
    bool isDiagonalValid(vector<vector<char>>&board,int currRow,int currCol,int n)
    {
        return upperRight(board,currRow,currCol,n) && upperLeft(board,currRow,currCol,n);
    }
    
    bool upperLeft(vector<vector<char>>&board,int currRow,int currCol,int n)
    {
        int row=currRow;
        int col=currCol;
        
        while(row>=0 && col >=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
                
            }
            row--;
            col--;
        }
        return true;
    }
    
    bool upperRight(vector<vector<char>>&board,int currRow,int currCol,int n)
    {
        int row=currRow;
        int col=currCol;
        
        while(row>=0 && col <=n-1)
        {
             if(board[row][col]=='Q')
            {
                return false;
                
            }
            row--;
            col++;
        }
         return true;
    }
    
   
};