.PHONY: all

all: quick_find quick_union quick_union_weighted

quick_find: quick_find.c
	gcc quick_find.c -o bin/quick_find

quick_union: quick_union.c
	gcc quick_union.c -o bin/quick_union

quick_union_weighted: quick_union_weighted.c
	gcc quick_union_weighted.c -o bin/quick_union_weighted
