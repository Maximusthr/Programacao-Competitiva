#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s; cin >> s;
    int ans = 0;

    string aux = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < aux.size(); i++){
        char y; // pares
        string temp;
        string temp2;
        bool found = false;
        for (int j = 0; j < s.size(); j++){
            if (aux[i] == s[j]){
                if (!found){
                    found = true;
                }
                else break;
            }
            else if (found) temp += s[j];
        }

        map<char, int> st;
        for (int j = 0; j < temp.size(); j++){
            st[temp[j]]++;
        }
        for (auto [x, y] : st){
            if (y == 1) ans++;
        }
    }

    cout << ans/2 << "\n";
}