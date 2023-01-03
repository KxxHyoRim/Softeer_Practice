#include <iostream>
#include <queue>

using namespace std;

struct Treasure {
    int weight;
    int price;

    Treasure(int w, int p) : weight(w), price(p) {}

    bool operator<(const Treasure t) const {
        return this->price < t.price;
    }
};

int main() {

    int n, w, m, p, sum = 0;
    cin >> w >> n;
    priority_queue<Treasure> pq;

    for (int i = 0; i < n; i++) {
        cin >> m >> p;  //무게, 가격
        pq.emplace(m, p);
    }

    while (w != 0) {
        if (pq.empty()) break;
        else if (pq.top().weight <= w) {
            int one_weight = pq.top().weight;
            int one_price = pq.top().price;
            pq.pop();
            sum += (one_price * one_weight);
            w -= one_weight;
        } else {
            int one_price = pq.top().price;
            pq.pop();
            sum += (w * one_price);
            w = 0;
            break;
        }
    }

    cout << sum;


    return 0;
}
