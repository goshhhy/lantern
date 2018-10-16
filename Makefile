 CFLAGS ?= -Wall -g -Og
CFLAGS_ENV := $(CFLAGS)

OUT := lantern

all: $(OUT)

$(OUT): src/*.c
	$(CC) -o $(OUT) src/*.c $(LIBS) $(CFLAGS)

clean:
	rm $(OUT)
