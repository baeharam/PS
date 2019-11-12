#include <cstdio>
#include <algorithm>
using namespace std;

const int PLAYER_SIZE = 4;
const int DICE_SIZE = 10;
const int BOARD_SIZE = 40;
const int EXIT = -1;
const int DUPLICATE1 = 30;
const int DUPLICATE2 = 40;

int dice[DICE_SIZE + 1];
int pos[PLAYER_SIZE + 1];
int blue[PLAYER_SIZE + 1];
int cancel[PLAYER_SIZE + 1];
int dir[BOARD_SIZE + 1];
int board[BOARD_SIZE + 1][2];

int move(int cur, int num, int idx, int BL[], int CL[]){
	int next = EXIT;
	if(BL[idx]){
		while(num){
			if(CL[idx]) next = (cur == DUPLICATE1 ? 35 : dir[cur]);
			else next = dir[cur];
			if(next == EXIT) break;
			else if(next == 25) CL[idx] = 1;
			cur = next;
			num--;
		}
	}
	else{
		next = ((cur + 2*num) > BOARD_SIZE ? EXIT : (cur + 2*num));
		if(next == 10 || next == 20 || next == 30) BL[idx] = 1;
	}
	return next;
}

int refinePos(int P[], int CL[], int BL[], int idx){
	if(P[idx] == DUPLICATE1) return CL[idx];
	else if(P[idx] == DUPLICATE2) return 0;
	return BL[idx];
}

int dfs(int idx, int BO[][2], int P[], int BL[], int CL[], int score){
	if(idx > DICE_SIZE) return score;

	int TBO[BOARD_SIZE + 1][2];
	int TP[PLAYER_SIZE + 1];
	int TBL[PLAYER_SIZE + 1];
	int TCL[PLAYER_SIZE + 1];

	copy(&BO[0][0], &BO[0][0] + (BOARD_SIZE + 1)*2, &TBO[0][0]);
	copy(P, P + PLAYER_SIZE + 1, TP);
	copy(BL, BL + PLAYER_SIZE + 1, TBL);
	copy(CL, CL + PLAYER_SIZE + 1, TCL);

	int ans = -2e9;

	for(int i=1; i<=PLAYER_SIZE; i++){
		if(TP[i] == EXIT) continue;
		int orgPos = TP[i];
		int orgBlue = TBL[i];
		int orgCancel = TCL[i];

		TBO[orgPos][refinePos(TP,TCL,TBL,i)] = 0;
		TP[i] = move(TP[i], dice[idx], i, TBL, TCL);

		if(TP[i] == EXIT || !TBO[TP[i]][refinePos(TP,TCL,TBL,i)]){
			if(TP[i] != EXIT) TBO[TP[i]][refinePos(TP,TCL,TBL,i)] = 1;
			int TS = (TP[i] == EXIT ? 0 : TP[i]);
			ans = max(ans, dfs(idx+1, TBO, TP, TBL, TCL, score + TS));
			if(TP[i] != EXIT) TBO[TP[i]][refinePos(TP,TCL,TBL,i)] = 0;
		}

		TCL[i] = orgCancel;
		TBL[i] = orgBlue;
		TP[i] = orgPos;
		TBO[TP[i]][refinePos(TP,TCL,TBL,i)] = 1;
	}
	return ans;
}

int main(void)
{
	dir[10] = 13; dir[13] = 16;
	dir[16] = 19; dir[19] = 25;
	dir[20] = 22; dir[22] = 24;
	dir[24] = 25; dir[30] = 28;
	dir[28] = 27; dir[27] = 26;
	dir[26] = 25; dir[25] = 30;
	dir[30] = 28; dir[35] = 40;
	dir[40] = EXIT;

	for(int i=1; i<=DICE_SIZE; i++) scanf("%d",&dice[i]);
	printf("%d ", dfs(1, board, pos, blue, cancel, 0));
	puts("");
	return 0;
}