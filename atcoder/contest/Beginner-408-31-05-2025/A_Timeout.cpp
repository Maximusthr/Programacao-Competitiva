#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, s; cin >> n >> s;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    if (arr[0] > s) ok = false;
    for (int i = 0; i < n-1; i++){    
        if (arr[i] + s < arr[i+1]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";

}