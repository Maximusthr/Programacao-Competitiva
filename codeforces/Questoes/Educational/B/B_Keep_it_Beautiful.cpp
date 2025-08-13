#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> val;
    val.push_back(arr[0]);

    cout << 1;

    bool foi = false;
    for (int i = 1; i < n; i++){
        if (arr[i] >= val.back()){
            if (foi){
                if (arr[i] >= val.back() && arr[i] <= val[0]){
                    cout << 1;
                    val.push_back(arr[i]);
                }
                else cout << 0;
            }
            else {
                cout << 1;
                val.push_back(arr[i]);
            }
        }

        else if (!foi && arr[i] < val.back() && arr[i] <= val[0]){
            foi = true;
            cout << 1;
            val.push_back(arr[i]);
        }
        else {
            cout << 0;
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}