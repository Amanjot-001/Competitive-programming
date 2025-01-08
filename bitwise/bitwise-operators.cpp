#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int max_and = 0, max_or = 0, max_xor = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = i & j;
            int y = i | j;
            int z = i ^ j;

            if (x < k && x > max_and)
                max_and = x;
            if (y < k && y > max_or)
                max_or = y;
            if (z < k && z > max_xor)
                max_xor = z;
        }
    }

    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);

    return 0;
}
