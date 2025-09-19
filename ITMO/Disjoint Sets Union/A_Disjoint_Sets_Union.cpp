#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;
vector<int> p(MAX);
vector<int> r(MAX);

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
    }
    else {
        p[a] = b;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++){
        p[i] = i;
    }

    for (int i = 0; i < m; i++){
        string a;
        int x, y;
        cin >> a >> x >> y;
        x--, y--;

        if (a == "union"){
            union_set(x, y);
        }
        else {
            if (get(x) == get(y)){
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }
    }
}