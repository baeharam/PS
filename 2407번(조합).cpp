#include <iostream>
#include <string>
#include <cstring>


std::string combination[100 + 1][100 + 1];
const int long_len = 30;
char result[long_len+1]; // 최댓값이 30자리이므로 31자리로 설정.

// string을 더하는 함수
std::string addBig(std::string s1, std::string s2)
{
	int temp = 0, n, m;

	// s1이 더 크면 true s2가 더 크면 false
	bool whoisbig = s1.size() > s2.size() ? true : false;
	// s1과 s2의 크기가 다르면 true
	bool isdiff = s1.size() != s2.size() ? true : false;

	// 길이가 더 큰 길이 기준으로 계산해야 하기 때문에 (큰값 기준)
	int lenBig = whoisbig ? s1.size() : s2.size();
	int lenSmall = whoisbig ? s2.size() : s1.size();

	int len = long_len-1; // 결과 배열에 집어넣기 위해 상수길이 복사

	// 제일 뒤에서부터 시작해서 큰 길이가 사라질 때까지 계산을 계속한다.
	for (int i = lenBig - 1, j = lenSmall - 1; j >= 0; i--, j--){
		if (whoisbig){
			n = s1[i] - '0'; // 문자를 숫자로 변환
			m = s2[j] - '0';
		}
		else{
			n = s1[j] - '0'; // 문자를 숫자로 변환
			m = s2[i] - '0';
		}
		
		temp = n + m + temp; // 숫자로 변환한 값을 더함, 이 때 temp에 1이있을수 있으므로 같이 더해준다.
		// 더했을 때 두자리가 되면 일의 자리만 결과 배열에 넣는다.
		if (temp / 10 != 0) {
			result[len--] = (temp % 10) + '0';
			temp = 1; // 십의자리는 항상 1이므로 1저장
		}
		else{
			result[len--] = temp + '0';
			temp = 0; // 초기화
		}
	}

	// 다 끝나고 10의 자리가 있을 경우 채워줘야 한다.
	// 단, 크기가 다르면 안된다.
	if (temp && !isdiff) result[len] = '1';

	// 1) 크기가 다르면서 더한 값이 10이상인 경우 : 앞자리+temp를 더해줘야 됨
	// 2) 크기가 다르면서 더한 값이 10미만인 경우 : 앞자리만 더해주면 됨
	else if (isdiff){
		if (whoisbig){
			// temp랑 더한 값도 10이상일 수 있으므로 그 경우들에 대한
			// 처리를 해주어야 함
			for (int i = s1.size() - s2.size()-1; i>=0; i--){
				int toResult = (s1[i] - '0') + temp;
				if (toResult / 10 != 0){
					result[len--] = (toResult % 10) + '0';
					temp = 1;
				}
				else{
					result[len--] = toResult + '0';
					temp = 0;
				}
			}	
		}  
		else{
			for (int i = s2.size() - s1.size() - 1; i >= 0; i--){
				int toResult = (s2[i] - '0') + temp;
				if (toResult / 10 != 0){
					result[len--] = (toResult % 10) + '0';
					temp = 1;
				}
				else{
					result[len--] = toResult + '0';
					temp = 0;
				}
			}
		}

		// temp가 0이 아니란 소리는 더해서 10이 넘었는데 자리수가 끝난 경우이므로
		// 처리해준다.
		if (temp) result[len] = temp+'0';
	}

	

	std::string toReturn;


	// result 배열의 0이 아닌값만 다시 real_result에 넣는다.
	for (int i = 0; i < long_len; i++){
		if (result[i] != '\0')
			toReturn.append(std::to_string(result[i]-'0'));
	}

	for (int i = 0; i <= long_len; i++) result[i] = '\0'; // result배열 초기화

	return toReturn;
}

int main(void)
{


	int n, m; std::cin >> n >> m;

	// 1C0=1C1=1로 설정
	combination[1][0] = combination[1][1] = "1";

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || i == j) combination[i][j] = "1";
			else if (j == 1) combination[i][j] = std::to_string(i);
			else combination[i][j] = addBig(combination[i - 1][j - 1], combination[i - 1][j]);
		}
	}

	std::cout << combination[n][m];

	

	
	return 0;
}