#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> box(n+1);
    vector<int> ans;

    for (int i = 0; i < m; i++){
        int x; cin >> x;
        if (x > 0) {
            box[x]++;
            ans.push_back(x);
        }
        else {
            pair<int, int> pos = {0, INF};
            for (int j = 1; j <= n; j++){
                if (box[j] < pos.second) {
                    pos.first = j;
                    pos.second = box[j];
                }
            }
            box[pos.first]++;
            ans.push_back(pos.first);
        }
    }

    for (auto i : ans) cout << i << " ";
    cout << "\n";
}