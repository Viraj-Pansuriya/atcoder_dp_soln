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


ll check(vector < ll > & arr , int bro , ll left , ll right , vector < vector < vector < ll > > > &dp){

    if(left > right) return 0; 

    if(dp[left][right][bro] != LONG_MAX) return dp[left][right][bro]; 
    if(bro == 0){
        // Taro: 
        ll takeFirst = arr[left] + check(arr , 1 - bro , left+1 , right , dp); 
        ll takeLast = arr[right] + check(arr , 1 - bro , left , right-1 , dp); 
        return dp[left][right][bro] = max(takeFirst , takeLast); 
    }
    else{
        // Jiro: 
        ll takeFirst = check(arr , 1 - bro , left+1 , right , dp) - arr[left];
        ll takeLast =  check(arr , 1 - bro , left , right-1 , dp) - arr[right]; 
        return  dp[left][right][bro] = min(takeFirst , takeLast); 
    }

}

void solve(){

    ll n; cin>>n; 
    vector < ll > arr(n); 
    for(int i = 0 ; i < n ; i++) cin>>arr[i]; 

    vector < vector < vector < ll > > > dp(3000 , vector < vector < ll > > (3000 , vector < ll > (2 , 0))); 

    for(int i = 0 ; i < n ;i++){
        dp[i][i][0] = arr[i];  
        dp[i][i][1] = -arr[i]; 
    }

    for(ll len = 2; len <= n; len++){
        for(int i = 0 ; i <= n - len ; i++){
            int j = i + len - 1; 
            dp[i][j][0] = max(arr[i] + dp[i+1][j][1]  , arr[j] + dp[i][j-1][1]); 
            dp[i][j][1] = min(dp[i+1][j][0] - arr[i] , dp[i][j-1][0] - arr[j]); 
        }
    }

    // logic such that each ppl tries to maximize their score and want to
   //  take out great outcome from that. 
    ll ans = dp[0][n-1][0];

    cout<<ans<<endl; 
 

}
int main(){
    solve(); 
}