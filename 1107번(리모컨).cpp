#include <iostream>
#include <string>
#include <cmath>

// 리모컨의 0~9숫자중 뭐가 고장났는지 체크하는 전역배열
bool remote[10];

// 번호를 눌러서 이동할 수 있는 채널인지 확인하는 함수
bool checkChannel(int channel)
{
	std::string channelString = std::to_string(channel);
	bool check = true;
	for (int i = 0; i < channelString.size(); i++) {
		if (remote[channelString[i]-'0'] == false) {
			check = false;
			break;
		}
	}
	return check;
}

int main(void)
{
	while (true) {
		// 먼저 리모컨의 모든 버튼이 동작한다고 가정
		for (int i = 0; i < 10; i++) remote[i] = true;
		int n, m, input; std::cin >> n >> m;
		// 입력받은 번호들을 고장난 것(false)으로 설정
		while (m--) {
			std::cin >> input;
			remote[input] = false;
		}

		// buttonNum = 리모컨의 버튼을 누른 횟수
		// channel_up, channel_down = 타겟채널에서 위/아래로 가는 2가지 경우
		int buttonNum = 0, channel_up = n, channel_down = n;

		// buttonPlus, buttonMinus = +,-버튼, buttonBegin = 현재채널에서 +,-버튼만을 이동해서 갈 때 눌러지는 횟수 (절댓값)
		int buttonPlus = 0, buttonBegin = std::abs(n - 100);

		// 0을 제외한 모든 숫자버튼이 고장났는지 확인하는 변수, 모든 버튼이 고장나면 +,-만 사용할 수 있기 때문이다.
		bool isAllbroken = true;
		for (int i = 1; i < 10; i++) {
			// 1~9의 버튼 중 하나라도 작동하면 바로 빠져나온다.
			if (remote[i] == true) {
				isAllbroken = false;
				break;
			}
		}

		// 0을 제외한 숫자들 중 고장나지 않은 버튼이 하나라도 있을 경우
		if (!isAllbroken) {
			// 타겟 채널에 최대한 가까이 위로 이동
			while (!checkChannel(channel_up)) {
				channel_up++;
				buttonPlus++;
			}
			// 번호로 이동한 만큼 더해준다.
			std::cout << channel_up << "으로 이동한 후에 " << buttonPlus << "만큼 내려온다.\n";
			buttonPlus += std::to_string(channel_up).size();
			// 현재 채널에서 이동하는 것과 위에서 계산한 값 중 더 작은값을 buttonNum으로 초기화
			buttonNum = buttonPlus > buttonBegin ? buttonBegin : buttonPlus;

			// 타겟 채널이 0이면 아래로 내려갈 수 없기 때문에 그 경우만 제외
			if (channel_down != 0) {
				int buttonMinus = 0;
				// 타겟 채널에 최대한 가까이 아래로 이동 (최소 0까지만 이동가능)
				while (!checkChannel(channel_down) && channel_down != 0) {
					channel_down--;
					buttonMinus++;
				}
				// 위의 while문을 나올 수 있는 경우가 channel_down==0인 경우도 있으므로
				// 그게 이동할 수 있는 채널인지 확인.
				if (checkChannel(channel_down)) {
					std::cout << channel_down << "으로 이동한 후에 " << buttonMinus << "만큼 올라간다.\n";
					// 번호로 이동한 만큼 더해준다.
					buttonMinus += std::to_string(channel_down).size();

					// 위에서 더 적은 값과 비교해서 buttonNum을 최종 설정
					buttonNum = buttonNum > buttonMinus ? buttonMinus : buttonNum;
				}
			}
		}
		// 0이 고장나지 않았다면 0에서 타겟채널로 가는 것과 100에서 타겟채널로 가는 것 중 더 적은횟수를 저장
		else if (remote[0] == true) buttonNum = buttonBegin > n + 1 ? n + 1 : buttonBegin;
		// 0이 고장났다면 현재채널인 100에서 +,-만으로 갈 수 있는 횟수 계산한 값이 답이 된다.	
		else buttonNum = buttonBegin;



		std::cout << buttonNum << '\n';
	}
	

	return 0;
}