#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<int> sz;
    vector<int> xp;

    DSU (int n) : p(n), sz(n, 1), xp(n) {
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        while (a != p[a]){
            a = p[a];
        }
        return a;
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        xp[a] -= xp[b];
    }

    void add(int a, int points){
        xp[get(a)] += points;
    }

    int points(int a){
        int sum = xp[a];
        while (a != p[a]){
            a = p[a];
            sum += xp[a];
        }
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    DSU players(n);

    while(q--){
        string x; cin >> x;

        if (x == "add"){
            int a, points; cin >> a >> points;
            a--;
            players.add(a, points);
        }
        else if (x == "join"){
            int a, b; cin >> a >> b;
            a--, b--;
            players.merge(a, b);
        }
        else {
            int a; cin >> a;
            a--;
            
            cout << players.points(a) << "\n";
        }
    }
}