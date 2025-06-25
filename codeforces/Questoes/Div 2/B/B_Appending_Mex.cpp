#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    bool ok = true;
    int inicio = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] <= inicio){
            if (arr[i] == inicio) inicio++;
        }
        else {
            cout << i+1 << "\n";
            ok = false;
            break;
        }
    }
    if (ok) cout << -1 << "\n";
}
