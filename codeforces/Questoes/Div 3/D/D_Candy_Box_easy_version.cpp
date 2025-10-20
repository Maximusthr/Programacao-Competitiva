#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<bool> foi(MAX);

    int ans = 0;
    int sub = 1, muda = 1;
    
    int i = 0;
    while (i < n){
        if (i+1 < n){
            if (arr[i] == arr[i+1]){
                muda++;
                if (!foi[muda]) sub = muda;
            }
            else {
                if (!foi[sub]) {
                    foi[sub] = true;
                    ans += sub;
                }
                muda = 1;
                sub = 1;
            }
        }
        else {
            if (!foi[sub]) {
                foi[sub] = true;
                ans += sub;
            }
        }
        i++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}