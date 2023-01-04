#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[101][101] = {0};
    int k, n, tmp, move_time = 0;

    cin >> k >> n;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < k; j++) {
            cin >> tmp;
            dp[j][i] += tmp;  // 세로 한줄한줄씩 채워나감
        }

        if (i == n - 1) break;

        for (int j = 0 ; j < k; j++){   // to
            for (int l = 0 ; l < k; l++){   // from
                if (j == l) move_time = 0;
                else cin >> move_time;
                if (dp[j][i+1] == 0)
                    dp[j][i+1] = dp[l][i] + move_time;
                else
                    dp[j][i+1] = min(dp[j][i+1], dp[l][i] + move_time);
            }
        }
    }


    int min = dp[0][k - 1];

    for (int i = 1; i < k; i++) {
        if (dp[i][n - 1] < min)
            min = dp[i][n - 1];
    }

    cout << min;
    return 0;
}