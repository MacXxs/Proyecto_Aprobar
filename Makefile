OPCIONS= -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Cita.o Frase.o Texto.o Cjt_textos.o Cjt_cites.o
	g++ -o program.exe program.o Cita.o Frase.o Texto.o Cjt_textos.o Cjt_cites.o
Cita.o: Cita.cc
	g++ -c Cita.cc $(OPCIONS)
Frase.o: Frase.cc
	g++ -c Frase.cc $(OPCIONS)
Texto.o: Texto.cc
	g++ -c Texto.cc $(OPCIONS)
Cjt_textos.o: Cjt_textos.cc
	g++ -c Cjt_textos.cc $(OPCIONS)
Cjt_cites.o: Cjt_cites.cc
	g++ -c Cjt_cites.cc $(OPCIONS)
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
	
clean:
	rm *.o
	rm *.exe

