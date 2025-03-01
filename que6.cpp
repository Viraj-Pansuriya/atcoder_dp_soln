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
    string a , b; 
    cin>>a>>b; 
    int n = a.size();
    int m = b.size(); 

    vector < vector < int > > dp(n+1, vector < int > (m+1 , 0)); 

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]); 
        }
    }

    
    int i = n , j = m; 

    string ans = ""; 
    while(i > 0 && j > 0){

        if(a[i-1] == b[j-1]){
            ans += a[i-1]; 
            i--; 
            j--; 
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;  
        }
        else {
            j--;  
        }
    }
    reverse(ans.begin() , ans.end());
    cout<<ans<<endl; 


}
int main(){
    solve(); 
}