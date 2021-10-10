// first method
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        
        vector<int> temp;
        for(int ele : nums){
            if(ele!=0){
                temp.push_back(ele);
            }
        }
        
        while(cnt--){
            temp.push_back(0);
        }
        
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};

// second method
// set all the non zero elements are at beginning of array
// fill remaining array with zero
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[idx++] = nums[i];
            }
        }
        
        for(int i=idx;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};