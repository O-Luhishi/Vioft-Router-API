CC=gcc
CFLAGS+=
LDFLAGS+= -ljson-c

all: libraries api
	@echo "compile done"

libraries:
	$(CC) $(CFLAGS) -Wall api.c -shared -fPIC -o libgldemo.so $(LDFLAGS)

api: unittest.o
	$(CC) $^ -o $@ $(LDFLAGS) -L. -lgldemo

clean:
	rm $(PROC) $(OBJS)

.PHONY: all clean