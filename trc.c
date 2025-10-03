#include "trc.h"
#include <stdint.h> // Include for uint32_t definition



/* ===== CRC-16 (X^16 + X^12 + X^5 + 1), init 0xFFFF, MSB-first ===== */
uint16_t trc_crc16(const uint8_t *buf, uint32_t len)
{
    uint16_t crc = 0xFFFFu;
    for (uint32_t i = 0; i < len; ++i) {
        uint8_t data = buf[i];
        for (int b = 0; b < 8; ++b) {
            uint16_t x = ((crc >> 15) ^ (data >> 7)) & 1u;
            crc <<= 1;
            if (x) crc ^= 0x1021u;
            data <<= 1;
        }
    }
    return crc;
}