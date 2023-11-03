all: main.o grafoponderado.o
	@gcc main.o grafoponderado.o -o exe
	rm -r *.o
main.o: main.c
	@gcc main.c -c -Wall
grafoponderado.o: grafoponderado.c
	@gcc grafoponderado.c -c -Wall
run:
	@./exe
