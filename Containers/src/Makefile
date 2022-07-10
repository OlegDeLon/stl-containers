all: clean test

test: clean
	g++ --coverage test.cpp -o test -lgtest
	./test

gcov_report: tests
	lcov --no-external -t  "test" -o test.info -c -d ./
	genhtml -o report test.info
	open ./report/index.html

leaks: test
	leaks -atExit -- ./test	

check:
	cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem *.cpp *.inl
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h *.inl

	rm -f CPPLINT.cfg

clean:
	rm -rf *.o *.a *.out *.gcno *.gcda *.info *.cfg  tmp.check report gcov_report gcov_exe test s21_containers
