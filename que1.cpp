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
    ll n; 
    cin>>n; 
    vector < ll > arr(n); 
    for(int i = 0 ; i < n ; i++) cin>>arr[i]; 

    vector < ll > dp(n); 
    dp[0] = 0; 
    // either take from (i-1)th  OR (i-2)th index, 

    for(int i = 1 ; i < arr.size() ; i++){
        int a = dp[i-1] + abs(arr[i] - arr[i-1]); 
        int b = INT_MAX; 
        if(i > 1) b = dp[i-2] + abs(arr[i] - arr[i-2]); 
        dp[i] = min(a , b);
    }

    cout<<dp.back()<<endl; 

}
int main(){
    ll t = 1; 
    // cin>>t; 
    while(t--) solve(); 
}