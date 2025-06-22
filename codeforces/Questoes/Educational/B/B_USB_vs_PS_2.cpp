#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int a, b, both; cin >> a >> b >> both;

    int n; cin >> n;

    vector<pair<int, string>> p;

    for (int i = 0; i < n; i++){
        int t; cin >> t;
        string x; cin >> x;
        p.push_back({t, x});
    }

    vector<int> usb;
    vector<int> ps;
    for (int i = 0; i < n; i++){
        if (p[i].second == "USB") usb.push_back(p[i].first);
        else ps.push_back(p[i].first);
    }

    sort(usb.begin(), usb.end());
    sort (ps.begin(), ps.end());
    
    int count = 0;
    ll price = 0;

    for (int i = 0; i < usb.size() && a > 0; i++, a--){
        count++;
        price += usb[i];
        usb[i] = 0;
    }
    for (int i = 0; i < ps.size() && b > 0; i++, b--){
        count++;
        price += ps[i];
        ps[i] = 0;
    }

    vector<int> restante;
    for (int i = 0; i < usb.size(); i++){
        if (usb[i] > 0) restante.push_back(usb[i]);
    }
    for (int i = 0; i < ps.size(); i++){
        if (ps[i] > 0) restante.push_back(ps[i]);
    }
    sort(restante.begin(), restante.end());

    for (int i = 0; i < restante.size() && both > 0; i++, both--){
        count++;
        price += restante[i];
    }

    cout << count << " " << price << "\n";
}