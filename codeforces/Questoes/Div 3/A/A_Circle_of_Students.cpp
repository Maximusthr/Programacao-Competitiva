#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    // clockwise?
    bool ok = false;
    bool pode = true;
    for (int i = 0; i < n; i++){
        if (arr[i] == n){
            ok = true;
            continue;
        }
        else if (i == 0) continue;
        if (!ok && arr[i]-1 != arr[i-1]){
            pode = false;
            break;
        }
        else if (ok){
            if (arr[i-1] == n){
                if (arr[i] != 1){
                    pode = false;
                    break;
                }
            }
            else if (arr[i]-1 != arr[i-1]){
                pode = false;
                break;
            }
        }
    }

    if (pode) {
        cout << "YES" << "\n";
        return;
    }

    pode = true;
    ok = false;

    for (int i = 0; i < n; i++){
        if (arr[i] == 1){
            ok = true;
            continue;
        }
        else if (i == 0) continue;
        if (!ok && arr[i]+1 != arr[i-1]){
            pode = false;
            break;
        }
        else if (ok){
            if (arr[i-1] == 1){
                if (arr[i] != n){
                    pode = false;
                    break;
                }
            }
            else if (arr[i]+1 != arr[i-1]){
                pode = false;
                break;
            }
        }
    }

    cout << (pode ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
