class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n);
        vector<int> leftMax(n), rightMax(n);

        stack<int> st;

        // previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // previous greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long maxContri = 1LL * leftMax[i] * rightMax[i] * nums[i];
            long long minContri = 1LL * leftMin[i] * rightMin[i] * nums[i];
            totalSum += (maxContri - minContri);
        }

        return totalSum;
    }
};
