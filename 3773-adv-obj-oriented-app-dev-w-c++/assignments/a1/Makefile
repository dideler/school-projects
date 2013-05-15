# @author Dennis Ideler <ideler.dennis@gmail.com>
#
# The basic syntax of a Makefile entry looks like:
# <target>: [ <dependency > ]*
#    [ <TAB> <command> <endl> ]+
#
# For more info on Makefiles:
# http://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html

CC = g++
STD = -std=c++0x  # Use the C++11 standard.
DEBUG = -g
OPTIMIZE = -O3
WARNINGS = -Wall -Wextra -Werror
CFLAGS = $(STD) $(WARNINGS) -c $(DEBUG) # Compiling flags
LFLAGS = $(STD) $(WARNINGS) $(DEBUG) # Linking flags

# If make is called without a target, it runs the first target, so this one.
all: ex3.3 ex3.9 clean

OBJ1 = line.o line_test.o point.o
ex3.3: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex3.3
line.o:	line.cpp line.h
	$(CC) $(CFLAGS) line.cpp
line_test.o: line_test.cpp line.h
	$(CC) $(CFLAGS) line_test.cpp
line.h: point.h
# add no_intersect_exception.h to line.h target when it exists
point.o: point.cpp point.h
	$(CC) $(CFLAGS) point.cpp

OBJ2 = item.o item_test.o book.o
ex3.9: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex3.9
item.o: item.cpp item.h
	$(CC) $(CFLAGS) item.cpp
item_test.o: item_test.cpp item.h book.h
	$(CC) $(CFLAGS) item_test.cpp
book.o: book.cpp book.h
	$(CC) $(CFLAGS) book.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex3.3 ex3.9
