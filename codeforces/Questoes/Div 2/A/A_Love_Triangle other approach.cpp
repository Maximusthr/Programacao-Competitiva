#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int c = 0;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    bool ok = false;
    for (int i = 1; i <= n; i++){
        if (i == arr[arr[arr[i]]]) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
}
