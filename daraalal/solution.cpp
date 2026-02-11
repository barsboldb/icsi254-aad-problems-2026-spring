#include <bits/stdc++.h>
using namespace std;

/*
  Given A, B length N.
  Choose integer X, add to all A: A[i] += X
  Then you may change at most K elements of A to any values (optimal: set them to B[i]) -> diff becomes 0.

  Let C[i] = A[i] - B[i]
  After adding X: |C[i] + X|
  Changing up to K elements means we can remove up to K largest absolute diffs.
  So for a fixed X, cost = sum of (N-K) smallest values of |C[i] + X|.

  Let p = -X. We want min over p of sum of (N-K) smallest |C[i] - p|.
  After sorting C, the best (N-K) elements form a contiguous window; optimal p for a window is its median.
  Evaluate all windows of length M = N-K.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

  
    //Todo 

  
    cout << ans << "\n";
    return 0;
}
