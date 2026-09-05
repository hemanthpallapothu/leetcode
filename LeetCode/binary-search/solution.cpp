class Solution {
public:
    int helper(vector<int>& nums, int target, int left, int right){
        if(left>right) return -1;
        else{
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) return helper(nums, target, left,mid-1);
            else return helper(nums, target, mid+1, right);
        }
    }

    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        return helper(nums, target, left, right);
    }
};