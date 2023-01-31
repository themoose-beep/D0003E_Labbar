#include "tinythreads.h"
#include <stdbool.h>

void writeChar(char ch, int pos); // from lab 1

bool is_prime(long i); // from lab 1

void printAt(long num, int pos) {
    int pp = pos;
    writeChar( (num % 100) / 10 + '0', pp);
    pp++;
    writeChar( num % 10 + '0', pp);
}

void computePrimes(int pos) {
    long n;

    for(n = 1; ; n++) {
        if (is_prime(n)) {
            printAt(n, pos);
        }
    }
}

int main() {
    spawn(computePrimes, 0);
    computePrimes(3);
}
