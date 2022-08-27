class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<int>ans;
        int n2=nums2.size();
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i=n2-1; i>=0;i--){
            int currElem=nums2[i];
            
            while(!st.empty() && st.top () <=currElem)
                st.pop();
            
            if(st.empty())
                mpp[currElem]=-1;
            
            else 
                {
                    mpp[currElem]=st.top();
                }
            
            st.push(currElem);
        }
        
        
        for(auto i:nums1)
        {
            int temp=mpp[i];
            ans.push_back(temp);
        }
        return ans;
    }
};