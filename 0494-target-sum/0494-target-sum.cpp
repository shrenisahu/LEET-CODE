// class Solution
// {
//     public:

//         int Solve(int idx, int target, vector<int> &nums, unordered_map<string, int> &mpp)
//         {
//             if (idx == nums.size() && target == 0)
//                 return 1;
//             if (idx == nums.size())
//                 return 0;

//             string currStr = to_string(idx) + "-" + to_string(target);
//             if (mpp.find(currStr) != mpp.end())
//                 return mpp[currStr];
//             int takePlus = Solve(idx + 1, target - nums[idx], nums, mpp);
//             int takeMinus = Solve(idx + 1, target + nums[idx], nums, mpp);

//             return mpp[currStr] = takePlus + takeMinus;
//         }

//     int Tabulate(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         unordered_map<string, int> mpp;

//         // vector<vector < int>> dp(n + 1, vector<int> (target + 1, 0));

//         for (int idx = 0; idx <= n; idx++)
//         {
//             string currStr = to_string(idx) + "-" + to_string(0);
//             mpp[currStr] = 1;
//         }
//         for (int idx = n - 1; idx >= 0; idx--)
//         {
//             for (int sum = 1; sum <= target; sum++)
//             {
//                 string currStr = to_string(idx) + "-" + to_string(sum);
//                 string currStrTake = to_string(idx + 1) + "-" + to_string(sum - nums[idx]);
//                 string currStrNotTake = to_string(idx + 1) + "-" + to_string(sum + nums[idx]);
//                 int takePlus = mpp[currStrTake];
//                 int takeMinus = mpp[currStrNotTake];

//                 mpp[currStr] = takePlus + takeMinus;
//             }
//         }
//         string currStr = to_string(0) + "-" + to_string(target);
//         return mpp[currStr];
//     }

//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         unordered_map<string, int> mpp;
//        	// int ans = Solve(0, target, nums, mpp);
//         int ans = Tabulate(nums, target);

//         return ans;
//     }
// };


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mpp;
        return TargetSum(nums, target,0,mpp);
    }
    
    
    int TargetSum(vector<int>& nums, int target,int currIndex,unordered_map<string,int>&mpp)
    {
        if(currIndex==nums.size()&& target==0)
            return 1;
        
        if(currIndex==nums.size()&& target!=0)
            return 0;
        
        string currKey=to_string(currIndex)+'-'+to_string(target);
        
        if(mpp.find(currKey)!=mpp.end())
            return mpp[currKey];
        
        int added=TargetSum(nums,target-nums[currIndex],currIndex+1,mpp);
         int sub=TargetSum(nums,target+nums[currIndex],currIndex+1,mpp);
        mpp[currKey]=added+sub;
        return   mpp[currKey];
        
    }
};