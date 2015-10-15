export CC

.PHONY: tests

all: tests

tests:
	bash ./tests/run_preprocessor_tests.sh || (exit 1)
	mkdir -p tests/build

	gcc tests/containerof_test.c -g -Iinclude -o ./tests/build/containerof_test
	./tests/build/containerof_test || (exit 1)
