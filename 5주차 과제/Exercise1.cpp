#include <stdio.h>
#include <string.h>

int Search_String(char* string, char* search) {

    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == search[0]) {
            int cursor = 0;
            for (int j = 0; j < strlen(search); j++) {
                if (string[i + j] == search[j]) {
                    cursor++;
                }
            }
            if (cursor == strlen(search)){
                count++;
            }
        }
    }

    return count++;
}



#define NUM_TEST_SET 5

int main() {
	char test_str[NUM_TEST_SET][256] = { "Is your name Bob?",
	"No, my name is Rob.",
	"Hello, Rob.",
	"A thief named hong gil dong lived with friends named hong gil donand hong gil ja in a village named hong gil dong village.",
	"A thief named hong gil dong lived with friends named hong don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village." };

	char test_search_str[NUM_TEST_SET][128] = { "name","name","name", "hong gil dong", "hong gil dong" };

	for (int t = 0; t < NUM_TEST_SET; t++) {
		char* str = test_str[t];
		char* search_str = test_search_str[t];

		int num_matches = Search_String(str, search_str);

		printf("\n// --- Experiment(%d) ---\n", t + 1);
		printf("[String: ] %s\n", str);
		printf("[Search: ] %s\n", search_str);
		printf("[Num Mateches: ] %d\n", num_matches);
	}

	return 0;
}