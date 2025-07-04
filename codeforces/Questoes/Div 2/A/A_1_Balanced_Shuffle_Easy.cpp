#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct valor{
    int x, pos;
    char v;

    bool operator<(const valor &V){
        if (V.x != x){
            return x < V.x;
        }
        return pos > V.pos;
    };
};

void solve(){
    string s; cin >> s;

    int sum = 0;
    vector<valor> final;
    for (int i = 0; i < s.size(); i++){
        final.push_back({sum, i, s[i]});

        if (s[i] == '(') sum++;
        else if (s[i] == ')') sum--;
    }

    sort(final.begin(), final.end());

    for (int i = 0; i < final.size(); i++){
        cout << final[i].v;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}