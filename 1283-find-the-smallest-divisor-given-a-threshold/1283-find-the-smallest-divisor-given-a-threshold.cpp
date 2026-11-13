class Solution {
public:
int sumByDivisior(vector<int>&nums , int div){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        sum += (nums[i] + div - 1) / div;
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int  n = nums.size();
        if(n > threshold){
            return -1;
        }
        int maxi = INT_MIN , ans = -1;
        for(int i = 0; i<n ; i++){
            maxi = max(maxi , nums[i]);
        }
        int low = 1 , high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(sumByDivisior(nums , mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low =  mid + 1;
            }
        }
        return ans;
    }
};