#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    map<int, int> val;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        val[arr[i]]++;
    }

    for (int i = 0; i < n; i++){
        if ((n-2) % arr[i] == 0){
            if ((n-2)/arr[i] == arr[i] && val[arr[i]] >= 2){
                cout << arr[i] << " " << arr[i] << "\n";
                return;
            }
            else if ((n-2)/arr[i] != arr[i]){
                if (val[(n-2)/arr[i]] >= 1){
                    cout << arr[i] << " " << (n-2)/arr[i] << "\n";
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}