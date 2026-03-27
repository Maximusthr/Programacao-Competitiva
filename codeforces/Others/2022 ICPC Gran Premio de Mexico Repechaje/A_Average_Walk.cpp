/**
* @file A_Average_Walk.cpp
* @author GabrielCampelo
* Created on 2026-03-27 at 08:33:12
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int x;
    cin >> x;

    cout << min(15.0, ceil(3000.0 / x)) << endl;
    
    return 0;
}