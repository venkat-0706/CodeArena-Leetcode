class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than;  
        vector<int> equal_to;  
        vector<int> greater_than; 
        for(int num:nums){
            if(num < pivot){
                less_than.push_back(num);
            } else if(num == pivot){
                equal_to.push_back(num);
            } else{
                greater_than.push_back(num);
            }
        }
        less_than.insert(less_than.end(), equal_to.begin(), equal_to.end());  
        less_than.insert(less_than.end(), greater_than.begin(), greater_than.end());  

    return less_than; 
        
    }
};