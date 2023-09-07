FLAGS = -Wall -Werror -Wextra -std=c11

all: test gcov_report install

install:
	cd Calc && qmake && make && make clean
	cp -r Calc/Calc.app ~/Desktop

uninstall:
	rm -rf Calc/Calc.app 
	rm -rf ~/Desktop/Calc.app
	rm -rf Calc/Makefile

clean:
	rm -rf *.o *.gcno *.gcda *.gcov *.css *.html *.dSYM report *.info *.gz tests

dvi:
	open dvi.html

dist: install
	mkdir archiv
	cp -r *.c *.h Makefile SmartCalc/ archiv
	tar -cvzf SmartCalc.tar.gz archiv
	rm -rf archiv

test: clean
	gcc -c $(FLAGS) test.c
	gcc -c $(FLAGS) main.c
	gcc -lcheck -fprofile-arcs -g -ftest-coverage Calc/s21_*.c Calc/support.c *.o -o tests
	./tests


gcov_report: 
	gcov *.gcda
	lcov -t "calc" -o calc.info -c -d .
	genhtml -o report calc.info
	open report/index.html

leaks:
	leaks -atExit -- ./tests
