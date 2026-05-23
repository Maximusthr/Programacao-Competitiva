#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    int n = s.size();

    vector<int> freq(26);
    for (int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }

    string ans = "#";

    while(true){
        pair<char, int> maior = {'#', 0};
        pair<char, int> seg_maior = {'#', 0};
        for (int i = 0; i < 26; i++){
            if (freq[i] == 0) continue;

            if (freq[i] > maior.second) {
                seg_maior = maior;
                maior = {i + 'a', freq[i]};
            }
            else if (freq[i] > seg_maior.second){
                seg_maior = {i + 'a', freq[i]};
            }
        }
        if (maior.first != ans.back()){
            ans.push_back(maior.first);
            freq[maior.first - 'a']--;
        }
        else {
            ans.push_back(seg_maior.first);
            freq[seg_maior.first - 'a']--;
        }

        if(maior.first == '#') break;
    }

    for (int i = 1; i < ans.size()-1; i++){
        if (ans[i] == ans[i-1] || ans[i] == '#'){
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
    for (int i = 1; i < ans.size()-1; i++){
        cout << ans[i];
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