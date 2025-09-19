#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+5;
vector<int> p(MAX);
vector<int> r(MAX);
vector<int> mx(MAX);
vector<int> mn(MAX);
vector<int> total(MAX, 1);

int get(int a){
    while (p[a] != a){
        a = p[a];
    }
    
    return a;
}

void union_set(int a, int b){
    a = get(a);
    b = get(b);

    if (a == b){
        return;
    }
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]){
        p[b] = a;
        mx[a] = max(mx[a], mx[b]);
        mn[a] = min(mn[a], mn[b]);
        total[a] += total[b];
    }
    else {
        p[a] = b;
        mx[b] = max(mx[a], mx[b]);
        mn[b] = min(mn[a], mn[b]);

        total[b] += total[a];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++){
        p[i] = i;
        mx[i] = i;
        mn[i] = i;
    }

    for (int i = 0; i < m; i++){
        string a; cin >> a;
        if (a == "union"){
            int x, y; cin >> x >> y;
            x--, y--;
            union_set(x, y);
        }
        else {
            int x; cin >> x; 
            x--;

            cout << mn[get(x)] + 1 << " " << mx[get(x)] + 1 << " " << total[get(x)] << "\n";
        }
    }
}