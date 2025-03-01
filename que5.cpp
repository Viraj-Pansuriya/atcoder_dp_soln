#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

void solve(){
    ll n, w; 
    cin >> n >> w; 
    vector <pair<ll, ll> > arr(n); 

    // Read the weight and value for each item
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first; // weight
        cin >> arr[i].second; // value
    }
    
    // Maximum possible value we can have (sum of all values)
    ll maxValue = 0;
    for (int i = 0; i < n; i++) {
        maxValue += arr[i].second;
    }

    // DP array for storing minimum weight required to achieve a certain value
    vector<vector<ll> > dp(n + 1, vector<ll>(maxValue + 1, LLONG_MAX));
    dp[0][arr[0].second] = arr[0].first;  // Base case: 0 value with 0 items requires 0 weight
    for(int i = 0 ; i < n ; i++){
        dp[i][0]= 0; 
    }
    
    // Filling the DP table
    for (int i = 1; i <= n; i++) {
        for (int value = 0; value <= maxValue; value++) {
            // If we don't pick the current item, carry forward the previous result
            dp[i][value] = dp[i-1][value];
            
            // If we pick the current item, check if it is feasible
            if (value >= arr[i].second && dp[i-1][value - arr[i].second] != LLONG_MAX) {
                dp[i][value] = min(dp[i][value], dp[i-1][value - arr[i].second] + arr[i].first);
            }
        }
    }
    
    // Now we need to find the maximum value that can be achieved within weight <= w
    ll ans = 0;
    for (ll value = maxValue; value >= 0; value--) {
        if (dp[n-1][value] <= w) {
            ans = value;
            break;
        }
    }

    cout << ans << endl; 
}

int main() {
    solve(); 
}
