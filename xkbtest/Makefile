CC=tcc 
CFLAGS=-lX11 -lXtst -D _XOPEN_SOURCE=700
OUT=xkbtest
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
