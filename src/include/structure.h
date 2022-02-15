#ifndef STRUCTURE_H
#define STRUCTURE_H

/**
 * The memory layout lets us refer to the grid as a whole
 * or the individual rows
 */
typedef union {
	unsigned short head : 16;
	struct {
		unsigned char x1 : 4;
		unsigned char x2 : 4;
		unsigned char x3 : 4;
		unsigned char x4 : 4;
	} r;
} structure_t;

void structure_transpose(structure_t* st);
void structure_reverse_rows(structure_t* st);
void structure_print(structure_t st);

#endif