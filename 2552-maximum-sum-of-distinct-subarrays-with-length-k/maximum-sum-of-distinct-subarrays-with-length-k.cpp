class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0, ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            sum += nums[right];

            // shrink window if duplicate exists
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            // check window size
            if (right - left + 1 == k) {
                ans = max(ans, sum);

                // slide window
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};