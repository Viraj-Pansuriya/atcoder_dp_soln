#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
#include <functional>
#include <type_traits>
#include <tuple>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <valarray>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cstdarg>
#include <climits>
#include <cfloat>
#include <bitset>
#define ll long long
using namespace std;




// ll check(vector < ll > & arr , ll index , ll remain , vector < vector < ll > > & dp){
//     if(remain == 0) return 1; 
//     if(index == arr.size()) return 0;
    
//     if(dp[index][remain] != -1) return dp[index][remain]; 

//     ll count = 0; 
//     for(int i = 0 ; i <= remain && i <= arr[index] ; i++){
//         count = (count % md + check(arr , index + 1, remain-i , dp) % md) % md;   
//     }
//     // cout<<index<<" "<<count<<" "<<remain<<endl; 
//     return dp[index][remain] = count%md; 
// }

// int dp[100][100005]; 
void solve(){

    ll n , k; 
    cin>>n>>k; 
    int md = 1e9 + 7; 
    vector < ll > arr(n); 
    for(int i = 0 ; i < n ; i++) cin>>arr[i]; 

    vector < vector < ll > > dp(100 , vector < ll > (100005 , 0)); 
    // memset(dp , 0 , sizeof(dp)); 

    // prefix sum DP;

    for(int i = 0 ; i <= arr[0] ; i++){
        dp[0][i] = 1; 
    }

    for(int i = 0 ; i < n ; i++) dp[i][0] = 1; 
    for(int i = 1 ; i < n ; i++){

        vector < ll > prefix_sum(k+1); 
        prefix_sum[0] = dp[i-1][0] % md; 
        // build a prefix sum so that for each index from (0 to K) 
        // you don't have to iterate k times again. 

        for(int j = 1 ; j <= k ; j++){
            prefix_sum[j] = (prefix_sum[j-1] % md + dp[i-1][j] % md) % md; 
        }

        for(int j = 0 ; j <= k ; j++){
            if((j - 1) >= arr[i])
                dp[i][j] = (prefix_sum[j] + md  - prefix_sum[j - arr[i] - 1])%md; 
            else dp[i][j] = prefix_sum[j] % md; 
        }
    }

    ll ans = dp[n-1][k] % md; 
    cout<<ans<<endl; 
}
int main(){

solve(); 

}