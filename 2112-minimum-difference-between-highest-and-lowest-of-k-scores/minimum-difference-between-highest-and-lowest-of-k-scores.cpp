class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==0) return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i+k-1<n;i++){
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};