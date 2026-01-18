class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n= candyType.size();
        set<int>candy;
        for(int i:candyType) candy.insert(i);
        int m = candy.size();
        return min(n/2,m);
    }
};