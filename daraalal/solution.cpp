#include <bits/stdc++.h>
using namespace std;

/*
  ICSI254 - AAD Problems (2026 Spring)
  Problem: daraalal

  What you must do:
  - Read input from STDIN
  - Print the answer to STDOUT
  - Do NOT print extra debug text

  Input format:
  N K
  A1 A2 ... AN
  B1 B2 ... BN

  Output:
  - One integer: the minimum possible value

  Notes:
  - This repository uses GitHub Actions to auto-test your code.
  - Tests are in: daraalal/test/*.in and *.out
  - Local test: python daraalal/run_test.py
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    // TODO: Implement your solution here.
    // Example output (WRONG): 
    // cout << 0 << "\n";

    // Remove the line below after implementing.
    cout << 0 << "\n";
    return 0;
}
