#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "font.h"

#define NUM_GLYPHS (sizeof(font)/sizeof(font[0]))

struct font_glyph font[] = {
	{
		.c = 'a',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			0, 1, 1, 0,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
		}
	},
	{
		.c = 'b',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 0,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 0,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 0,
		}
	},
	{
		.c = 'c',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			0, 1, 1, 1,
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 0, 0, 0,
			0, 1, 1, 1,
		}
	},
	{
		.c = 'd',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 0,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 0,
		}
	},
	{
		.c = 'e',
		.width = 3,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1,
			1, 0, 0,
			1, 0, 0,
			1, 1, 1,
			1, 0, 0,
			1, 0, 0,
			1, 1, 1,
		}
	},
	{
		.c = 'f',
		.width = 3,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1,
			1, 0, 0,
			1, 0, 0,
			1, 1, 1,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
		}
	},
	{
		.c = 'g',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			0, 1, 1, 1,
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			0, 1, 1, 0,
		}
	},
	{
		.c = 'h',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
		}
	},
	{
		.c = 'i',
		.width = 3,
		.height = 7,
		.bitmap = (const int []) {
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
		}
	},
	{
		.c = 'j',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 1,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			1, 0, 1, 0,
			1, 0, 1, 0,
			0, 1, 1, 0,
		}
	},
	{
		.c = 'k',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 1,
			1, 0, 1, 0,
			1, 1, 1, 0,
			1, 1, 0, 0,
			1, 1, 1, 0,
			1, 0, 1, 0,
			1, 0, 0, 1,
		}
	},
	{
		.c = 'l',
		.width = 3,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 1, 1,
		}
	},
	{
		.c = 'm',
		.width = 5,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 0, 1, 1,
			1, 0, 1, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
		}
	},
	{
		.c = 'n',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 1,
			1, 1, 0, 1,
			1, 1, 0, 1,
			1, 0, 1, 1,
			1, 0, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
		}
	},
	{
		.c = 'o',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 1,
		}
	},
	{
		.c = 'p',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 1,
			1, 0, 0, 0,
			1, 0, 0, 0,
			1, 0, 0, 0,
		}
	},
	{
		.c = 'q',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 1, 1,
			1, 1, 1, 1,
		}
	},
	{
		.c = 'r',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 0,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 1, 1, 0,
			1, 1, 0, 0,
			1, 0, 1, 0,
			1, 0, 0, 1,
		}
	},
	{
		.c = 's',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			0, 1, 1, 1,
			1, 0, 0, 0,
			1, 0, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 1,
			0, 0, 0, 1,
			1, 1, 1, 0,
		}
	},
	{
		.c = 't',
		.width = 3,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
		}
	},
	{
		.c = 'u',
		.width = 4,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			1, 0, 0, 1,
			0, 1, 1, 0,
		}
	},
	{
		.c = 'v',
		.width = 5,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			0, 1, 0, 1, 0,
			0, 0, 1, 0, 0,
		}
	},
	{
		.c = 'w',
		.width = 5,
		.height = 7,
		.bitmap = (const int []) {
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 1, 0, 1,
			1, 1, 0, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
		}
	},
	{
		.c = 'x',
		.width = 5,
		.height = 5,
		.bitmap = (const int []) {
			1, 0, 0, 0, 1,
			0, 1, 0, 1, 0,
			0, 0, 1, 0, 0,
			0, 1, 0, 1, 0,
			1, 0, 0, 0, 1,
		}
	},
	{
		.c = 'y',
		.width = 3,
		.height = 4,
		.bitmap = (const int []) {
			1, 0, 1,
			0, 1, 0,
			0, 1, 0,
			0, 1, 0,
		}
	},
	{
		.c = 'z',
		.width = 4,
		.height = 4,
		.bitmap = (const int []) {
			1, 1, 1, 1,
			0, 0, 1, 0,
			0, 1, 0, 0,
			1, 1, 1, 1,
		}
	},
	{
		.c = ' ',
		.width = 2,
		.height = 7,
		.bitmap = (const int []) {
			0, 0,
			0, 0,
			0, 0,
			0, 0,
			0, 0,
			0, 0,
			0, 0,
		}
	},
	{
		.c = '0',
		.width = 5,
		.height = 7,
		.bitmap = (const int []) {
			1, 1, 1, 1, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 1, 0, 1,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
			1, 1, 1, 1, 1,
		}
	},
};

extern const struct font_glyph *
font_get_glyph(char c, bool ignore_case)
{
	size_t i;
	for (i = 0; i < NUM_GLYPHS; ++i)
		if (font[i].c == c || (ignore_case && tolower(font[i].c) == tolower(c)))
			return &font[i];
	return NULL;
}

extern void
font_print(void)
{
	char c;
	int x, y;
	const struct font_glyph *glyph;

	for (c = 'a'; c <= 'z'; ++c) {
		if (NULL != (glyph = font_get_glyph(c, true))) {
			for (y = 0; y < glyph->height; ++y) {
				for (x = 0; x < glyph->width; ++x) {
					if (glyph->bitmap[y*glyph->width+x] == 1) putchar('#');
					else putchar(' ');
				}
				putchar('\n');
			}
			putchar('\n');
		}
	}
}
