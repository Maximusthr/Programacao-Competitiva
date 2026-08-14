#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n; cin >> n;
    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    map<int, vector<pair<string, int>>> carac;

    for (int i = 0; i < s.size(); i++){
        for (int j = 1; j <= 10; j++){
            if (i + j <= s.size()){
                string x = s.substr(i, j);
                
                bool flag = false;
                for (int k = 0; k < n; k++){
                    if (x == arr[k]){
                        flag = true;
                        carac[i].push_back({x, k+1});
                        break;
                    }
                }
                if (flag){
                    continue;
                }
            }
        }
    }

    vector<bool> foi(s.size());
    vector<pair<int, int>> ans;

    for (int i = 0; i < s.size(); i++){
        if (foi[i]) continue;
        else {
            int maior = 0;
            int id = 0;
            int pos = 0;
            string aux;
            if (carac[i].size() > 0){
                for (auto [x, y] : carac[i]){
                    if (x.size() > maior){
                        maior = x.size();
                        id = y;
                        aux = x;
                        pos = i;
                    }
                }
            }

            for (int j = i - 10; j < i; j++){
                if (j < 0) continue;
                for (int k = 1; k <= 10; k++){
                    int ue = s.size();
                    if (j + k > ue) break;
                    string zzz = s.substr(j, k);

                    if (carac[j].size() > 0){
                        for (auto [x, y] : carac[j]){
                            if (zzz == x){
                                int dif = i - j;
                                int ff = x.size() - dif;
                                if (maior < ff){
                                    maior = x.size() - dif;
                                    id = y;
                                    aux = x;
                                    pos = j;
                                }
                            }
                        }
                    }
                }
            }
            for (int k = i; k < i + maior; k++){
                foi[k] = true;
            }
            ans.push_back({id, pos+1});
        }
    }

    for (int i = 0; i < s.size(); i++){
        if (!foi[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
