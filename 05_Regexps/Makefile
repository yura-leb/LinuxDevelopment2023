GENERATES = esub *.o *~ o.* sed_test esub_test

all:	esub

esub: esub.c
	gcc $^ -o $@

test: 
	echo 'string' | sed -E 's/regexp/substitution/' > sed_test
	./esub regexp substitution string > esub_test
	diff sed_test esub_test

	echo '1234' | sed -E 's/[0-9]/a/' > sed_test
	./esub [0-9] a 1234 > esub_test
	diff sed_test esub_test

	echo 'Tue Oct 24 09:32:58 AM UTC 2023' | sed 's/\([0-9][0-9]*\)/<\1\1\\\\\1>/' > sed_test
	./esub '([0-9][0-9]*)' '<\1\1\\\\\1>' 'Tue Oct 24 09:32:58 AM UTC 2023' > esub_test
	diff sed_test esub_test

clean:
	rm -rf $(GENERATES)