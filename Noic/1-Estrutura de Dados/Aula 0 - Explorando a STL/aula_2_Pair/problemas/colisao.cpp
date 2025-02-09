#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int, int>> pontos1;
    vector<pair<int, int>> pontos2;

    int x0, x1, y0, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    pontos1.push_back({x0, y0});
    pontos1.push_back({x1, y1});

    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    pontos2.push_back({x2, y2});
    pontos2.push_back({x3, y3});

    if (pontos2[0].first <= pontos1[1].first && pontos2[0].second <= pontos2[1].second && pontos2[1].first >= pontos1[0].first && pontos2[1].second >= pontos1[0].first) cout << "1" << "\n";
    else cout << "0" << "\n";
}
