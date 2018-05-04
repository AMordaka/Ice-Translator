all: Printer.h Printer.cpp client server Client.o Server.o Translator.o 

Printer.cpp Printer.h: Printer.ice
	slice2cpp Printer.ice

Translator.o: Translator.cpp Translator.h
	c++ -I. -c Printer.cpp Translator.cpp

Server.o: Server.cpp Translator.h
	c++ -I. -c Printer.cpp Server.cpp Translator.cpp
	
Client.o: Client.cpp
	c++ -I. -c Printer.cpp Client.cpp

client: Client.o
	c++ -o client Printer.o Client.o -pthread -lIce

server: Server.o
	c++ -o server Printer.o Server.o Translator.o -pthread -lIce

