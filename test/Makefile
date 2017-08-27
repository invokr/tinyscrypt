CC := gcc
CFLAGS := -O0 -DDEBUG -I ../

all: test run clean

test:
	$(CC) $(CFLAGS) -DTINYSCRYPT_N=16 -DTINYSCRYPT_R=1 -DTINYSCRYPT_P=1 ../tinyscrypt.c test1.c -o test1
	$(CC) $(CFLAGS) -DTINYSCRYPT_N=1024 -DTINYSCRYPT_R=8 -DTINYSCRYPT_P=16 ../tinyscrypt.c test2.c -o test2
	$(CC) $(CFLAGS) -DTINYSCRYPT_N=16384 -DTINYSCRYPT_R=8 -DTINYSCRYPT_P=1 ../tinyscrypt.c test3.c -o test3
	$(CC) $(CFLAGS) -DTINYSCRYPT_N=1048576 -DTINYSCRYPT_R=8 -DTINYSCRYPT_P=1 ../tinyscrypt.c test4.c -o test4

run:
	./test1
	./test2
	./test3
	./test4

clean:
	rm test1 test2 test3 test4
