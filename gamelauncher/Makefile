CC=tcc
CFLAGS=
OUT=gamelauncher
FILE=main.c
all: build
build: clean
	$(CC) $(FILE) -o $(OUT) $(CFLAGS)
clean:
	    rm -rf $(OUT)

test: build
	./$(OUT)
install: build
	sudo install $(OUT) /usr/bin/$(OUT)
	mkdir -p ~/.launcher/
	touch ~/.launcher/games
debug:
	$(CC) -g3 $(FILE) -o $(OUT) $(CFLAGS)
	gdb $(OUT)
