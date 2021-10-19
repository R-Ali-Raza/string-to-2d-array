#include <iostream>
#include <cstring>
using namespace std;
char* IgnorePunct(char input[]) {
	char* copy = new char[200];
	int i = 0, j = 0;
	while (input[j] != '\0') {
		if (!ispunct(input[j])) {
			if (isupper(input[j]))
				input[j] += 32;
			copy[i] = input[j];
			i++;
		}
		j++;
	}
	copy[i++] = ' ';				//There was a problem that if the auxillary verb is at the end then the next function may fail to delete it.
	copy[i] = '\0';
	delete[] input;
	return copy;
}
char* IgnoreVerbs(char input[]) {
	char* copy = new char[200];
	int i = 0, j = 0;
	while (input[j] != '\0') {
		if ((input[j] == 'i' && input[j + 1] == 's' && input[j + 2] == ' ' && input[j - 1] == ' ') || (input[j] == 'a' && input[j + 1] == 'm' && input[j + 2] == ' ' && input[j - 1] == ' ')) {
			j += 3;
			continue;
		}
		else if ((input[j] == 'a' && input[j + 1] == 'r' && input[j + 2] == 'e' && input[j + 3] == ' ' && input[j - 1] == ' ') || (input[j] == 'w' && input[j + 1] == 'a' && input[j + 2] == 's' && input[j + 3] == ' ' && input[j - 1] == ' ')) {
			j += 4;
			continue;
		}
		else if ((input[j] == 'w' && input[j + 1] == 'e' && input[j + 2] == 'r' && input[j + 3] == 'e' && input[j + 4] && input[j - 1] == ' ')) {
			j += 5;
			continue;
		}
		copy[i] = input[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	delete[] input;
	return copy;
}
void dim(char input[], int &words, int &maxLen) {
	for (int i = 0; input[i] != 0; i++) {
		int temp = 0;
		if (input[i] == ' ' || input[i] == 0) {
			words++;
			if (temp > maxLen) {
				maxLen = temp;
				temp = 0;
			}
		}
		else
		{
			temp++;
		}
	}
}
void Init(char input[], char **output) {
	for (int i = 0, k = 0; input[k] != 0; i++, k++) {
		int j = 0;
		for (; input[k] != ' ' && input[k] != '\0'; j++, k++) {
			output[i][j] = input[k];
		}
		output[i][j] = '\0';
	}
}
void disp(char** output, int words) {
	for (int i = 0; i < words; i++) {
		cout << output[i] << ' ';
	}
	return;
}
int main() {
	char* input, **output;
	int words = 0, maxLen = 0;
	input = new char[200];
	cout << "Enter the sentence ";
	cin.getline(input, 200);
	input = IgnorePunct(input);
	input = IgnoreVerbs(input);
	dim(input, words, maxLen);
	//dynamic memory allocation
	output = new char*[words];
	for (int i = 0; i < words; i++) {
		output[i] = new char[maxLen];
	}
	Init(input, output);
	disp(output, words);
	delete[]input;
	for (int i = 0; i < words; i++) {
		delete[] output[i];
	}
	return 0;
}
