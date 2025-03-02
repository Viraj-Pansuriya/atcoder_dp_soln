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


bool check(vector < ll > & arr , int bro , ll remain , vector < vector < ll > > &dp){
    if(remain == 0) return false; 
    bool win = false;
    if(dp[bro][remain] != -1) return dp[bro][remain]; 
    
    for(int i = 0 ; i < arr.size() ; i++){
        bool curr = true;
        if(arr[i] <= remain){
            curr = check(arr , 1 - bro , remain - arr[i] , dp);
            // here you have given all possible 
            // ways , now if in each ways opponent wins , then my current bro will gonna loose game. 
            if(curr == false) return dp[bro][remain] =  true; 
        } 
    }
    return dp[bro][remain] = false; 

}

void solve(){

    ll n , k ; 
    cin>>n>>k; 
    vector < ll > arr(n); 
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

    vector < vector < bool > > dpTable(2 , vector < bool > (k+1 , false)); 
    for(int p = 1 ; p <=k ; p++){
        for(int i = 0 ; i < 2 ; i++){
            bool curr = true; 
            for(int q = 0 ; q < arr.size(); q++){
                if(arr[q] <= p){
                    curr = curr & dpTable[1-i][p-arr[q]]; 
                }
            }
            dpTable[i][p] = 1 - curr;  
        }
    }
    bool ans = dpTable[0][k]; 
    if(ans) cout<<"First"<<endl; 
    else cout<<"Second"<<endl; 
    
}

int main(){
    solve(); 
}