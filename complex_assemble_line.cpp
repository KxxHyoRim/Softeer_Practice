#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time[101] = {0,};
    int k, n, tmp, result = 0;

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        int minIdx = -1;
        // L ij 시간
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            time[j] += tmp;
            if (time[j] < min) {
                min = time[j];
                minIdx = j;
            }
        }

        result += min;

        if (i == n - 1) break;

        for (int j = 0; j < k; j++) {
            cout << j << "생산장\n";
            if (j == minIdx)
                for (int l = 0; l < k; l++){
                    if (l == j){
                        time[l] = 0;
                        continue;
                    }
                    cin >> time[l];
                }
            else
                for (int l = 0; l < k - 1; l++)
                    cin >> tmp; // 필요 없는 값

        }
    }

    cout << result;
    return 0;
}