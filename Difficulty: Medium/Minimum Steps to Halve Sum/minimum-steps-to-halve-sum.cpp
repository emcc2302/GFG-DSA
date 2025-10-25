#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        // compute the initial sum (use double because of halving floats)
        double sum = 0;
        for (int x : arr) sum += x;
        double target = sum / 2.0;

        // max-heap of doubles
        priority_queue<double> pq;
        for (int x : arr) {
            pq.push((double)x);
        }

        int ops = 0;
        double reducedSum = sum;  // current sum

        // keep picking largest until sum ≤ target
        while (reducedSum > target) {
            double x = pq.top();
            pq.pop();
            double half = x / 2.0;
            // we reduce the sum by (x − half) = half
            reducedSum -= half;
            // push the halved value back
            pq.push(half);
            ops++;
        }
        return ops;
    }
};
