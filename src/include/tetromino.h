#ifndef TETROMINO_H
#define TETROMINO_H

#include <defs.h>

/**
 * mino is a single piece
 * tetromino is a configuration of 4 minos
 * matrix can eat tetromino and story them into it's mino configuration
 * 
 */

/**
 * 8 possibilities
 * 3 bits needed
 */
typedef enum {
	MINO_I, MINO_O, MINO_T, MINO_S, MINO_Z, MINO_J, MINO_L, MINO_EMPTY
} e_mino_t;

/**
 * 4 possibilities
 * 2 bits are required
 */
typedef enum {
	ROTATION_0, ROTATION_90, ROTATION_180, ROTATION_270
} e_rotation_t;

typedef struct {
	u16 rotations[4];
	u16* structure;
	/**
	 * first 4 bits are rotation
	 * second 4 bits are type
	 */
	u8 state;
} tetromino_t;

tetromino_t tetromino_create(e_mino_t type, u16 base);
void tetromino_print(tetromino_t* t);

#endif