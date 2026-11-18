
tree: tree.c utils/utils.c
	gcc tree.c utils/utils.c -o tree && ./tree

list: list.c utils/utils.c
	gcc list.c utils/utils.c -o list && ./list

clean:
	rm list tree

