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


void solve(){
    ll n , k; 
    cin>>n>>k; 
    vector < ll > arr(n); 
    for(int i = 0; i < n ; i++) cin>>arr[i]; 
    vector  < ll > dp(n); 
    dp[0] = 0; 
    for(int i = 1 ; i < n ; i++){
        int mini = INT_MAX; 
        for(int p = 1 ; p <= k && (i-p >= 0) ; p++){
            int a = dp[i-p]  + abs(arr[i] - arr[i-p]); 
            mini = min(mini , a); 
        }
        dp[i] = mini; 
    }
    cout<<dp.back()<<endl; 
}

int main(){
    ll t  = 1; 
    // cin>>t; 
    while(t--) solve(); 
}