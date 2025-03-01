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

    ll n , m; 
    cin>>n>>m; 

    vector < string > arr(n); 


    for(int i = 0 ; i < n ; i++){
        cin>>arr[i]; 
    }

    int md = 1e9 + 7; 

    vector < vector < ll > > dp(n , vector < ll > (m , 0)); 
    
    dp[0][0] = 1; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if((i == 0 && j == 0) || (arr[i][j] == '#')) continue; 
            if(i == 0) dp[i][j] += dp[i][j-1]; 
            else if(j == 0) dp[i][j] += dp[i-1][j]; 
            else {
                dp[i][j] = (dp[i][j] % md + dp[i-1][j] % md + dp[i][j-1] % md)% md; 
            }
        }
    }

    ll ans = dp[n-1][m-1] % md; 
    cout<<ans<<endl; 






}
int main(){
    solve(); 
}