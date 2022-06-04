class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>mainAns;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        NQUEEN(board,0,n,mainAns);
        return mainAns;
    }
    
    void NQUEEN(vector<vector<char>>&board,int currRow,int n ,vector<vector<string>>&mainAns )    
    {
        if(currRow==n)
        {
            vector<string>tempAns=Convert(board);
            mainAns.push_back(tempAns);
              return ;
        }
        for(int currCol=0;currCol<n;currCol++){
            if(isValid(board,currRow,currCol,n)){
            board[currRow][currCol]='Q';
            NQUEEN(board,currRow+1,n,mainAns);
            board[currRow][currCol]='.';
           }
        }
        return ;
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
    
    vector<string>Convert( vector<vector<char>>&board)
    {
        vector<string> Lists;
        
        for(auto temp:board)
        {
            string currString="";
            for(auto eachChar:temp)
            {
                currString+=eachChar;
            }
            Lists.push_back(currString);     
        }
        return Lists;

    }
        
};