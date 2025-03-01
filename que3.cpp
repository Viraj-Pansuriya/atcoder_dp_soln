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
    ll n ; cin>>n; 
    vector < vector < ll > > arr(n , vector < ll > (3)); 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++) cin>>arr[i][j]; 
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < 3 ; j++){
            ll maxi = 0; 
            for(int prev = 0 ; prev < 3 ; prev++){
                if(j == prev) continue; 
                maxi = max(maxi , arr[i-1][prev]);
            }
            arr[i][j] += maxi; 
        }
    }

    ll maxi = 0 ; 
    for(int i = 0 ; i < 3 ; i++){
        maxi = max(maxi , arr[n-1][i]); 
    }

    cout<<maxi<<endl; 



}
int main(){
    solve(); 
}