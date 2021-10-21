CC = gcc
HPATH = ./inc/
FUNCSPATH = ./func_tests/
CFLAGS = -std=c99 -I$(HPATH) --coverage -Wall -pedantic -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

FUNC_C = src/*.c
FUNC_O = *.o
UNIT_C = unit_tests/*.c


app.exe:
	$(CC) $(CFLAGS) -c src/*.c
	$(CC) -o app.exe -coverage *.o

app:
	$(CC) $(CFLAGS) -c src/*.c
	$(CC) -o app -coverage *.o

unit_tests.exe:
	$(CC) -std=c99 -Wall -Werror -c unit_tests/check_unit.c
	$(CC) -std=c99 -Wall -Werror -c src/filter.c
	gcc -std=c99 -Wall -Werror -c src/sorting.c
	$(CC) -o unit_tests.exe sorting.o filter.o check_unit.o -lcheck -lpthread

unit:
	gcc -std=c99 -Wall -Werror -c unit_tests/check_unit.c
	gcc -std=c99 -Wall -Werror -c src/filter.c
	gcc -std=c99 -Wall -Werror -c src/sorting.c
	gcc -o unit filter.o sorting.o check_unit.o -lcheck -lpthread
	./unit
	rm unit filter.o sorting.o check_unit.o

func: app
	./script.sh
	gcov -n *.o
	make clean

clean:
	rm *.o app unit app.exe $(FUNC_O) *.gcda *.gcno *.gcov
