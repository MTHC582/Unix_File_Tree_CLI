

list: list.c utils/utils.c
	gcc list.c utils/utils.c -o list && ./list

cleanlist: 
	rm list

