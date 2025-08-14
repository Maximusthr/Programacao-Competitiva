#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

set<char> carac;
void verif(map<char, int> &tic, int &solo){
    int dif = 0;
    vector<char> t;
    for (auto [x, y] : tic) {
        dif++;
        t.push_back(x);
    }
    if (dif == 1 && carac.find(t[0]) == carac.end()){
        solo++;
        carac.insert(t[0]);
    }
    
    tic.clear();
}

set<pair<char, char>> teams_carac;
void v_team(map<char, int> &tic, int &teams){
    int dif = 0;
    vector<char> t;
    for (auto [x, y] : tic) {
        dif++;
        t.push_back(x);
    }
    if (dif == 2 && (teams_carac.find({t[0], t[1]}) == teams_carac.end())){
        teams++;
        teams_carac.insert({t[0], t[1]});
    }

    tic.clear();
}

void solve(){
    vector<string> s(3);

    for (int i = 0; i < 3; i++) cin >> s[i];
    map<char, int> cows;

    int solo = 0;
    // linha
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) cows[s[i][j]]++;
        verif(cows, solo);
    }

    // coluna
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) cows[s[j][i]]++;        
        verif(cows, solo);
    }

    // main diag
    for (int i = 0; i < 3; i++) cows[s[i][i]]++;
    verif(cows, solo);

    // sec diag
    for (int i = 0, j = 2; i < 3; i++, j--) cows[s[i][j]]++;
    verif(cows, solo);


    int team = 0;
    // linha
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) cows[s[i][j]]++;
        v_team(cows, team);
    }

    // coluna
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) cows[s[j][i]]++;
        v_team(cows, team);
    }

    // main diag
    for (int i = 0; i < 3; i++) cows[s[i][i]]++;
    v_team(cows, team);

    // sec diag
    for (int i = 0, j = 2; i < 3; i++, j--) cows[s[i][j]]++;
    v_team(cows, team);
        
    cout << solo << "\n";
    cout << team << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    solve();
}
