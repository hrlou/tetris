#include <stdio.h>

#include <defs.h>
#include <tetromino.h>

int main(void) {
	// ! SERIOUS MEMORY ISSUE MUST BE FIXED
	// UNSURE
	// I
	tetromino_t x1 = tetromino_create(MINO_EMPTY, 0b0010001000100010);
	// T
	tetromino_t x2 = tetromino_create(MINO_EMPTY, 0b0010011000100000);
	// O
	tetromino_t x3 = tetromino_create(MINO_EMPTY, 0b0000011001100000);
	// tetromino_t x4 = tetromino_create(MINO_EMPTY, 0b0010011001000000);
	// tetromino_t x5 = tetromino_create(MINO_EMPTY, 0b0100011000100000);
	// tetromino_t x6 = tetromino_create(MINO_EMPTY, 0b0100010001100000);
	// tetromino_t x7 = tetromino_create(MINO_EMPTY, 0b0010001001100000);

	// exit(0);

	// log_debug("Hello, World");

	// getting corrupted by after

	for (int i = 0; i < 4; i++) {
		tetromino_print(&x2);
		tetromino_rotate(&x2);
		// structure_print(x2.rotations[i]);
	}
	
	return 0;
}