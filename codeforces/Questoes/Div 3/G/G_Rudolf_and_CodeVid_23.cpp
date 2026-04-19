#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int transform(string &med){
    int mask1 = 0;
    for (int i = 0; i < med.size(); i++){
        if (med[i] == '1') mask1 += (1 << i);
    }
    return mask1;
}

struct P {
    int days;
    string med, sint;

    bool operator>(P const p) const {   
        return days > p.days;
    };
};

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<P> medic(m);
    for (int i = 0; i < m; i++){
        int d; cin >> d;
        string med, sint; cin >> med >> sint;
        medic[i] = {d, med, sint};
    }
   
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> vis(1 << n, INF);

    pq.push({0, s});

    int ini = transform(s);
    vis[ini] = 0;

    int days = INF;
    while(!pq.empty()){
        int d = pq.top().days;
        string med = pq.top().med;

        pq.pop();

        for (int i = 0; i < n; i++){
            if (med[i] != '0') break;
            if (i + 1 == n) {
                cout << d << "\n";
                return;
            }
        }

        for (int i = 0; i < m; i++){
            string md = medic[i].med;
            string st = medic[i].sint;
            int total = d + medic[i].days;

            string aux = med;
            
            for (int j = 0; j < n; j++){
                if (aux[j] == '1' && md[j] == '1') aux[j] = '0';
                else if (aux[j] == '0' && st[j] == '1') aux[j] = '1';
            }
            
            int mask = transform(aux);
            if (total >= vis[mask]) continue;
            vis[mask] = d + medic[i].days;

            pq.push({total, aux});
        }
    }

    if (days == INF){
        cout << -1 << "\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}