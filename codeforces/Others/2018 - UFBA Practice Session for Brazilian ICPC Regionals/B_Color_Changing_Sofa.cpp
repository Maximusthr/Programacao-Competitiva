// Campelo did it

/**
* @file bb.cpp
*
* Created on 2025-05-19 at 20:46:02
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

int main() { _
    string room;
    string sofa;

    cin >> room >> sofa;

    int type = 1;
    for (int i = 1; i < sofa.size(); i++) {
        if (sofa[0] != sofa[i]) {
            type = 2;
            break;
        }
    }

    vector<int> dp(30);
    
    int diff = 0;
    int len = sofa.size();

    for (int i = 0; i < len; i++) {
        int c = room[i] - 'a';
        if (dp[c] == 0) diff++;
        dp[c]++;
    }

    int l = 0, r = len - 1;
    int ans = 0;

    while (1) {
        if (diff == 1) {
            ans++;
        } else if (diff == 2 && type == 2) {
            bool possible = true;
            char c0 = '$', c1 = '$';
            int j = 0;

            for (int i = l; i <= r; i++, j++) {
                if (sofa[j] == '0') {
                    if (c0 == '$') {
                        c0 = room[i];
                    } else if (c0 != room[i]) {
                        possible = false;
                        break;
                    }
                } else {
                    if (c1 == '$') {
                        c1 = room[i];
                    } else if (c1 != room[i]) {
                        possible = false;
                        break;
                    }
                }
            }

            if (possible) {
                ans++;
            } else {
                possible = true;
                c0 = '$', c1 = '$';
                j = 0;

                for (int i = r; i >= l; i--, j++) {
                    if (sofa[j] == '0') {
                        if (c0 == '$') {
                            c0 = room[i];
                        } else if (c0 != room[i]) {
                            possible = false;
                            break;
                        }
                    } else {
                        if (c1 == '$') {
                            c1 = room[i];
                        } else if (c1 != room[i]) {
                            possible = false;
                            break;
                        }
                    }
                }

                if (possible) ans++;
            }
        }

        if (r == room.size() - 1) break;

        int c = room[l] - 'a';
        if (dp[c] == 1) diff--;
        dp[c]--;

        c = room[r + 1] - 'a';
        if (dp[c] == 0) diff++;
        dp[c]++;

        l++;
        r++;
    }

    cout << ans << endl;
    
    return 0;
}