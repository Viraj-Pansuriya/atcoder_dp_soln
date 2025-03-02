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
const int md = 1e9 + 7; 

ll dp[21][1<<21 + 1]; 

ll check(int index , vector < vector < int > > & arr , ll mask){

    if(index == arr.size()) return 1; 
    if(dp[index][mask] != -1) return dp[index][mask]; 
    ll ans = 0; 
    for(int i = 0 ; i < arr.size() ; i++){
        ll wmn = (arr.size()-i-1); 
        if( ((mask & (1<<wmn)) == 0) && arr[index][i] == 1){
            ans = (ans % md + check(index + 1 , arr , mask | (1 <<wmn)) % md) % md; 
        }
    }
    return dp[index][mask]= ans % md; 
}

void solve(){

    ll n; cin>>n; 

    vector <  vector < int > > arr(n , vector < int > (n)); 

    memset(dp , -1 , sizeof(dp));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin>>arr[i][j]; 
        }
    }


    ll ans = check(0 , arr , 0); 

    cout<<ans<<endl; 






}
int main(){
    solve(); 
}