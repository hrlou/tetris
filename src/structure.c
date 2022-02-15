#include <structure.h>
#include <defs.h>

void structure_transpose(structure_t* st) {
	structure_t o = *st;
	// x1 = x1[0] | x2[0] | x3[0] | x4[0]
	st->r.x1 = ((o.r.x1 & 0x1) | (o.r.x2 & 0x1) << 1 | (o.r.x3 & 0x1) << 2 | (o.r.x4 & 0x1) << 3);
	st->r.x2 = ((o.r.x1 & 0x2) | (o.r.x2 & 0x2) << 1 | (o.r.x3 & 0x2) << 2 | (o.r.x4 & 0x2) << 3) >> 1;
	st->r.x3 = ((o.r.x1 & 0x4) | (o.r.x2 & 0x4) << 1 | (o.r.x3 & 0x4) << 2 | (o.r.x4 & 0x4) << 3) >> 2;
	st->r.x4 = ((o.r.x1 & 0x8) | (o.r.x2 & 0x8) << 1 | (o.r.x3 & 0x8) << 2 | (o.r.x4 & 0x8) << 3) >> 3;
}

void structure_reverse_rows(structure_t* st) {
	st->head = (st->head & 0xCCCC) >> 2 | (st->head & 0x3333) << 2;
	st->head = (st->head & 0xAAAA) >> 1 | (st->head & 0x5555) << 1;
}

void structure_print(structure_t st) {
	for (u8 y = 0; y < 4; y++) {
		for (u8 x = 0; x < 4; x++) {
			u8 is = BIT_CHECK(st.head, (y * 4 + x));
			putchar(is ? '#' : '_');
		}
		putchar('\n');
	}
	putchar('\n');
}