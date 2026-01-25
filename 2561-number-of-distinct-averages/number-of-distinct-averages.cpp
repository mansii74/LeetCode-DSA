class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<int>ans;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            ans.insert(sum);
            i++;
            j--;
        }
        return ans.size();
    }
};