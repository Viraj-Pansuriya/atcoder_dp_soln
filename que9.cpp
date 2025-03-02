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



double check(vector < double > & arr , ll need , ll index , vector < vector < double > > & dp){

    if(index == arr.size()) return need == 0;  

    double pick = 0;
    if(dp[index][need] != -1) return dp[index][need];  
    if(need){
        pick = (arr[index]) * check(arr , need - 1, index+1 , dp); 
    } 
    double notPick = 0; 
    notPick = (1-arr[index]) * check(arr , need , index+1 , dp); 

    return dp[index][need] = pick + notPick; 
}

void solve(){
    ll n; cin>>n;

    vector < double > arr(n); 
    for(int i= 0 ; i < n ; i++) cin>>arr[i]; 
    ll req = (n + 1)/2; 
    double ans = 0; 
    vector < vector < double > > dp(n+1 , vector < double > (n+1 , -1)); 
    for(ll i = req ; i <= n ; i++){
        ans += check(arr , i , 0, dp);
    }
    cout.precision(10);
    cout<<ans<<endl; 
}
int main(){
    solve(); 
}