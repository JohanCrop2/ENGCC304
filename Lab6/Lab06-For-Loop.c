#include <stdio.h>

int main() {
    int N;

    printf("Enter value:\n");
    scanf("%d", &N);

    printf("Series: ");

    if (N % 2 == 1) {
        for (int i = 1; i <= N; i += 2) {
            printf("%d ", i);
        }
    } else {
        for (int i = N; i >= 0; i -= 2) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
