// RockPaperScissor.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

enum enRockPaperScissor{Rock=1,Paper=2,Scissor=3};
enum enWinner{Player1=1,Computer=2, Draw =3};

struct stRoundInfo {
	short RoundNumber = 0;
	enRockPaperScissor playerChoose;
	enRockPaperScissor computerChoose;
	enWinner RoundWinner;
	string RoundwinnerName = "";
};
struct stGameResults {
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;

	enWinner GameWinner;
	string winnerName = "";


};

short ReadHowManyRounds1To10Number() {

	short number = 0;

	do {

		cout << "How many times you will play? 1 to 10 \n";
		cin >> number;
	} while (number <= 0 || number >10);
	return number;
} 
enRockPaperScissor ReadPlayerChooseNumber() {

	int number = 1;

	do {
		cout << "your choose: [1]:Rock, [2]:Paper, [3]:Scissors?  ";
		cin >> number;
	} while (number < 1 || number > 3);
	return (enRockPaperScissor)number;
}
int ReadIntNumber(string massage)
{
	int Number; 
	cout << massage;
	cin >> Number;
	return Number;
}

string WinnerName(enWinner winner) {
	string arrNames[3] = { "Player1","Computer","Draw" };
	return arrNames[winner - 1];
}

string ChooseName(enRockPaperScissor choose) {
	string arrNames[3] = { "Rock","Paper","Scissors" };
	return arrNames[choose - 1];
}
void PrintRoundNO(int roundNO) { 
	cout << "Round [" << roundNO << "] begins:\n\n";
}
void SetScreenColor(enWinner winner) {
	switch (winner)
	{
	case Player1:
		system("color 2F");
		break;
	case Computer:
		system("color 4F");
		cout << "\a";
		break;
	case Draw:
		system("color 6F");
		break;
	default:
		break;
	}
}
void PrintRoundResult(stRoundInfo roundInfo) {
	cout << "\n_____________________________Round [" << roundInfo.RoundNumber << "]:_____________________________\n\n";
	cout << "	Player1 choose: " << ChooseName(roundInfo.playerChoose) << endl;
	cout << "	Computer choose: " << ChooseName(roundInfo.computerChoose) << endl;
	cout << "	Round winner: " << WinnerName(roundInfo.RoundWinner) << endl;
	cout << "____________________________________________________________________\n\n";

	SetScreenColor(roundInfo.RoundWinner);
}
short RandomNumber(int From, int To)
{
	//Function to generate a random number
	short randNum = rand() % (To - From + 1) + From;
	return randNum;
}
enRockPaperScissor GetRandomChooseForComputer() {
	return (enRockPaperScissor)RandomNumber(1, 3);
}
enRockPaperScissor GetPlayerChoose(int number) { 

	switch (number)
	{
	case 1:
		return enRockPaperScissor::Rock;

	case 2:
		return enRockPaperScissor::Paper;

	case 3:
		return enRockPaperScissor::Scissor;
	default:
		break;
	}
}

enRockPaperScissor GetTheWinner(enRockPaperScissor player, enRockPaperScissor computer) { 

	switch (player,computer)
	{
	case enRockPaperScissor::Rock:enRockPaperScissor::Paper;
		return enRockPaperScissor::Rock;

	case 2:
		return enRockPaperScissor::Paper;

	case 3:
		return enRockPaperScissor::Scissor;
	default:
		break;
	}
}
 

void ShowFinalGameResults(stGameResults gameResults) {

	cout << "\t\t________________[ Game Results ]________________\n\n";
	cout << "\t\tGame Rounds: " << gameResults.GameRounds << endl;
	cout << "\t\tPlayer1 won times: " << gameResults.Player1WonTimes << endl;
	cout << "\t\tComputer won times: " << gameResults.ComputerWonTimes << endl;
	cout << "\t\tDraw times: " << gameResults.DrawTimes << endl;
	cout << "\t\tWinner name: " << gameResults.winnerName << endl;
	cout << "\t\t________________________________________________\n\n";
	SetScreenColor(gameResults.GameWinner);
}
void GameOverScreen() {

	cout << "\t\t________________________________________________\n\n";
	cout << "\t\t\t\t +++Game Over +++ \n";
	cout << "\t\t________________________________________________\n\n";
}
 
enWinner WhoWonTheRound(stRoundInfo roundInfo) {

	if (roundInfo.playerChoose == roundInfo.computerChoose)
		return enWinner::Draw;

	switch (roundInfo.playerChoose)
	{
		case enRockPaperScissor::Rock:
			if (roundInfo.computerChoose == enRockPaperScissor::Paper) {
				return enWinner::Computer;
			}
			break;
		case enRockPaperScissor::Paper:
			if (roundInfo.computerChoose == enRockPaperScissor::Scissor) {
				return enWinner::Computer;
			}
			break;

		case enRockPaperScissor::Scissor:
			if (roundInfo.computerChoose == enRockPaperScissor::Rock) {
				return enWinner::Computer;
			}
			break;
	}
	return enWinner::Player1;
}
enWinner WhoWonTheGame(short PlayerWons, short ComputerWons) {
	if (PlayerWons == ComputerWons)
		return enWinner::Draw;
	else if (PlayerWons > ComputerWons)
		return enWinner::Player1;
	else return enWinner::Computer;
}
stGameResults FillGameResults(short HowManyTimes, short PlayerWons, short ComputerWons, short drowTimes) {

	stGameResults gameResults;

	gameResults.GameRounds = HowManyTimes;
	gameResults.Player1WonTimes = PlayerWons;
	gameResults.ComputerWonTimes = ComputerWons;
	gameResults.DrawTimes = drowTimes;

	gameResults.GameWinner = WhoWonTheGame(PlayerWons, ComputerWons);
	gameResults.winnerName = WinnerName(gameResults.GameWinner);

	return gameResults;

}
stGameResults PlayGame(short HowManyTimes) {
	stRoundInfo roundInfo; 
	short playerWonCounter = 0, computerWonCounter = 0, drowTimesCounter = 0;

	for (short GameRound = 1; GameRound <= HowManyTimes; GameRound++) {

		cout << "Round [" << GameRound << "] begins:\n\n";
		roundInfo.RoundNumber = GameRound;
		roundInfo.playerChoose = ReadPlayerChooseNumber();
		roundInfo.computerChoose = GetRandomChooseForComputer();
		roundInfo.RoundWinner = WhoWonTheRound(roundInfo);
		roundInfo.RoundwinnerName = WinnerName(roundInfo.RoundWinner);

		if (roundInfo.RoundWinner == enWinner::Player1)
			playerWonCounter++;
		else if (roundInfo.RoundWinner == enWinner::Computer)
			computerWonCounter++;
		else
			drowTimesCounter++;

		PrintRoundResult(roundInfo);

	}

	return FillGameResults(HowManyTimes, playerWonCounter, computerWonCounter, drowTimesCounter);



}
void ResetScreen()
{
	system("cls");
	system("color 0F");
}
void StartGame() {
	char playAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults=PlayGame(ReadHowManyRounds1To10Number());
		GameOverScreen();
		ShowFinalGameResults(GameResults);


		cout << "\t\tDo you want to play again? Y/N?  \n";
		cin >> playAgain;
	} while (playAgain == 'Y' || playAgain == 'y');

}

int main()
{  
	//
	srand((unsigned)time(NULL));
	// 
	StartGame();

	return 0;
}
 