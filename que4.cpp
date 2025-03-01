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



ll check(vector < pair < int , int > > & arr  , ll w , int index){
    if(w <= 0) return 0; 
    if(index >= arr.size()) return 0; 
    // check by picking this what values you would get 
    // what happends if you leave this current index element.
    ll pick = INT_MIN , notPick = INT_MIN; 

    if(arr[index].first <= w){
        pick = arr[index].second + check(arr , w - arr[index].first , index+ 1); 
    }
    notPick = check(arr , w , index+1); 
    return max(pick  , notPick); 
}


void solve(){

    ll n , w; 
    cin>>n>>w; 
    vector < pair < int , int > > arr(n); 

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i].first; 
        cin>>arr[i].second; 
    }

    vector < vector < ll > > dp(n , vector < ll > (w+1));
    // think about base case : 
    for(int i = arr[0].first ; i <= w; i++){
        dp[0][i] = arr[0].second; 
    } 

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j <=w ; j++){
            ll pick = 0 , notPick = 0; 
            notPick = dp[i-1][j]; 
            if(arr[i].first <= j){
                pick = arr[i].second  + dp[i-1][j-arr[i].first];
            }
            dp[i][j] = max(pick , notPick); 
        }
    }



    

    ll ans = dp[n-1][w]; 
    cout<<ans<<endl; 


    // x1 x2 x3 x4 x5 x6 x7 x8


}
int main(){
    solve(); 
}