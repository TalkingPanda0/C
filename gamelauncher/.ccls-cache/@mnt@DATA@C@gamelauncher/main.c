#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LIST "/usr/share/launcher/games"
int Random(int lower, int upper);
int getlinen(int l);
int main() {
    system("clear");
    srand(time(NULL));
    size_t malloc_size = 100;
    FILE *name;
    char *line = NULL;
    char *ccmd[100];
    char *cgame[100];
    size_t len = 0;
    size_t read;
    int game = 0;
    char selected[10];
    int linenum = 1;
    name = fopen(LIST, "r");
    if (name == NULL) {
	// if file fails to open
	printf("File Failed to Open\nTrying to Create The File\n");
	system("touch " LIST);
	main();
    }

    while ((read = getline(&line, &len, name)) != -1) {
	if (linenum % 2 == 0) {
	    ccmd[getlinen(linenum)] = malloc(malloc_size * sizeof(char));
	    sprintf(ccmd[getlinen(linenum)], "%s", line);

	} else {
	    cgame[getlinen(linenum)] = malloc(malloc_size * sizeof(char));
	    sprintf(cgame[getlinen(linenum)], "%s", line);
	}
	linenum++;
    }
    fclose(name);
    if (line) {
	free(line);
    }
    int i;
    for (i = 0; i < getlinen(linenum); i++) {
	printf("%d: %s", i, cgame[i]);
    }
    printf("Game:");
    fgets(selected, sizeof selected, stdin);
    selected[strcspn(selected, "\n")] = 0;
    // random
    if (strncmp(selected, "rand", sizeof(selected)) == 0) {
	int gamenum = getlinen(linenum);
	int randgame = Random(1, gamenum--);
	printf("running %s \n", ccmd[randgame]);
	system(ccmd[randgame]);
	main();
    }
    // add
    if (strncmp(selected, "add", sizeof(selected)) == 0) {
	system("clear");
	FILE *add = fopen(LIST, "a");
	char game[256];
	char cmd[256];
	printf("New Game Name:");
	fgets(game, sizeof game, stdin);
	fprintf(add, "%s", game);
	printf("New Game Command:");
	fgets(cmd, sizeof cmd, stdin);
	fprintf(add, "%s", cmd);
	fclose(add);
	main();
    }

    game = atoi(selected);
    game++;
    printf("Running %s\n", ccmd[game]);
    system(ccmd[game]);
    main();
}

int getlinen(int l) {
    int a = l / 2;
    return a--;
}
int Random(int lower, int upper) {
    int num = (rand() % (upper + 1 - lower) + lower * 2);
    return num;
}
