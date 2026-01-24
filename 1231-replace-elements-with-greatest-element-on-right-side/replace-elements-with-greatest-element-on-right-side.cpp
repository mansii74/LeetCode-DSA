class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        int max_right = -1;
        for(int i=n-1;i>=0;i--){
            ans[i]=max_right;
            max_right=max(max_right,arr[i]);
        }   
        return ans;
    }
};