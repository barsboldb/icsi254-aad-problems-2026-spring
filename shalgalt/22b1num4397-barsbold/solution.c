#include <stdio.h>

#define NEG_INF (-536870912)  /* -(1 << 29) */

static inline int max3(int a, int b, int c) {
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}

int main(void) {
    int N;
    scanf("%d", &N);

    // dp[0]: study today (0 consecutive play days ending here)
    // dp[1]: 1st consecutive play day ending here
    // dp[2]: 2nd consecutive play day ending here
    int dp0 = 0, dp1 = NEG_INF, dp2 = NEG_INF;

    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);

        int new_dp0 = max3(dp0, dp1, dp2);  // study today
        int new_dp1 = dp0 + t;              // 1st play (must follow study day)
        int new_dp2 = dp1 == NEG_INF ? NEG_INF : dp1 + t; // 2nd consecutive play

        dp0 = new_dp0;
        dp1 = new_dp1;
        dp2 = new_dp2;
    }

    printf("%d\n", max3(dp0, dp1, dp2));
    return 0;
}
