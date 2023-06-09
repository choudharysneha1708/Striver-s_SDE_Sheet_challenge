class Solution {
public:
    void print(vector<vector<int>>&ans, vector<int>&nums, vector<int>&temp, int i)
    {
        if(i==nums.size())
        {
            
                ans.push_back(temp);
            return;
        }
        //not pick an element
        print(ans,nums,temp,i+1);
        temp.push_back(nums[i]);

        print(ans,nums,temp,i+1);         //pick an element
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ans;  
      vector<int>temp;
      print(ans,nums,temp,0);
      return ans;
    }
};