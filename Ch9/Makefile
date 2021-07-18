SRC=$(wildcard ./*.c)

PROGS=$(patsubst %.c, %, $(SRC))

all: $(PROGS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY:
	clean

clean:
	rm -f $(PROGS)