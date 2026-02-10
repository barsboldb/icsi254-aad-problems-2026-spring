#include "brute_force.h"
#include <string.h>

#define MOD 998244353

int isPalindrome(char *s, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}

int isDoublePalindrome(char *s, int len) {

    if (isPalindrome(s, len))
        return 1;

    for (int i = 1; i < len; i++) {
        if (isPalindrome(s, i) &&
            isPalindrome(s + i, len - i))
            return 1;
    }

    return 0;
}

// recursive generate
void generate(int pos, int len, int k, char *buffer, long long *ans) {

    if (pos == len) {
        if (isDoublePalindrome(buffer, len)) {
            (*ans) = ((*ans) + 1) % MOD;
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        buffer[pos] = 'a' + i;
        generate(pos + 1, len, k, buffer, ans);
    }
}

long long countDoublePalindromes(int n, int k) {

    long long ans = 0;
    char buffer[20];  
    // brute force тул n <= 19

    for (int len = 1; len <= n; len++) {
        generate(0, len, k, buffer, &ans);
    }

    return ans % MOD;
}