#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fileGenerator() {
	FILE* ff;

	ff = fopen("data.txt", "w");

	fprintf(ff, "내 이름은 %%s이고 이번학기 점수는 %%d9999점이고 성적은 %%c를 받았습니다.\n");
	fprintf(ff, "내 이름은 멋진 이은석님이고 이번학기 점수는 989999점이고 성적은 A를 받았습니다.\n");

	fclose(ff);
	return 0;
}
int fileReader(char *Format, char* input, int MAX) {
	FILE* ff;

	ff = fopen("data.txt", "r");

	fgets(Format, MAX, ff);
	fgets(input, MAX, ff);

	for (int i = 0; Format[i] != '\0'; i++) {
		if (Format[i] == '\n') { Format[i] = '\0'; }
	}
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '\n') { input[i] = '\0'; }
	}

	fclose(ff);
	return 0;
}
