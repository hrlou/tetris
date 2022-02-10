#include <stdio.h>

#include <defs.h>
#include <log.h>
#include <tetromino.h>


int main(void) {
	printf("%ld\n", sizeof(tetromino_t));
	// tetromino_t I = tetromino_create(MINO_I, 0x8888);
	// tetromino_t T = tetromino_create(MINO_T, 0x2620);
	tetromino_t x1 = tetromino_create(MINO_EMPTY, 0b0010001000100010); // Tetronimos 4x4
	tetromino_t x2 = tetromino_create(MINO_EMPTY, 0b0010011000100000);
	tetromino_t x3 = tetromino_create(MINO_EMPTY, 0b0000011001100000);
	tetromino_t x4 = tetromino_create(MINO_EMPTY, 0b0010011001000000);
	tetromino_t x5 = tetromino_create(MINO_EMPTY, 0b0100011000100000);
	tetromino_t x6 = tetromino_create(MINO_EMPTY, 0b0100010001100000);
	tetromino_t x7 = tetromino_create(MINO_EMPTY, 0b0010001001100000);

	
	tetromino_t* t = &x1;
	tetromino_print(t);
	tetromino_rotate(t);
	tetromino_print(t);
	tetromino_rotate(t);
	tetromino_print(t);
	tetromino_rotate(t);
	tetromino_print(t);
	tetromino_rotate(t);
	tetromino_print(t);
	tetromino_rotate(t);
	tetromino_print(t);
	
	return 0;
}