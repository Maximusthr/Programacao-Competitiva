#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> num;
    vector<int> arr(2*n);
    for (auto &i : arr) {
        cin >> i;
        num[i]++;
    }
    
    vector<pair<int, int>> especial;
    vector<pair<int, int>> nao;

    vector<pair<int, int>> par, impar;

    for (auto [x, y] : num){
        if (y % 2 == 0){
            if (y/2 % 2){
                especial.push_back({x, y});
            }
            else {
                // nao.push_back({x, y});
                par.push_back({x, y});
            }
        }
        // else nao.push_back({x, y});
        else impar.push_back({x, y});
    }

    // 1 2 3 4 5 4 1 4 1 5 4 6
    // 1 1 1
    // 2
    // 3
    // 4 4 4 4
    // 5 5
    // 6

    for (int i = 0; i < par.size(); i++){
        nao.push_back(par[i]);
    }
    for (int i = 0; i < impar.size(); i++){
        nao.push_back(impar[i]);
    }

    // sort(nao.begin(), nao.end(), [&](pair<int, int> &a, pair<int, int> &b){
    //     // if (a.second != b.second) return a.second > b.second;
    //     // else a.first < b.first;
    // });

    vector<int> conj_1, conj_2;

    int ans = (especial.size() * 2);

    auto add = [&](vector<int> &conj1, vector<int> &conj2, vector<pair<int, int>> &elem, int idx) -> void {
        for (int i = 0; i < elem[idx].second/2 + 1; i++){
            conj1.push_back(elem[idx].first);
        }
        for (int i = 0; i < elem[idx].second/2 - 1; i++){
            conj2.push_back(elem[idx].first);
        }
    };

    auto add_impar = [&](vector<int> &conj1, vector<int> &conj2, vector<pair<int, int>> &elem, int idx) -> void {
        for (int i = 0; i < elem[idx].second/2 + 1; i++){
            conj1.push_back(elem[idx].first);
        }
        for (int i = 0; i < elem[idx].second/2; i++){
            conj2.push_back(elem[idx].first);
        }
    };

    for (int i = 0; i < nao.size(); i++){
        if (i == nao.size() - 1){
            // equilibro maximo
            
            if (nao[i].second % 2 == 0){
                if (conj_1.size() < conj_2.size()){

                    add(conj_1, conj_2, nao, i);

                }
                else if (conj_1.size() > conj_2.size()){
                    
                    add(conj_2, conj_1, nao, i);

                }
                else {

                    for (int j = 0; j < nao[i].second/2; j++){
                        conj_1.push_back(nao[i].first);
                    }
                    for (int j = 0; j < nao[i].second/2; j++){
                        conj_2.push_back(nao[i].first);
                    }

                }
            }
            else {
                assert(conj_1.size() != conj_2.size());

                if (conj_1.size() < conj_2.size()){
                    add_impar(conj_1, conj_2, nao, i);
                }
                else {
                    add_impar(conj_2, conj_1, nao, i);
                }
            }
            
            break;
        }

        if (conj_1.size() <= conj_2.size()){
            if (nao[i].second % 2 == 0){

                add(conj_1, conj_2, nao, i);

            }
            else {

                add_impar(conj_1, conj_2, nao, i);

            }
        }
        else {
            if (nao[i].second % 2 == 0){

                add(conj_2, conj_1, nao, i);

            }
            else {

                add_impar(conj_2, conj_1, nao, i);

            }
        }
    }

    // assert(conj_1.size() == n);
    // assert(conj_2.size() == n);

    map<int, int> freq_1, freq_2;
    for (int i = 0; i < conj_1.size(); i++){
        freq_1[conj_1[i]]++;
    }
    for (int i = 0; i < conj_2.size(); i++){
        freq_2[conj_2[i]]++;
    }

    for (auto [x, y] : freq_1){
        if (y%2) ans++;
    }
    for (auto [x, y] : freq_2){
        if (y%2) ans++;
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}