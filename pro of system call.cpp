#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void generateFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main() {
    int n = 10;
    pid_t pid = fork();
    if (pid == -1) {
        printf("Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        printf("parent process\n");
        generateFibonacci(n);
        printf("\n");
    } else {
        printf("child process\n");
        wait(NULL);
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}

