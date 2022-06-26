class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        
        for(int currRow=0; currRow <m; currRow++)
        {
            for(int currCol=0;currCol <n ; currCol++)
            {
                
                if(board[currRow][currCol]==word[0] && DFS(currRow,currCol,0,m,n,board,word))
                {
                    return true;
                }
            }
        }
        return false;
        
    }
    
    
    bool DFS(int currRow,int currCol,int currIndex,int m,int n,vector<vector<char>>& board,string &word)
    {
        if(currIndex>=word.size())
            return true;
        if(currRow <0 || currCol <0 || currRow >=m || currCol >=n ||  board[currRow][currCol]!=word[currIndex])
            return false;
        
        
        
        char temp=   board[currRow][currCol];
        board[currRow][currCol]='.';
        
     bool found=     DFS(currRow+1,currCol,currIndex+1,m,n,board,word)|| 
                     DFS(currRow-1,currCol,currIndex+1,m,n,board,word)||
                     DFS(currRow,currCol+1,currIndex+1,m,n,board,word)||
                     DFS(currRow,currCol-1,currIndex+1,m,n,board,word);
        
        board[currRow][currCol]=temp;
    
        
        return found;
        // return false;
    }
};