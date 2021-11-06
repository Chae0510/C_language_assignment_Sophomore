#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_REGION_LENS 12
#define MAX_CANDIDATE_LENS 12
#define MAX_FULL 3000

struct  PERSONAL {
	char region[MAX_REGION_LENS];
	int age;
	char candidate[MAX_CANDIDATE_LENS];
};

void copy_element(const PERSONAL* src, PERSONAL* dest) {
	strcpy(dest->region, src->region);
	dest->age, src->age;
	strcpy(dest->candidate, src->candidate);
}

bool read_file_age(const char* fname, PERSONAL persons[], int* num_persons) { 
	
	FILE* pFile;

	pFile = fopen(fname, "r");
	if (pFile == NULL) { 

		printf("Error: Cannot Read File: %s\n", fname);
		*num_persons = 0;
		return false; // 수행하지 않고 멈추게
	}

	PERSONAL read_person;
	int num = 0;

	while (fscanf(pFile, "%s %d %s",
		&read_person.region,
		&read_person.age,
		&read_person.candidate) == 3) {

		copy_element(&read_person, &persons[num]);
		num++;
	}

	fclose(pFile);
	*num_persons = num;
	return true;
}

bool write_file(const char* fname, const PERSONAL persons[], const int num_persons /*셋 다 input 이라는 사실 한 눈에 알 수 있음*/) {

	FILE* pFile;

	pFile = fopen(fname, "w");

	if (pFile == NULL) { 

		printf("Error: Cannot Open the File: %s\n", fname);

		return false; 
	}

	for (int i = 0; i < num_persons; i++) {
		fprintf(pFile, "%12s %d %12s\n",
			persons[i].region,
			persons[i].age,
			persons[i].candidate);
	}

	fclose(pFile);
	return true;
}

void countcan(const PERSONAL original[], const int num_vote, PERSONAL grouped[]) {
	int index = 0;

	for (int i = 0; i < num_vote; i++) {
		copy_element(&original[i], &grouped[index]);
		index++;
	}

	int W_voted = 0, L_voted = 0, R_voted = 0;
	
	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'W') {
			W_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'L') {
			L_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'R') {
			R_voted++;
		}
	}

	printf("%d\n", index);
	printf("%d %d %d\n", W_voted, L_voted, R_voted);
	printf("Washington's percentage of votes : %.2f%%\n", W_voted / double(index) * 100.0);
	printf("Lincoln's percentage of votes : %.2f%%\n", L_voted / double(index) * 100.0);
	printf("Roosevelt's percentage of votes : %.2f%%\n\n\n", R_voted / double(index) * 100.0);
}

void count_3(const PERSONAL original[], const int num_vote, PERSONAL grouped[]) {
	int index = 0;

	for (int i = 0; i < num_vote; i = i + 3) {
		copy_element(&original[i], &grouped[index]);
		index++;
	}


	int W_voted = 0, L_voted = 0, R_voted = 0;

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'W') {
			W_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'L') {
			L_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'R') {
			R_voted++;
		}
	}

	printf("%d\n", index);
	printf("%d %d %d\n", W_voted, L_voted, R_voted);
	printf("Washington's percentage of votes(3th row)  : %.2f%%\n", W_voted / double(index) * 100.0);
	printf("Lincoln's percentage of votes(3th row) : %.2f%%\n", L_voted / double(index) * 100.0);
	printf("Roosevelt's percentage of votes(3th row) : %.2f%%\n\n\n", R_voted / double(index) * 100.0);


}

void count_10(const PERSONAL original[], const int num_vote, PERSONAL grouped[]) {
	int index = 0;

	for (int i = 0; i < num_vote; i = i + 10) {
		copy_element(&original[i], &grouped[index]);
		index++;
	}


	int W_voted = 0, L_voted = 0, R_voted = 0;

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'W') {
			W_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'L') {
			L_voted++;
		}
	}

	for (int i = 0; i < index; i++) {
		char ch = grouped[i].candidate[0];
		if (ch == 'R') {
			R_voted++;
		}
	}

	printf("%d\n", index);
	printf("%d %d %d\n", W_voted, L_voted, R_voted);
	printf("Washington's percentage of votes(10th row)  : %.2f%%\n", W_voted / double(index) * 100.0);
	printf("Lincoln's percentage of votes(10th row) : %.2f%%\n", L_voted / double(index) * 100.0);
	printf("Roosevelt's percentage of votes(10th row) : %.2f%%\n\n\n", R_voted / double(index) * 100.0);


}

int main() {
	PERSONAL persons[MAX_FULL];
	int num_persons = 0;

	if (!read_file_age("vote.txt", persons, &num_persons)) { // ! : reading failed 텍스트 파일 읽어오기 실패(외부요인)
		return -1;
	}

	if (!write_file("vote.txt", persons, num_persons)) {
		return -1;
	}

	PERSONAL group_candidate[MAX_FULL];
	countcan(persons, num_persons, group_candidate);
	if (!write_file("vote.txt", group_candidate, num_persons)) {
		return -1;
	}

	PERSONAL count3[MAX_FULL];
	count_3(persons, num_persons, count3);
	if (!write_file("vote.txt", group_candidate, num_persons)) {
		return -1;
	}

	PERSONAL count10[MAX_FULL];
	count_10(persons, num_persons, count10);
	if (!write_file("vote.txt", group_candidate, num_persons)) {
		return -1;
	}
}
