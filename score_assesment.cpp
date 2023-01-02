#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
    if (a > b) return true;
    return false;
}

int main(int argc, char **argv) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, input;
    cin >> n;

    int score[100000] = {0};
    int sorted[100000] = {0};
    int ranking[100000] = {0};

    int total[100000] = {0};
    int total_sorted[100000] = {0};


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            score[j] = input;
            sorted[j] = input;
            total[j] += input;
            total_sorted[j] += input;
        }

        sort(sorted, sorted + n, compare);

        ranking[0] = 1;
        for (int j = 1; j < n; j++) {
            if (sorted[j] == sorted[j - 1]) {
                ranking[j] = ranking[j - 1];
            } else {
                ranking[j] = j + 1;
            }
        }

        for (int j = 0; j < n; j++) {
            int find_target = score[j];

            int left = 0;
            int right = n - 1;
            while (true) {
                int mid = (left + right) / 2;
                if (find_target == sorted[mid]) {
                    cout << ranking[mid] << " ";
                    break;
                } else if (find_target < sorted[mid]) { left = mid + 1; }
                else { right = mid - 1; }
            }
        }
        cout << "\n";
    }

    /** total sort */
    sort(total_sorted, total_sorted + n, compare);

    ranking[0] = 1;
    for (int j = 1; j < n; j++) {
        if (total_sorted[j] == total_sorted[j - 1]) {
            ranking[j] = ranking[j - 1];
        } else {
            ranking[j] = j + 1;
        }
    }


    for (int j = 0; j < n; j++) {
        int find_target = total[j];

        int left = 0;
        int right = n - 1;
        while (true) {
            int mid = (left + right) / 2;
            if (find_target == total_sorted[mid]) {
                cout << ranking[mid] << " ";
                break;
            } else if (find_target < total_sorted[mid]) { left = mid + 1; }
            else { right = mid - 1; }
        }
    }
    return 0;
}