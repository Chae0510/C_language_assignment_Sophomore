#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 8 
#define MAX_HOBBY_LEN 8	
#define MAX_PERSONS 30

struct PERSONAL {
	char name[20];
	int age;
	char hobby[20];
};


void copy_element(const PERSONAL* src, PERSONAL* dest) {

	strcpy(dest->name, src->name);
	dest->age = src->age;
	strcpy(dest->hobby, src->hobby);
}

bool read_file(const char* fname, PERSONAL persons[], int* num_persons) { 
	FILE* pFile;

	pFile = fopen(fname, "r");
	if (pFile == NULL) {

		printf("Error: Cannot Read File: %s\n", fname);
		*num_persons = 0;
		return false;
	}

	PERSONAL read_person;
	int num = 0;

	while (fscanf(pFile, "%s %d %s",
		&read_person.name,
		&read_person.age,
		&read_person.hobby) == 3) {

		copy_element(&read_person, &persons[num]);
		num++;
	}

	fclose(pFile);
	*num_persons = num;
	return true;
}


bool write_file_age(const char* fname, const PERSONAL persons[], const int num_persons) {

	FILE* pFile;

	pFile = fopen(fname, "w");

	if (pFile == NULL) {

		printf("Error: Cannot Open File: %s\n", fname);

		return false;
	}

	for (int i = 0; i < num_persons; i++) {
		fprintf(pFile, "%8s %d\n",
			persons[i].name,
			persons[i].age);
	}

	fclose(pFile);
	return true;
}

bool write_file_hobby(const char* fname, const PERSONAL persons[], const int num_persons) {

	FILE* pFile;

	pFile = fopen(fname, "w");

	if (pFile == NULL) {

		printf("Error: Cannot Open File: %s\n", fname);

		return false;
	}

	for (int i = 0; i < num_persons; i++) {
		fprintf(pFile, "%8s %8s\n",
			persons[i].name,
			persons[i].hobby);
	}

	fclose(pFile);
	return true;
}

int main(int argt, char* argv[]) {

	PERSONAL persons[MAX_PERSONS]; 
	int num_persons = 0;

	if (!read_file ("personal.txt", persons, &num_persons)) {
		return -1;
	}

	PERSONAL group_age[MAX_PERSONS];

	if (!write_file_age("age.txt", persons, num_persons)) {
		return -1;
	}

	PERSONAL group_hobby[MAX_PERSONS];

	if (!write_file_hobby("hobby.txt", persons, num_persons)) {
		return -1;
	}

	return 0;
}