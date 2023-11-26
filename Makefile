
array:
	gcc -std=c11 -o bin/array array.c

branch:
	gcc -std=c11 -o bin/branch branch.c

inline:
	gcc -std=c11 -o bin/inline inline.c

pp_inline:
	gcc -std=c11 -o bin/pp_inline pp_inline.c

token:
	gcc -std=c11 -o bin/token token.c

regex_simply:
	gcc -std=c11 -o bin/regex_simply regex_simply.c -lpcre2-8

regex:
	gcc -std=c11 -o bin/regex regex.c -lpcre2-8

all:
	make array && make branch && make inline && make pp_inline && make token && make regex_simply && make regex

clean:
	rm -rf results/*
	rm -rf bin/*

.PHONY: all test clean