test: main.c linked-list.c
	gcc  main.c linked-list.c -o test
clean:
	rm -f *.o *.exe