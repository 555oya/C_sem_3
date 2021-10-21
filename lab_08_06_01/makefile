CC = gcc
HPATH = ./inc/
OBJ_DIR = out
SRC_DIR = src
FUNCSPATH = func_tests
CFLAGS = -std=c99 -I$(HPATH) --coverage -Wall -pedantic -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ =  $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
GCNO =  $(patsubst $(SRC_DIR)/%.c, %.gcno, $(SRC))
GCDA =  $(patsubst $(SRC_DIR)/%.c, %.gcda, $(SRC))

app.exe:
	$(CC) $(CFLAGS) -o app.exe $(SRC)

app:
	$(CC) $(CFLAGS) -o app $(SRC)
	mv $(GCNO) out

unit_tests.exe:
	$(CC) -std=c99 -Wall -Werror -c unit_tests/check_units.c
	$(CC) -std=c99 -Wall -Werror -c src/add_row_col.c
	$(CC) -std=c99 -Wall -Werror -c src/delete_rows_cols.c
	$(CC) -std=c99 -Wall -Werror -c src/mult_matrix.c
	$(CC) -o unit_tests.exe add_row_col.o delete_rows_cols.o mult_matrix.o check_units.o -lcheck -lpthread

unit:
	$(CC) -std=c99 -Wall -Werror -c unit_tests/check_units.c
	$(CC) -std=c99 -Wall -Werror -c src/add_row_col.c
	$(CC) -std=c99 -Wall -Werror -c src/delete_rows_cols.c
	$(CC) -std=c99 -Wall -Werror -c src/mult_matrix.c
	$(CC) -o unit add_row_col.o delete_rows_cols.o mult_matrix.o check_units.o -lcheck -lpthread
	./unit
	rm unit add_row_col.o delete_rows_cols.o mult_matrix.o check_units.o

func: app
	./script.sh
	mv $(GCDA) out
	gcov -n $(OBJ)

clean:
	rm $(OBJ) app */*.gcda */*.gcno */*.gcov *.gcno
