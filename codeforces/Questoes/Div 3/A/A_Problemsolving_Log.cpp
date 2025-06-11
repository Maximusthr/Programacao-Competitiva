#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        
        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        map<char, int> alf;
        for (int i = 1; i <= 26; i++){
            alf[alfabeto[i-1]] = i;
        }

        int ans = 0;
        map<char, int> res; 
        for (int i = 0; i < n; i++){
            res[s[i]]++;
        }

        for (auto [x, y] : res){
            if (y >= alf[x]) ans++;
        }

        cout << ans << "\n";
    }

}