#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    if (a == b && b == c){
        cout << "YES" << "\n";
        return;
    }

    vector<int> arr = {a, b, c};
    
    sort(arr.begin(), arr.end());

    int oper = 0;
    while(oper < 3){
        int v = arr.back();
        arr.pop_back();
        arr.push_back(arr[0]);
        arr.push_back(v - arr[0]);

        sort(arr.begin(), arr.end());

        bool ok = true;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] != arr[i-1]){
                ok = false;
                break;
            }
        }
        if (ok){
            cout << "YES" << "\n";
            return;
        }

        oper++;
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}