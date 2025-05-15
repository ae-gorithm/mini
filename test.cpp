#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, flag;
    cin >> n;

    deque<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        q.push_back(make_pair(i, k));
    }

    flag = q.front().second;
    cout << q.front().first << ' ';
    q.pop_front();

    while (!q.empty()) {
        if (flag > 0) {
            for (int i = 0; i < flag - 1; i++) {
                q.push_back(q.front());
                q.pop_front();
            }
            flag = q.front().second;
            cout << q.front().first << ' ';
            q.pop_front();
        }
        else if (flag < 0) {
            for (int i = 0; i > flag + 1; i--) {
                q.push_front(q.back());
                q.pop_back();
            }
            flag = q.back().second;
            cout << q.back().first << ' ';
            q.pop_back();
        }
    }



    return 0;
}