#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int day = 0;
    int month = 0;
    int year = 0;
    int consume = 0;
} dates;

bool isLeap(int y){
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
    return false;
}

int day_m(int month, int year){
    switch(month){
        case 1: 
            return 31;
        case 2:
            if (isLeap(year)) return 29;
            return 28;
        case 3: 
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6: 
            return 30;
        case 7:
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

int main(){
    int t; 
    while(cin >> t && t){
        vector<dates> data;
        for (int i = 0; i < t; i++){
            int d, m, y, c; cin >> d >> m >> y >> c;
            data.push_back({d, m, y, c});
        }

        int ans = 0;
        int sum = 0;

        for (int i = 0; i < t-1; i++){
            int days = day_m(data[i].month, data[i].year);

            int aux_day = data[i].day + 1;
            int aux_month = data[i].month;
            int aux_year = data[i].year;
            
            if (aux_day > days) {
                aux_day = 1;
                aux_month++;
                if (aux_month > 12) {
                    aux_month = 1;
                    aux_year++;
                }
            }

            if (aux_day == data[i+1].day && aux_month == data[i+1].month && aux_year == data[i+1].year){
                ans++;
                sum += data[i+1].consume - data[i].consume;
            }
        }

        cout << ans << " " << sum << "\n";
    }
}
