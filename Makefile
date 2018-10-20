CFLAGS ?= -Wall -g -Og
CFLAGS_ENV := $(CFLAGS)

LIBS	:= $(shell pkg-config --static --libs glfw3) -lGL

OUT := lantern

all: $(OUT)

$(OUT): src/*.c
	$(CC) -o $(OUT) src/*.c $(LIBS) $(CFLAGS)

clean:
	rm $(OUT)
