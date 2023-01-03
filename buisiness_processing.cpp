#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int H, R, K, input, result = 0;

bool isLeaf(int n) {
    if (n >= pow(2, H - 1) )
        return true;
    return false;
}

int main() {
    cin >> H >> K >> R;
    H++;
    int member_num = (int) pow(2, H) - 1;
    int leaf_num = (int) pow(2, H - 1);

    vector<queue<int>> fromLeft(member_num + 1, queue<int>());
    vector<queue<int>> fromRight(member_num + 1, queue<int>());

    // leaf node queue 채워 넣음
    int idx = (int) pow(2, H - 1);
    for (int i = 0; i < leaf_num; i++) {
        for (int j = 0; j < K; j++) {
            cin >> input;
            fromLeft[idx].push(input);
        }
        idx++;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= member_num; j++) {
            int child = j; // 자기자신
            int parent = j / 2;
            int workNum;
            bool isWorkExist = false;
            if (isLeaf(j) || (i % 2 == 1)) {
                if (!fromLeft[child].empty()){
                    isWorkExist = true;
                    workNum = fromLeft[child].front();
                    fromLeft[child].pop();
                }
            } else {
                if (!fromRight[child].empty()){
                    isWorkExist = true;
                    workNum = fromRight[child].front();
                    fromRight[child].pop();
                }
            }

            if (isWorkExist){
                if (j == 1) {
                    result += workNum;
                } else if (j % 2 == 0) {
                    fromLeft[parent].push(workNum);
                } else {
                    fromRight[parent].push(workNum);
                }
            }
        }
    }

    cout << result;

    return 0;
}
