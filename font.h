#ifndef __GITART_FONT_H__
#define __GITART_FONT_H__ 1

struct font_glyph {
	char c;
	int width, height;
	const int *bitmap;
};

extern const struct font_glyph *
font_get_glyph(char c, bool ignore_case);

extern void
font_print(void);

#endif
