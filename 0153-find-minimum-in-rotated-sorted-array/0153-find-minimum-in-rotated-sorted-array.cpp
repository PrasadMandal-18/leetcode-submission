class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0;
       int high = nums.size() - 1;
       int ans = INT_MAX;

       while(low <= high){
        int mid = low + (high - low) / 2;
        //both side are sorted

        if(nums[low] <= nums[high]){
            ans = min(ans, nums[low]);
            break;
        }
        //left sie are sorted

        else if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        // right side sorted

        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
     }
       return ans; 
    }
};