#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t set_bit(uint32_t value, unsigned int bit);
uint32_t clear_bit(uint32_t value, unsigned int bit);
uint32_t toggle_bit(uint32_t value, unsigned int bit);
int check_bit(uint32_t value, unsigned int bit);
void print_binary(uint32_t value);
void print_register(uint32_t value);

int main(void)
{
    uint32_t gpio = UINT32_C(0x00000104);

    puts("Variant 3: 32-bit GPIO register");

    puts("\nBefore set_bit(4):");
    print_register(gpio);
    gpio = set_bit(gpio, 4);
    puts("After set_bit(4):");
    print_register(gpio);

    puts("\nBefore clear_bit(8):");
    print_register(gpio);
    gpio = clear_bit(gpio, 8);
    puts("After clear_bit(8):");
    print_register(gpio);

    puts("\nBefore toggle_bit(14):");
    print_register(gpio);
    gpio = toggle_bit(gpio, 14);
    puts("After toggle_bit(14):");
    print_register(gpio);

    puts("\nBefore check_bit(2):");
    print_register(gpio);
    printf("Bit 2 = %d\n", check_bit(gpio, 2));
    puts("After check_bit(2):");
    print_register(gpio);

    return 0;
}

uint32_t set_bit(uint32_t value, unsigned int bit)
{
    if (bit >= 32) {
        return value;
    }
    return value | (UINT32_C(1) << bit);
}

uint32_t clear_bit(uint32_t value, unsigned int bit)
{
    if (bit >= 32) {
        return value;
    }
    return value & ~(UINT32_C(1) << bit);
}

uint32_t toggle_bit(uint32_t value, unsigned int bit)
{
    if (bit >= 32) {
        return value;
    }
    return value ^ (UINT32_C(1) << bit);
}

int check_bit(uint32_t value, unsigned int bit)
{
    if (bit >= 32) {
        return 0;
    }
    return (value & (UINT32_C(1) << bit)) != 0;
}

void print_binary(uint32_t value)
{
    for (int bit = 31; bit >= 0; --bit) {
        putchar(((value >> bit) & UINT32_C(1)) ? '1' : '0');

        if (bit > 0 && bit % 4 == 0) {
            putchar(' ');
        }
    }
    putchar('\n');
}

void print_register(uint32_t value)
{
    printf("HEX: 0x%08" PRIX32 "\nBIN: ", value);
    print_binary(value);
}