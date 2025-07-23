#include <iostream>
#include <Windows.h>
#include <array>
#include <string>
#include <ctime>
constexpr int RANDOM_MAX = 8;
constexpr int RAND_CHAR_MAX = 6;

const std::array<std::string, RAND_CHAR_MAX> RAND_CHAR = {
	u8"�T",
	u8"�J",
	u8"�o",
	u8"��",
	u8"�X",
	u8"�s"
};

const std::array<int, RANDOM_MAX> CORRECT_NUM = {
	0,1,2,3,2,4,5,4
};

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));  // �����̏�����
	SetConsoleOutputCP(CP_UTF8);  // UTF-8�R�[�h�y�[�W�ɐݒ�
	while (true) {
		int loop_num = 0;
		std::cin >> loop_num;
		for (int i = 0; i < loop_num; i++) {
			int correct_count = 0;
			for (int c = 0; c < RANDOM_MAX; c++) {
				int random_num = rand() % RAND_CHAR_MAX;
				if (random_num == CORRECT_NUM[c]) {
					correct_count++;
				}
				printf_s(u8"%s", RAND_CHAR[random_num].c_str());
			}
			if (correct_count >= RANDOM_MAX) {
				printf_s(u8"��\n");
				break;
			}
			printf_s("\n");
		}
	}

	system("pause");
	return 0;
}