class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int ans =0;
        for(int col=m-1;col>=0;col--){
            int mx =0;
            for(int row=0;row<n;row++){
                mx = max(mx,grid[row][col]);
            }
            ans+=mx;
        }
        return ans;
    }
};