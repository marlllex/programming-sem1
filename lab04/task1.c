#include <stdio.h>

int is_prime(int number);
unsigned int count_primes(int prime);

int main(void)
{
    int number;

    puts("Variant 3: prime numbers and static counter");
    puts("Enter q to finish.");

    while (1) {
        printf("Enter an integer: ");

        if (scanf("%d", &number) != 1) {
            break;
        }

        int prime = is_prime(number);
        unsigned int total = count_primes(prime);

        printf("%d: %s\n", number, prime ? "prime" : "not prime");
        printf("Primes found this session: %u\n\n", total);
    }

    return 0;
}

int is_prime(int number)
{
    if (number < 2) {
        return 0;
    }

    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }

    return 1;
}

unsigned int count_primes(int prime)
{
    static unsigned int total = 0;

    if (prime) {
        ++total;
    }

    return total;
}