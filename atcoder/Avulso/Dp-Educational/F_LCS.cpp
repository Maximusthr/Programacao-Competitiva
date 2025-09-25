#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s, t; cin >> s >> t;

    vector<vector<int>> lcs_size(s.size() + 1, vector<int> (t.size() + 1));

    for (int i = s.size()-1; i >= 0; i--){
        for (int j = t.size()-1; j >= 0; j--){
            if (s[i] == t[j]){
                lcs_size[i][j] = 1 + lcs_size[i+1][j+1];
            }
            else if (s[i] != t[j]){
                lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
            }
        }
    }

    // for (int i = 0; i < s.size(); i++){
    //     for (int j = 0; j < t.size(); j++){
    //         cout << lcs_size[i][j] << " \n"[j == t.size()-1];
    //     }
    // }

    string lcs;

    int i = 0, j = 0;
    while(i < s.size() && j < t.size()){
        if (s[i] == t[j]){
            lcs.push_back(s[i]);
            i++, j++;
        }
        else if(lcs_size[i+1][j] > lcs_size[i][j+1]) i++;
        else j++;
    }

    cout << lcs << "\n";
}