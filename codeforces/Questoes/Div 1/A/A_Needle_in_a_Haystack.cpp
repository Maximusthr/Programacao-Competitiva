#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s, t;
    cin >> s >> t;

    vector<int> freq1(26), freq2(26);
    for (int i = 0; i < s.size(); i++){
        freq1[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++){
        freq2[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        if (freq1[i] > freq2[i]){
            cout << "Impossible" << "\n";
            return;
        }
    }

    string ans;
    int j = 0;
    for (int i = 0; i < s.size(); i++){
        while(s[i] - 'a' > j){
            int k = 0;
            for (; k < freq2[j] - freq1[j]; k++){
                ans.push_back(j + 'a');
            }
            freq2[j] -= k;
            k = 0;
            j++;
        }
        freq1[s[i]-'a']--;
        freq2[s[i]-'a']--;
        ans.push_back(s[i]);
        j = 0;
    }
    for (int i = 0; i < 26; i++){
        while(freq2[i] > 0){
            ans.push_back('a' + i);
            freq2[i]--;
        }
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