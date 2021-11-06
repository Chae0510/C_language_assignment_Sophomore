#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#define NUM_TEST_SET 3

struct DATASET {
	char name[10];
	int age;
	char hobby[10];
} dataset[] = {
		{"Kim", 39, "Tennis"},
		{"Ko",15,"Soccer"},
		{"Lee", 17, "Soccer"},
		{"Choi",21, "Tennis"},
		{"Park", 10, "Tennis"}
};

struct INDEX {
	char key[10];
	int index;
} index[] = {
	{"Kim", 0},
	{"Ko",1},
	{"Lee",2},
	{"Choi", 3},
	{"Park",4}
};

int Search_Index(const char* search) {
	int s_k = 0;
	for (int i = 0; i < 5; i++) {
		if (strcmp(search, index[i].key) == 0) {
			s_k = i;
			break;
		}
		else {
			s_k = -1;
		}
	}
	return s_k;
}
int main()
{
	char test_search_keys[NUM_TEST_SET][10] = { "Lee", "Cha", "Park" };

	for (int t = 0; t < NUM_TEST_SET; t++)
	{
		char* search_key = test_search_keys[t];
		int index = Search_Index(search_key);

		printf("\n//--- Experiment(%d) --- \n", t + 1);
		printf("[Key:] [%s]\n", search_key);

		if (index < 0) {
			printf("The Key does not exist !!\n");
		}
		else {
			printf("result: index(%d), name(%s), age(%d), hobby(%s)\n", index,
				dataset[index].name, dataset[index].age, dataset[index].hobby);
		}
	}
	return 0;
}