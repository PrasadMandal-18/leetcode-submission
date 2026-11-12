class Solution {
public:
bool Possible(vector<int>&bloomDay , int day , int m , int k){
    int count = 0;
    int bouqeuts = 0 , n = bloomDay.size();
    for(int i = 0; i < n; i++){
        if(bloomDay[i] <= day){
            count ++;
        }
        else{
            bouqeuts += count / k;
            count = 0;
        }
    }
    bouqeuts += count / k;
    return bouqeuts >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL*m*k;
        int n = bloomDay.size();
        if(val > n){
            return -1;
        }
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i = 0; i < n ;i++){
            mini = min(mini , bloomDay[i]);
            maxi = max(maxi , bloomDay[i]);
        }
        int low = mini , high = maxi , ans =-1;
        while(low <= high){
            int mid = low +(high - low) / 2;
            if(Possible(bloomDay,mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};