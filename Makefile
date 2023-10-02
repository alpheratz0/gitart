.POSIX:
.PHONY: all clean install uninstall dist

include config.mk

all: gitart

gitart: gitart.o
	$(CC) $(LDFLAGS) -o gitart gitart.o

clean:
	rm -f gitart gitart.o gitart-$(VERSION).tar.gz

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f gitart $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/gitart
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp -f gitart.1 $(DESTDIR)$(MANPREFIX)/man1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/gitart.1

dist: clean
	mkdir -p gitart-$(VERSION)
	cp -R COPYING config.mk Makefile README gitart.1 gitart.c fo.c gitart-$(VERSION)
	tar -cf gitart-$(VERSION).tar gitart-$(VERSION)
	gzip gitart-$(VERSION).tar
	rm -rf gitart-$(VERSION)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/gitart
	rm -f $(DESTDIR)$(MANPREFIX)/man1/gitart.1
