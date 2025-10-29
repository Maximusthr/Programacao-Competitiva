// upsolve
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> color;

void dfs(int u, int c){
    if (color[u] == -1) color[u] = c;

    for (auto v : g[u]){
        if (color[v] == -1){
            dfs(v, c^1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    g.resize(n);
    color.assign(n, -1);

    set<pair<int, int>> usou;

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        usou.insert({x, y});
        usou.insert({y, x});
    }

    dfs(0, 0);

    vector<int> zero, um;
    for (int i = 0; i < n; i++){
        if (color[i] == 0) zero.push_back(i);
        else um.push_back(i);
    }

    int qtd = (zero.size() * um.size()) - n + 1;

    set<pair<int, int>> use;
    
    for (int i = 0; i < zero.size(); i++){
        for (int j = 0; j < um.size(); j++){
            if (!use.count({zero[i], um[j]}) && !use.count({um[j], zero[i]})){
                use.insert({zero[i], um[j]});
                use.insert({um[j], zero[i]});
            }
        }
    }
    
    vector<pair<int, int>> arr = {use.begin(), use.end()};

    auto query = [&]() -> pair<int, int> {
        int x, y; cin >> x >> y;
        return {x, y};
    };
    auto answer = [&]() -> void {
        for (int i = 0; i < arr.size(); i++){
            if (!usou.count({arr[i].first, arr[i].second}) && !usou.count({arr[i].second, arr[i].first})){
                usou.insert({arr[i].first, arr[i].second});
                usou.insert({arr[i].second, arr[i].first});

                cout << arr[i].first + 1 << " " << arr[i].second + 1 << endl;
                return;
            }
        }
    };
    
    if (qtd % 2){
        cout << "First" << endl;
        while(true){
            answer();

            pair<int, int> talvez = query();
            if (talvez.first == -1 && talvez.second == -1) {
                break;
            }
            usou.insert({talvez.first - 1, talvez.second - 1});
            usou.insert({talvez.second - 1, talvez.first - 1});
        }   

    }
    else {
        cout << "Second" << endl;
        while(true){
            pair<int, int> talvez = query();
            if (talvez.first == -1 && talvez.second == -1) {
                break;
            }
            usou.insert({talvez.first - 1, talvez.second - 1});
            usou.insert({talvez.second - 1, talvez.first - 1});
            
            answer();
        }
    }
}