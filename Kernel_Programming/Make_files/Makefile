

executable.out : main_file.o sum_digits.o 
	gcc main_file.o sum_digits.o
main_file.o: main_file.c
	gcc -c main_file.c 
sum_digits.o: sum_digits.c
	gcc -c sum_digits.c


clean:
	rm *.o a.out
