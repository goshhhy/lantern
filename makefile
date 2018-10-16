LIBS	:= $(shell pkg-config --static --libs glfw3) -lGL


HEADERS := 	\

OBJS 	:= 	build/main.o 				\
			build/backend/backend.o 	\
			build/backend/glfw/glfw.o 	\

OUT := lantern

.PHONY: clean gameclean engine game distclean lua

default: $(OUT)

build/%.o: engine/%.c
	mkdir -p build/$*
	$(CC) -c -o $@ $<

$(OUT): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) $(LIBS) 


distclean: clean gameclean

clean:
	-@rm -f build/*.o $(OUT)
