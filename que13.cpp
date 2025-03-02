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


ll check(vector < ll > & arr  , vector < ll > & prefix , int left , int right , vector < vector < ll > > & dp){
    if(left == right) return 0; 
    ll ans = LONG_MAX; 
    if(dp[left][right] != -1) return dp[left][right]; 
    for(int i = left ; i < right ; i++){
        ans = min(ans , check(arr ,prefix , left , i , dp) + check(arr , prefix , i+1 , right , dp) + prefix[right+1] - prefix[left]);
    }

    return  dp[left][right]= ans; 

}

void solve(){

    ll n; cin>>n; 
    vector < ll > arr(n); 
    for(int i = 0 ; i < n ; i++) cin>>arr[i]; 

    vector < ll > prefix(n+1 , 0); 
    for(int i = 1 ; i <= n ; i++) prefix[i] = prefix[i-1] + arr[i-1]; 
    vector < vector < ll > > dp(n+1 , vector < ll > (n + 1 , LONG_MAX)); 

    for(int i = 0 ; i < n ; i++) dp[i][i] = 0; 

    for(int len = 2 ; len <= n ; len++){
        for(int i = 0 , j = len-1 ; j < n ; i++ , j++){
           for(int split = i ; split < j ; split++){
                dp[i][j] = min(dp[i][j] , dp[i][split] + dp[split+1][j] + prefix[j+1] - prefix[i]); 
           }
        }
    }

    ll ans = dp[0][n-1]; 
    cout<<ans<<endl; 
}
int main(){
    solve(); 
}