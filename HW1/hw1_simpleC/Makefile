EXEC=test
OBJS=$(EXEC).o
SRC=$(EXEC).c

CFLAGS= -ftest-coverage -fprofile-arcs
LDFLAGS= --coverage -lgcov -fprofile-arcs
CC=gcc

all:$(EXEC)

$(EXEC):$(OBJS)

$(OBJS):$(SRC)

clean:
	rm -f $(EXEC) *.o *.g* *.info



