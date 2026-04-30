#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr;
    vector<int> ext;
    vector<int> dois;
    vector<int> tres;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x % 6 == 0){
            ext.push_back(x);
        }
        else {
            if (x % 2 == 0) dois.push_back(x);
            else if (x % 3 == 0) tres.push_back(x);
            else arr.push_back(x);
        }
    }

    bool flag = false;
    if (dois.size() > tres.size()){
        flag = true;
        for (auto i : dois) cout << i << " ";
    }
    else for (auto i : tres) cout << i << " ";

    for (auto &i : arr) cout << i << " ";

    if (flag) for (auto &i : tres) cout << i << " ";
    else for (auto &i : dois) cout << i << " ";

    for (auto &i : ext) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}