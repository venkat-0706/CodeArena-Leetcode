class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto &row:grid){
            int n =row.size();
            int low =0 , high = n-1;
            while(low <= high){
                int mid = (low + high)/2;
                if(row[mid]< 0){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            count = count + n-low;
        }
        return count;
    }
};