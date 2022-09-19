class Solution
{
    public:
        vector<vector < string>> findDuplicate(vector<string> &paths)
        {

            int n = paths.size();
            unordered_map<string, vector < string>> memo;
            vector<vector < string>> result;
            for (int i = 0; i < n; i++)
            {

                string currPath = paths[i];
                stringstream stream1;
                stream1 << currPath;

                string currPathTillRoot;
                getline(stream1, currPathTillRoot, ' ');
               	// cout << currPathTillRoot << "  ->   ";
                string subPaths;

                while (getline(stream1, subPaths, ' '))
                {

                    int idx = 0;
                    string content = "";
                    string fileName = "";
                    while (idx < subPaths.size())
                    {

                        if (subPaths[idx] == '(')
                        {

                            idx++;
                            while (subPaths[idx] != ')')
                            {
                                content += subPaths[idx];
                                idx++;
                            }
                        }
                        else
                        {
                            fileName += subPaths[idx];
                        }
                        idx++;
                    }
                    string mapValue = currPathTillRoot +'/'+ fileName;
                    memo[content].push_back(mapValue);
                   	// cout << "conetent is" << content << " filename is  " << fileName << "  ";
                }

               	// cout << endl;
            }

            for (auto i: memo)
            {
                if (i.second.size() > 1)
                {
                    result.push_back(i.second);
                }
            }
        
    return result;
}
};