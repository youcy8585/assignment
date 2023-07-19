CC = gcc
CFLAGS = -Wall -Wextra

PROGRAM = add-nbo
SOURCE = add-nbo.c

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
        $(CC) $(CFLAGS) -o $@ $<

clean:
        rm -f $(PROGRAM)

~                          
