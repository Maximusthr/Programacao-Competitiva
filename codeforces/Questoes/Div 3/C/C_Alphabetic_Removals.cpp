#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    string s; cin >> s;

    map<char, queue<int>> mapa;

    for (int i = 0; i < n; i++){
        mapa[s[i]].push(i);
    }

    char aux = 'a';
    int last = 0;
    bool entrou = false;
    for (int i = 0; i < 26; i++){
        while (!mapa[aux].empty()){
            if (k == 0){
                last = mapa[aux].front();
                entrou = true;
                break;
            }
            mapa[aux].pop();
            k--;
        }
        if (entrou) break;
        aux++;
    }

    for (int i = 0; i < n; i++){
        if (s[i] > aux) continue;
        if (s[i] == aux && i >= last) continue;

        s[i] = '.';
    }

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.') continue;
        cout << s[i];
    }
    cout << "\n";
}