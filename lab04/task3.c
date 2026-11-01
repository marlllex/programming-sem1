#include <stdio.h>
#include <stdint.h>

uint16_t pack_telemetry(unsigned int priority, unsigned int fan_speed,
                        unsigned int error_code, unsigned int power);

void unpack_telemetry(uint16_t packet, unsigned int *priority,
                      unsigned int *fan_speed, unsigned int *error_code,
                      unsigned int *power);

int main(void)
{
    unsigned int priority, fan_speed, error_code, power;
    unsigned int restored_priority, restored_fan;
    unsigned int restored_error, restored_power;

    puts("Variant 3: telemetry packing");
    puts("Enter priority (0..15), fan speed (0..255),");
    puts("error code (0..3), power (0..1), separated by spaces:");

    if (scanf("%u %u %u %u", &priority, &fan_speed,
              &error_code, &power) != 4) {
        puts("Input error: enter four integers.");
        return 1;
    }

    if (priority > 15 || fan_speed > 255 ||
        error_code > 3 || power > 1) {
        puts("Input error: a value is outside the allowed range.");
        return 1;
    }

    uint16_t packet = pack_telemetry(priority, fan_speed,
                                      error_code, power);

    unpack_telemetry(packet, &restored_priority, &restored_fan,
                     &restored_error, &restored_power);

    printf("\nOriginal: priority=%u, fan=%u, error=%u, power=%u\n",
           priority, fan_speed, error_code, power);

    printf("Packet: 0x%04X\n", (unsigned int)packet);

    printf("Restored: priority=%u, fan=%u, error=%u, power=%u\n",
           restored_priority, restored_fan,
           restored_error, restored_power);

    if (priority == restored_priority &&
        fan_speed == restored_fan &&
        error_code == restored_error &&
        power == restored_power) {
        puts("Verification: OK (all fields match).");
        return 0;
    }

    puts("Verification: FAILED.");
    return 1;
}

uint16_t pack_telemetry(unsigned int priority, unsigned int fan_speed,
                        unsigned int error_code, unsigned int power)
{
    return (uint16_t)((priority & 0x0Fu) |
                      ((fan_speed & 0xFFu) << 4) |
                      ((error_code & 0x03u) << 12) |
                      ((power & 0x01u) << 14));
}

void unpack_telemetry(uint16_t packet, unsigned int *priority,
                      unsigned int *fan_speed, unsigned int *error_code,
                      unsigned int *power)
{
    *priority = packet & 0x0Fu;
    *fan_speed = (packet >> 4) & 0xFFu;
    *error_code = (packet >> 12) & 0x03u;
    *power = (packet >> 14) & 0x01u;
}