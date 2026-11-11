class Solution {
public:
int FindMax(vector<int>&piles){
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i= 0; i<n; i++){
        maxi = max(maxi , piles[i]);
    }
    return maxi;
}
long long CalculateTotalHours(vector<int>&piles , int hourly){
    long long totalh = 0;
    int n = piles.size();
    for(int i = 0; i<n; i++){
        totalh += ((long long)piles[i] + hourly - 1) / hourly;
    }
    return totalh;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = FindMax(piles);
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) /2;
            
            long long totalh = CalculateTotalHours(piles , mid);
            if(totalh <= h){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;   
    }
};