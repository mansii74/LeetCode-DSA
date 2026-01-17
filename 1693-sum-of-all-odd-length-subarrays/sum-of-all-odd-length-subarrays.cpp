class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(len%2==1){
                    for(int k=i;k<=j;k++){
                        ans+=arr[k];
                    }
                }
            }
        }
        return ans;
    }
};