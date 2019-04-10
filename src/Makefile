CC=gcc
CFLAGS+=
LDFLAGS+= -ljson-c

all: libraries demotest
	@echo "compile done"

libraries:
	$(CC) $(CFLAGS) -Wall demo.c -shared -fPIC -o libgldemo.so $(LDFLAGS)

demotest: unittest.o
	$(CC) $^ -o $@ $(LDFLAGS) -L. -lgldemo

clean:
	rm $(PROC) $(OBJS)

.PHONY: all clean