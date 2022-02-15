#include <tetromino.h>
#include <structure.h>

// static const u16 DEFAULT_PIECES[7] = { 0x2222, };
/*tetromino_t tetromino_create(e_mino_t type, u16 base) {
	tetromino_t st;
	st.rotations[0].head = base;
	for (int i = 1; i <= ROTATION_270; i++) {
		printf("%d\t%d\n", i, i-1);
		st.rotations[i] = st.rotations[i - 1];
		structure_transpose(&st.rotations[i]);
		structure_reverse_rows(&st.rotations[i]);
	}
	st.structure = &st.rotations[ROTATION_0];
	return st;
}*/

tetromino_t tetromino_create(e_mino_t type, u16 base) {
	tetromino_t st;
	st.rotations[ROTATION_0].head = base;
	st.structure = &st.rotations[ROTATION_0];
	st.rotations[ROTATION_90].head = base;
	structure_transpose(&st.rotations[ROTATION_90]);
	structure_reverse_rows(&st.rotations[ROTATION_90]);
	st.rotations[ROTATION_180].head = st.rotations[ROTATION_90].head;
	structure_transpose(&st.rotations[ROTATION_180]);
	structure_reverse_rows(&st.rotations[ROTATION_180]);
	st.rotations[ROTATION_270].head = st.rotations[ROTATION_180].head;
	structure_transpose(&st.rotations[ROTATION_270]);
	structure_reverse_rows(&st.rotations[ROTATION_270]);
	return st;
}

void tetromino_rotate(tetromino_t* st) {
	st->rotation += (st->rotation == ROTATION_270) ? -3 : 1;
	st->structure = &st->rotations[st->rotation];
}

void tetromino_print(tetromino_t* st) {
	printf("val: 0x%x, state: %d\n", st->structure->head, st->rotation);
	structure_print(*st->structure);
	puts("--------------------------");
}