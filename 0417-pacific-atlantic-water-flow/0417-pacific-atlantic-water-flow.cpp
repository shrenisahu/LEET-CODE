class Solution
{
    public:
        vector<vector < int>> pacificAtlantic(vector<vector < int>> &grid)
        {
            int tr = grid.size();
            int tc = grid[0].size();
            vector<vector < int>>ans;
            set<pair<int, int>> pacific;
            set<pair<int, int>> atlantic;

            for (int cc = 0; cc < tc; cc++)// upper
            {
                int prevHeight = grid[0][cc];
                DFS(0, cc, tr, tc, grid, pacific, prevHeight);
            }
            for (int cr = 0; cr < tr; cr++)	// left
            {
                int prevHeight = grid[cr][0];
                DFS(cr, 0, tr, tc, grid, pacific, prevHeight);
            }

            for (int cc = 0; cc < tc; cc++)	//lower
            {
                int prevHeight = grid[tr - 1][cc];
                DFS(tr - 1, cc, tr, tc, grid, atlantic, prevHeight);
            }

            for (int cr = 0; cr < tr; cr++)	//right
            {
                int prevHeight = grid[cr][tc - 1];
                DFS(cr, tc - 1, tr, tc, grid, atlantic, prevHeight);
            }
            cout<<atlantic.size()<<endl;
            cout<<pacific.size()<<endl;
            
            
            for(int i=0;i<tr;i++)
            {
                for(int j=0;j<tc;j++)
                {
                    if((atlantic.find({i,j})!=atlantic.end()) &&  (pacific.find({i,j})!=pacific.end()))
                    {
                        vector<int>temp;
                        temp.push_back(i);
                        temp.push_back(j);
                        ans.push_back(temp);
                    }
                }
            }
            
            return ans;
        }

    void DFS(int cr, int cc, int tr, int tc, vector<vector < int>> &grid, set< pair<int, int>> &visited, int prevHeight)
    {
        if (cr < 0 || cc < 0 || cr >= tr || cc >= tc || grid[cr][cc] < prevHeight)
            return;

        if (visited.find({ cr,
                cc }) != visited.end())
            return;

        visited.insert({ cr,
            cc });
        
        
         DFS(cr+1,cc,tr,tc,grid,visited,grid[cr][cc]);
         DFS(cr-1,cc,tr,tc,grid,visited,grid[cr][cc]);
         DFS(cr,cc+1,tr,tc,grid,visited,grid[cr][cc]);
         DFS(cr,cc-1,tr,tc,grid,visited,grid[cr][cc]);
        
        return ;
        
    }
};