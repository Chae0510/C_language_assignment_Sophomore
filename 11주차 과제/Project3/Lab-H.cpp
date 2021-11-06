#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 8
#define MAX_HOBBY_LEN 8
#define MAX_PERSONS 30

struct PERSONAL {
	char name[MAX_NAME_LEN];
	int age;
	char hobby[MAX_HOBBY_LEN];
};

void copy_element(const PERSONAL* src, PERSONAL* dest) {
	strcpy(dest->name, src->name);
	dest->age = src->age;
	strcpy(dest->hobby, src->hobby);
}

bool read_file_age(const char* fname, PERSONAL persons[], int* num_persons) {
	FILE* pFile;

	pFile = fopen(fname, "r");

	if (pFile == NULL) {
		printf("Error: Cannot Read File: %s\n", fname);
		*num_persons = 0;
		return false;
	}

	PERSONAL read_person;
	int num = 0;

	while (fscanf(pFile, "%s %d %s", &read_person.name, &read_person.age, &read_person.hobby) == 3) {
		copy_element(&read_person, &persons[num]);
		num++;
	}

	fclose(pFile);

	*num_persons = num;

	return true;
}

bool write_file(const char* fname, const PERSONAL persons[], const int num_persons, int age10, int age20, int age30, int age40) {
	FILE* pFile;
	 
	pFile = fopen(fname, "w");

	if (pFile == NULL) {
		printf("Error: Cannot Open File: %s\n", fname);
		return false;

	}

	fputs("\nAge from 10 to 19\n", pFile);
	fputs("---------------------------\n", pFile);
	for (int i = 0; i < age10; i++) {

		fprintf(pFile, "%8s %d %8s \n", persons[i].name, persons[i].age, persons[i].hobby);

	}

	fputs("\nAge from 20 to 29\n", pFile);
	fputs("---------------------------\n", pFile);
	for (int i = age10; i < age20; i++) {

		fprintf(pFile, "%8s %d %8s \n", persons[i].name, persons[i].age, persons[i].hobby);

	}
	fputs("\nAge from 30 to 39\n", pFile);
	fputs("---------------------------\n", pFile);
	for (int i = age20; i < age30; i++) {

		fprintf(pFile, "%8s %d %8s \n", persons[i].name, persons[i].age, persons[i].hobby);

	}
	fputs("\nAge from 40 to 49\n", pFile);
	fputs("---------------------------\n", pFile);
	for (int i = age30; i < age40; i++) {

		fprintf(pFile, "%8s %d %8s \n", persons[i].name, persons[i].age, persons[i].hobby);

	}

	fclose(pFile);

	return true;
}

void group_by_age(const PERSONAL original[], 
	const int num_persons, 
	PERSONAL grouped[], int* age10, int* age20, int* age30, int* age40)
{
	int index = 0;

	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 10) {
			copy_element(&original[i], &grouped[index]);
			index++;

		}
	}
	*age10 = index;

	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 20) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}
	*age20 = index;

	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 30) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}
	*age30 = index;

	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 40) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}
	*age40 = index;

}
int main(int argc, char* argv[]) {
	PERSONAL persons[MAX_PERSONS];
	int num_persons = 0;
	int age10, age20, age30, age40 = 0;

	if (!read_file_age("personal.txt", persons, &num_persons)) {
		return -1;
	}
	PERSONAL group_age[MAX_PERSONS];

	group_by_age(persons, num_persons, group_age, &age10, &age20, &age30, &age40);

	if (!write_file("output.txt", group_age, num_persons, age10, age20, age30, age40)) {
		return -1;
	}

	return 0;
}