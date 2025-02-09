#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<pair<int, int>, pair<int, int>>> pontos;

    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int xi, xf, yi, yf; cin >> xi >> xf >> yi >> yf;

        pontos.push_back({{xf, yf}, {xi, yi}});
    }

    int area = 0;
    for (int i = 0; i < qtd; i++){
        area += (pontos[i].first.first - pontos[i].second.first) * (pontos[i].first.second - pontos[i].second.second);
    }

    int interseccao = 0;
    for (int i = 0; i < qtd; i++){
        for (int j = 0; j < qtd; j++){
            if ((i != j) && (pontos[i].first.first <= pontos[j].first.first) && (pontos[i].first.second <= pontos[j].first.second)
                && (pontos[i].second.first >= pontos[j].second.first) && (pontos[i].second.second >= pontos[j].second.second))
            {
                interseccao += (pontos[i].first.first - pontos[i].second.first) * (pontos[i].first.second - pontos[i].second.second);
                break;
            }
            if ((i != j) && (pontos[i].first.first <= pontos[j].first.first) && (pontos[i].first.second <= pontos[j].first.second)
                && (pontos[i].second.first <= pontos[j].second.first) && (pontos[i].second.second <= pontos[j].second.second))
            {
                interseccao += (pontos[i].first.first - pontos[j].second.first) * (pontos[i].first.second - pontos[j].second.second);
                break;
            }
        }
    }
    cout << area - interseccao << "\n";
}
