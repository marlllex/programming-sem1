#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void configure_register(uint32_t *reg)
{
    if (reg == NULL) {
        return;
    }

    *reg |= (UINT32_C(1) << 7);
    *reg &= ~(UINT32_C(1) << 3);
    *reg ^= (UINT32_C(1) << 19);
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos)
{
    if (reg == NULL || bit_pos >= 32) {
        return 0;
    }

    return (*reg & (UINT32_C(1) << bit_pos)) != 0;
}

int main(void)
{
    uint32_t reg = UINT32_C(0x0000000C);

    printf("Before: 0x%08" PRIX32 "\n", reg);

    configure_register(&reg);

    printf("After:  0x%08" PRIX32 "\n", reg);
    printf("Status bit 2: %d\n", check_status_flag(&reg, 2));

    return 0;
}