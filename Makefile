export CC

.PHONY: tests

all: tests

tests:
	./tests/run_preprocessor_tests.sh || (exit 1)
