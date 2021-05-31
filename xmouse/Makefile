CC=tcc
CFLAGS=-Wall -lX11 -lXtst -lpthread -D _XOPEN_SOURCE=700
OUT=xmouse
FILE=main.c
build: clean
	$(CC) $(FILE) -o $(OUT) $(CFLAGS)
clean:
	    rm -rf $(OUT)

test: build
	./$(OUT)
install: build
	install $(OUT) /usr/bin/$(OUT)
debug: 
	$(CC) -g3 $(FILE) -o $(OUT) $(CFLAGS)
	gdb $(OUT)
