#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fileGenerator() {
	FILE* ff;

	ff = fopen("data.txt", "w");

	fprintf(ff, "�� �̸��� %%s�̰� �̹��б� ������ %%d9999���̰� ������ %%c�� �޾ҽ��ϴ�.\n");
	fprintf(ff, "�� �̸��� ���� ���������̰� �̹��б� ������ 989999���̰� ������ A�� �޾ҽ��ϴ�.\n");

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
