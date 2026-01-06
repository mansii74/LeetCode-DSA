class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxsum=0;
        for(int i=0;i<n;i++){
            unordered_set<int> even,odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2){
                    even.insert(nums[j]);
                }else{
                    odd.insert(nums[j]);
                }

                if(even.size()==odd.size()){
                    maxsum=max(maxsum,j-i+1);
                }
            }
        }
        return maxsum;
    }
};