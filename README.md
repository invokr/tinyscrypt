Tinyscrypt
==========

Tiny (as in, < 1000 LOC) SCrypt implementation, mostly based on https://github.com/technion/libscrypt.

The biggest difference between `tinyscrypt` and `libscrypt` is that the SCrypt-parameters for `tinyscrypt` have
to be set at compile time. This saves two calls to malloc (making the library malloc-free, only requiring one mmap
call).

License
-------

This is a derivative work based on https://github.com/technion/libscrypt/, which itself is a derivative
work based on the original implementation by Colin Percival (http://www.tarsnap.com/scrypt.html).

All original source code is licensed under the BSD License (see tinyscrypt.h header).
My changes can be considered public domain.

Compilation
-----------

Simply include `tinyscrypt.c` and `tinyscrypt.h` in your build. There are no external dependencies.
Default parameters can be overwritten at compile time using the following cflags: `-DTINYSCRYPT_N=XX -DTINYSCRYPT_R=X -DTINYSCRYPT_P=X`.

Tinyscrypt can be compiled without `libc` if you provide your own implementations for `memcpy`, `memcmp`, `memmove`, and `mmap`.
In this case compiling the library using `-fno-stack-protector` is required to not pull in libc dependencies.

Usage
-----

    #include <stdio.h>
    #include "tinyscrypt.h"

    int main() {
        int ret;
        const char* pw = "pw";
        const char* salt = "salt";
        uint8_t out[64];

        // ret: 0 = OK, !0 = Error
        // Password, Password-len, Salt, Salt-len, output buffer, buffer-len
        ret = tinyscrypt((const uint8_t*)pw, 2, (const uint8_t*)salt, 4, out, 64);

        if (ret != 0) {
            printf("Scrypt failed!\n");
            return 1;
        }

        // result is in `out`

        return 0;
    }
