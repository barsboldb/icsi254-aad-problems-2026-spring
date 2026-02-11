#include <stdio.h>
#include <string.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    int side[1000];   // 0 = L, 1 = R
    int skills[1000]; // bitmask of 15 skills
    for (int i = 0; i < N; i++) {
      char s[20];
      scanf("%s", s);
      side[i] = (s[0] == 'R') ? 1 : 0;
      skills[i] = 0;
      for (int j = 1; j <= 15; j++) {
        if (s[j] == '1')
          skills[i] |= (1 << (j - 1));
      }
    }

    int best = 0;
    for (int mask = 0; mask < (1 << 15); mask++) {
      int left_count = 0;
      for (int i = 0; i < N; i++) {
        int overlap = skills[i] & mask;
        int flipped = __builtin_popcount(overlap) & 1;
        if ((side[i] == 0 && !flipped) || (side[i] == 1 && flipped))
          left_count++;
      }
      if (left_count > best)
        best = left_count;
    }
    printf("%d\n", best);
  }
  return 0;
}
