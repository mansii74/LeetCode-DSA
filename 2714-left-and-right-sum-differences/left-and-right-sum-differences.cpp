class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int total=0;
        for(int x: nums)total+=x;
        int Ls =0;  //leftsum
        for(int i=0;i<n;i++){
            int Rs = total-Ls-nums[i];
            ans[i]= abs(Ls-Rs);
            Ls+=nums[i];
        }
        return ans;
    }
};