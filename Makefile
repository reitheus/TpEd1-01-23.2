
all: main.o grafoponderado.o lista.o
	@gcc main.o grafoponderado.o lista.o -o exe
	@rm *.o -r
main.o: main.c
	@gcc main.c -c -Wall
grafoponderado.o: grafoponderado.c
	@gcc grafoponderado.c -c -Wall
lista.o: lista.c
	@gcc lista.c -c -Wall
run:
	@./exe
