#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getlinen(int l);
int main() {
    system("clear");
	// Launcher Folder
	char *folder = malloc(sizeof(char) * 1024);
	sprintf(folder,"/home/%s/.launcher/",getenv("USER"));
	// game list
	char *list = malloc(sizeof(char) * 1024);
	sprintf(list,"%sgames",folder);
    FILE *name;
    char *line = NULL;
    char *ccmd[100];
    char *cgame[100];
    size_t len = 0;
    size_t read;
    int game = 0;
    char selected[10];
    int linenum = 1;
    name = fopen(list, "r");
    if (name == NULL) {
		// if file fails to open
		fprintf(stderr,"%s Failed to Open\n",list);
		return 2;
    }
	while ((read = getline(&line, &len, name)) != -1) {
		// Read Games and cmd
		if (linenum % 2 == 0) {
			ccmd[getlinen(linenum)] = malloc(100 * sizeof(char));
		    sprintf(ccmd[getlinen(linenum)], "%s", line);
		}
		else {
		    cgame[getlinen(linenum)] = malloc(100 * sizeof(char));
		    sprintf(cgame[getlinen(linenum)], "%s", line);
		}
		linenum++;
    }
    fclose(name);
    free(line);
    int i;
    for (i = 0; i < getlinen(linenum); i++) {
		// print games
		printf("%d: %s", i, cgame[i]);
    }
	// input
    printf("Game: ");
    fgets(selected, sizeof selected, stdin);
    selected[strcspn(selected, "\n")] = 0;
	//exit
	if(!strncmp(selected,"q",sizeof(selected)) | !strncmp(selected,"exit",sizeof(selected))){
		return 0;
	}
    // add to game list
    if (!strncmp(selected, "add", sizeof(selected))) {
		system("clear");
		FILE *add = fopen(list, "a");
		char game[256];
		char cmd[256];
		printf("New Game Name: ");
		fgets(game, sizeof game, stdin);
		fprintf(add, "%s", game);
		printf("New Game Command: ");
		fgets(cmd, sizeof cmd, stdin);
		fprintf(add, "%s", cmd);
		fclose(add);
		main();
    }
	//run the game
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
