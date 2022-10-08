/*
	Copyright (C) 2022 <alpheratz99@protonmail.com>

	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU General Public License version 2 as published by the
	Free Software Foundation.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place, Suite 330, Boston, MA 02111-1307 USA

*/

#include <git2.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include "fo.c"

static void
die(const char *fmt, ...)
{
	va_list args;

	fputs("gitart: ", stderr);
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fputc('\n', stderr);
	exit(1);
}

static const char *
enotnull(const char *str, const char *name)
{
	if (NULL == str)
		die("%s cannot be null", name);
	return str;
}

static void
usage(void)
{
	puts("usage: gitart [-hv] [-d dirname] [-i intensity] [text]");
	exit(0);
}

static void
version(void)
{
	puts("gitart version "VERSION);
	exit(0);
}

static void
add_new_commit(git_repository *repo, git_signature *sig)
{
	git_oid tid, pid, cid;
	size_t nparents;
	git_tree *tree;
	git_commit *parent;
	git_index *index;

	if (git_repository_index(&index, repo) < 0)
		die("git_repository_index failed: %s", git_error_last()->message);

	if (git_index_write_tree(&tid, index) < 0)
		die("git_index_write_tree failed: %s", git_error_last()->message);

	if (git_tree_lookup(&tree, repo, &tid) < 0)
		die("git_tree_lookup failed: %s", git_error_last()->message);

	git_index_free(index);

	switch (git_repository_head_unborn(repo)) {
		case 0:
			nparents = 1;
			if (git_reference_name_to_id(&pid, repo, "HEAD") < 0)
				die("git_reference_name_to_id failed: %s", git_error_last()->message);
			if (git_commit_lookup(&parent, repo, &pid) < 0)
				die("git_commit_lookup failed: %s", git_error_last()->message);
			break;
		case 1:
			nparents = 0;
			parent = NULL;
			break;
		default:
			die("git_repository_head_unborn failed: %s", git_error_last()->message);
			break;
	}

	if (git_commit_create_v(&cid, repo, "HEAD", sig, sig,
				"UTF-8", "gitart", tree, nparents, parent) < 0)
		die("git_commit_create_v failed: %s", git_error_last()->message);

	git_tree_free(tree);
}

static void
set_pixel(git_repository *repo, git_signature *sig, int x, int y, int intensity)
{
	time_t t;
	struct tm *now;

	t = time(NULL);
	now = localtime(&t);

	sig->when.time = t - 60 * 60 * 24 * (now->tm_wday + (52 - x) * 7 - y);

	while (intensity-- > 0)
		add_new_commit(repo, sig);
}

static void
gitart(const char *dir, const char *text, int intensity)
{
	git_repository *repo;
	git_signature *sig;
	unsigned char *glyph;
	size_t i;
	int caret, gx, gy;

	if (mkdir(dir, 0700) < 0)
		die("mkdir failed: %s", strerror(errno));

	if (git_libgit2_init() < 0)
		die("git_libgit2_init failed: %s", git_error_last()->message);

	if (git_repository_init(&repo, dir, false) < 0)
		die("git_repository_init failed: %s", git_error_last()->message);

	if (git_signature_default(&sig, repo) < 0)
		die("git_signature_default failed: %s", git_error_last()->message);

	caret = 0;

	for (i = 0; i < strlen(text); ++i) {
		printf("rendering glyph: %c\n", text[i]);
		glyph = five_by_seven + text[i]*7;
		for (gy = 0; gy < 7; ++gy)
			for (gx = 0; gx < 5; ++gx)
				if (glyph[gy] & (1 << (4 - gx)))
					set_pixel(repo, sig, caret + gx, gy, intensity);
		caret += 6;
	}

	git_signature_free(sig);
	git_repository_free(repo);
	git_libgit2_shutdown();
}

int
main(int argc, char **argv)
{
	const char *dir, *text;
	int intensity;

	intensity = 100;
	text = NULL;
	dir = "art";

	while (++argv, --argc > 0) {
		if ((*argv)[0] == '-' && (*argv)[1] != '\0' && (*argv)[2] == '\0') {
			switch ((*argv)[1]) {
				case 'h': usage(); break;
				case 'v': version(); break;
				case 'i': --argc; intensity = atoi(enotnull(*++argv, "intensity")); break;
				case 'd': --argc; dir = enotnull(*++argv, "dirname"); break;
				default: die("invalid option %s", *argv); break;
			}
		} else {
			if (NULL != text)
				die("unexpected argument: %s", *argv);
			text = *argv;
		}
	}

	if (NULL == text)
		text = "gitart";

	if (intensity < 1)
		intensity = 10;

	gitart(dir, text, intensity);

	return 0;
}
