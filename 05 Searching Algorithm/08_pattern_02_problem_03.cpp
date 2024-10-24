class Solution {
public:
    // tc for average case O(log2n)
    // tc for worst case when almost all elements are same O(n/2) 
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        
        int low =0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] and nums[high] == nums[mid]){
                low++;
                high--;
                continue;
            }
            if(nums[mid]>=nums[low]){
                if(target>=nums[low] and target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low= mid+1;  
                }
            }
            else{
                if(target>nums[mid] and target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        } 
        return false;  
    }
};