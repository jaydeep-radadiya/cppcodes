// first method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};

// second method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> ump;
        
        for(int i=0;i<nums.size();i++){
            if(ump.find(target-nums[i])!=ump.end()){
                // complementary number is present
                ans.push_back(ump[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            ump[nums[i]] = i;
        }
        
        return ans;
    }
};

// third method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int>> arr;
        
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});    
        }
        sort(arr.begin(),arr.end());
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right){
            if(arr[left].first+arr[right].first==target){
                ans.push_back(arr[left].second);
                ans.push_back(arr[right].second);
                break;
            }
            else if(arr[left].first+arr[right].first>target)
                right--;
            else if(arr[left].first+arr[right].first<target)
                left++;
        }
        
        return ans;
    }
};