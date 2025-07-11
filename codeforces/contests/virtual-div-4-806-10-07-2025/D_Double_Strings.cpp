#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> arr(n);
    map<string, int> valores;
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
        valores[arr[i]]++;
    }

    string a;
    deque<char> b;

    vector<bool> foi(n, 0);

    for (int i = 0; i < n; i++){
        a += arr[i][0];

        for (int j = 1; j < arr[i].size(); j++){
            b.push_back(arr[i][j]);
        }

        int l = 0;
        while(b.size() > 0){
            string s;
            for (auto k = b.begin(); k < b.end(); k++){
                s += *k;
            }

            if (valores[a] > 0 && valores[s] > 0){
                foi[i] = 1;
                break;
            }
            else {
                l++;
                if (l >= arr[i].size()) {
                    break;
                }
                a += arr[i][l];
                b.pop_front();
            }
        }
        a.clear();
        b.clear();
    }
    
    for (int i = 0; i < n; i++){
        if (foi[i] == 1){
            cout << 1;
        }
        else cout << 0;
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