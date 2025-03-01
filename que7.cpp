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

ll check(ll curr , vector < ll > adj[] , vector < ll > & dp){

    if(dp[curr] != -1) return dp[curr]; 

    dp[curr] = 0; // this is life saving trick : no need to keep visit track. 
    int count = 0; 

    for(auto & nxt : adj[curr]){
        int val = check(nxt , adj , dp); 
        count = max(val , count); 
    }

    return dp[curr] = count + 1;  
}


void solve(){
    ll n , m; 
    cin>>n>>m; 
    vector < ll > adj[n+1]; 

    for(int i = 0 ; i < m ; i++){
        ll x , y; cin>>x>>y; 
        adj[x].push_back(y); 
    }

    vector < ll > dp(n+1 , -1);

    // find a longest path in it. 
    // can maintain a visit array , and make a appropriate choise ?? 

    ll ans = 0; 
    for(int i = 1 ; i <= n ; i++){
        ll val = check(i , adj ,dp); 
        ans = max(ans , val); 
    }
    cout<<ans-1<<endl; 

}
int main() {
    solve(); 
}