CC							= g++
CFLAGS					= -std=c++17 -Wall -Wextra -Werror -pedantic -fsanitize=address,undefined -I .
LDFLAGS					= -lgtest_main -lgtest -lpthread 
VALGRIND_FLAGS	= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
GCOVFLAGS 			= -fprofile-arcs -ftest-coverage

SRC_PROJECT_DIR	= library/
SRC_TEST_DIR		= tests/
OBJ_PROJECT_DIR	= obj/library/
OBJ_TEST_DIR		= obj/tests/

LIBRARY					= s21_matrix_oop.a
SRC_PROJECT			= $(wildcard $(SRC_PROJECT_DIR)*.cc)
SRC_TEST				= $(wildcard $(SRC_TEST_DIR)*.cc)
OBJ_PROJECT			= $(patsubst $(SRC_PROJECT_DIR)%.cc,$(OBJ_PROJECT_DIR)%.o,$(SRC_PROJECT))
OBJ_TEST				= $(patsubst $(SRC_TEST_DIR)%.cc,$(OBJ_TEST_DIR)%.o,$(SRC_TEST))
FILES_TO_CHECK	= $(shell find . -name '*.cc' && find . -name '*.h')

.PHONY: all test build rebuild clang gcov_report gcovr_report clean valgrind

all: $(LIBRARY)

$(LIBRARY): build_folders $(OBJ_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

$(OBJ_PROJECT_DIR)%.o: $(SRC_PROJECT_DIR)%.cc
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TEST_DIR)%.o: $(SRC_TEST_DIR)%.cc
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(LDFLAGS)
	./test

gcov_report: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
	./test
	lcov -t test -o test.info -c -d . --no-external
	genhtml -o report test.info
	rm -rf ./*.gc*
	open report/index.html

gcovr_report: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
	./test
	mkdir gcovr/
	gcovr --html-details gcovr/report.details.html
	rm -rf ./*.gc*
	open gcovr/report.details.html

report_nohtml: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
	./test
	gcov *gcno > coverage.txt
	rm -rf ./*.gc*
	open coverage.txt

rebuild: clean $(LIBRARY)

build_folders:
	@mkdir -p $(OBJ_PROJECT_DIR); mkdir -p $(OBJ_TEST_DIR)

clean: 
	@rm -rf $(OBJ_PROJECT_DIR)*	
	@rm -rf $(OBJ_TEST_DIR)*
	@rm -rf *.dSYM
	@rm -rf $(LIBRARY)
	@rm -rf test
	@rm -rf gcovr
	@rm -rf report
	@rm -rf *.info
	@rm -rf *.txt
	@rm -rf obj*

valgrind: test
	valgrind $(VALGRIND_FLAGS) ./test
	! grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

stylecheck:
	@clang-format -n --style=Google $(FILES_TO_CHECK)
	@cpplint $(FILES_TO_CHECK)

