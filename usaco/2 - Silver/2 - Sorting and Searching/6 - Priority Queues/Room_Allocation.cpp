#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Room {
    int c, s;
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<pair<Room, int>> customers;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        customers.push_back({{a, b}, i});
    }

    sort(customers.begin(), customers.end(), [&](pair<Room, int> &a, pair<Room, int> &b){
        if (a.first.c != b.first.c) return a.first.c < b.first.c;
        return a.first.s < b.first.s;
    });

    vector<int> ans(n);

    using Sala = pair<int, int>;
    priority_queue<Sala, vector<Sala>, greater<Sala>> pq;

    int last_room = 0;
    for (int i = 0; i < n; i++){
        if (pq.empty() || pq.top().first >= customers[i].first.c){
            last_room++;
            pq.push({customers[i].first.s, last_room});
            ans[customers[i].second] = last_room;
        }
        else {
            Sala aux = pq.top();
            pq.pop();
            pq.push({customers[i].first.s, aux.second});
            ans[customers[i].second] = aux.second;
        }
    }

    cout << last_room << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}