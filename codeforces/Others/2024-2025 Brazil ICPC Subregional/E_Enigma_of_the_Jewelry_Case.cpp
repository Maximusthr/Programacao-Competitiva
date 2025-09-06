#/**
* @file e.cpp
*
* Created on 2025-09-06 at 08:52:25
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX_N 55

int ar[MAX_N][MAX_N];

int main() { _
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }

    int mn = ar[0][0];
    mn = min(mn, ar[0][n - 1]);
    mn = min(mn, ar[n - 1][0]);
    mn = min(mn, ar[n - 1][n - 1]);

    if (mn == ar[0][0]) {
        cout << 0 << endl;
    } else if (mn == ar[0][n - 1]) {
        cout << 1 << endl;
    } else if (mn == ar[n - 1][n - 1]) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    
    return 0;
}