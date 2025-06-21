#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    map<int, int> ocor;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ocor[a[i]]++;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    for (int i = n-1; i >= 0; i--){
        ocor[a[i]]--;
        if (a[i] == b[i]) continue;
        else {
            if (b[i] < 0){
                if (ocor[-1] > 0) a[i] = b[i];
            }
            else if (b[i] > 0){
                if (ocor[1] > 0) a[i] = b[i];
            }
            else if (b[i] == 0){
                if ((a[i] > 0 && ocor[-1] > 0) || (a[i] < 0 && ocor[1] > 0)) a[i] = 0;
            }
            
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}