#include <tetromino.h>

static void _structure_transpose(u16* s) {
	u16 t;
	for (int col = 0; col < 4; ++col) {
    	for (int row = 0; row < 4; ++row) {
			int i = (row * 4) + col;
			if (BIT_CHECK(*s, (col * 4) + row)) {
				// printf("(%d, %d) -> (%d, %d)\n", row, col, col, row);
				BIT_SET(t, i);
			} else { 
				// I have no clue why this is needed
				BIT_CLEAR(t, i);
			}
		}
	}
	*s = 0;
	*s = t;
}

static void _structure_reverse_rows(u16* s) {
	*s = (*s & 0xCCCC) >> 2 | (*s & 0x3333) << 2;
	*s = (*s & 0xAAAA) >> 1 | (*s & 0x5555) << 1;
}

static const u16 DEFAULT_PIECES[7] = { 0x2222, };

tetromino_t tetromino_create(e_mino_t type, u16 base) {
	tetromino_t st;
	st.rotations[ROTATION_0] = base;
	st.rotations[ROTATION_90] = base;
	_structure_transpose(&st.rotations[ROTATION_90]);
	_structure_reverse_rows(&st.rotations[ROTATION_90]);
	st.rotations[ROTATION_180] = st.rotations[ROTATION_90];
	_structure_transpose(&st.rotations[ROTATION_180]);
	_structure_reverse_rows(&st.rotations[ROTATION_180]);
	st.rotations[ROTATION_270] = st.rotations[ROTATION_180];
	_structure_transpose(&st.rotations[ROTATION_270]);
	_structure_reverse_rows(&st.rotations[ROTATION_270]);
	st.structure = &st.rotations[ROTATION_0];
	return st;
}

void tetromino_rotate(tetromino_t* st) {
	u8 r = st->state & 0xF;
	printf("state: %d ->", r);
	r += (r == ROTATION_270) ? -3 : 1;
	st->state = (r & 0xF) | (r << 4);
	printf(" %d\n", st->state & 0xF);
	st->structure = &st->rotations[r];
}

void tetromino_print(tetromino_t* st) {
	for (u8 y = 0; y < 4; y++) {
		for (u8 x = 0; x < 4; x++) {
			u8 is = BIT_CHECK(*st->structure, (y * 4 + x));
			putchar(is ? '#' : '_');
		}
		putchar('\n');
	}
	printf("val: 0x%x, state: %d\n", *st->structure, st->state & 0xF);
}