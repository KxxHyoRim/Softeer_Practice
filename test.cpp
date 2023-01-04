#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int> pq;
    pq.push(1);
    cout << pq.top() << endl;
    pq.pop();
    // pq.pop() // error


    return 0;
}