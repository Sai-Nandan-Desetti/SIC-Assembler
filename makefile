#makefile for making a SIC Assembler

General_fun:	General_fun.c
	gcc -c General_fun.c

Line_fun:	Line_fun.c
	gcc -c Line_fun.c

OpTab_fun:	OpTab_fun.c
	gcc -c OpTab_fun.c

SymTab_fun:	SymTab_fun.c
	gcc -c SymTab_fun.c

functions:	General_fun Line_fun OpTab_fun SymTab_fun
	
pass1:	pass1.c 
	gcc -o pass1 pass1.c General_fun.o Line_fun.o OpTab_fun.o SymTab_fun.o

remove:	
	rm *.inter
	rm *.o
