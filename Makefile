PROG = Kim-Rabbani-Walker
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o encrypt.o decrypt.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o : 
	$(CC) $(CPPFLAGS) -c main.cpp

encrypt.o : encrypt.h
	$(CC) $(CPPFLAGS) -c encrypt.cpp

decrypt.o : decrypt.h
	$(CC) $(CPPFLAGS) -c decrypt.cpp

clean :
	$(RM) $(PROG) $(OBJS)
