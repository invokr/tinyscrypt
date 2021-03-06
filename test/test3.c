#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "../tinyscrypt.h"

// test vector
const char* pwd = "pleaseletmein";
const char* salt = "SodiumChloride";

const uint8_t expected[] = {
    0x70, 0x23, 0xbd, 0xcb, 0x3a, 0xfd, 0x73, 0x48, 0x46, 0x1c, 0x06, 0xcd, 0x81, 0xfd, 0x38, 0xeb,
    0xfd, 0xa8, 0xfb, 0xba, 0x90, 0x4f, 0x8e, 0x3e, 0xa9, 0xb5, 0x43, 0xf6, 0x54, 0x5d, 0xa1, 0xf2,
    0xd5, 0x43, 0x29, 0x55, 0x61, 0x3f, 0x0f, 0xcf, 0x62, 0xd4, 0x97, 0x05, 0x24, 0x2a, 0x9a, 0xf9,
    0xe6, 0x1e, 0x85, 0xdc, 0x0d, 0x65, 0x1e, 0x40, 0xdf, 0xcf, 0x01, 0x7b, 0x45, 0x57, 0x58, 0x87
};

uint8_t out[64];

int main() {
    int ret;
    ret = tinyscrypt((const uint8_t*)pwd, strlen(pwd), (const uint8_t*)salt, strlen(salt), out, 64);

    assert(ret == 0);
    assert(memcmp(out, expected, 64) == 0);

    return 0;
}
