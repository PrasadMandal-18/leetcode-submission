class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int low = 0;
        int high = nums.back() - nums.front();

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long count = 0;
            int i = 0;
            for(int j =0; j< nums.size() ; j++){
                while(nums[j] - nums[i] > mid){
                    i++;
                }
                count += j - i;
            }
            if(count < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};