#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    set<int> pos {0, n};
    multiset<int> dist{n};

    for (int i = 0; i < m; i++){
        int x; cin >> x;

        auto it1 = pos.upper_bound(x);
        auto it2 = it1;
        it2--;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(x - *it2);
        dist.insert(*it1 - x);

        pos.insert(x);

        cout << *(--dist.end()) << " \n"[i == m-1];
    }
}