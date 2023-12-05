bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

@DX_RULES@

all-local:	doxygen-doc

doxygen-doc/man/man1/namegen.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/namegen.1

ru/LC_MESSAGES/guess.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guess.pot guess.c
	xgettext -k_ -c guess.c -o messages.new.pot
	cp guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

run_en:
	./guess

run_ru:
	LANGUAGE=ru_RU.UTF8 ./guess

clean:
	git clean -fd

http:	doxygen-doc
	python3 -m http.server --directory $</html