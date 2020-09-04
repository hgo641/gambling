// Project1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// 플레이어 클래스
class Player {
    string name;

public:
    void setName(string name);
    string getName();
};

// 게임 전체를 담당하는 클래스
class GamblingGame {
    Player* p;

public:
    GamblingGame();
    void setPlayer(Player p1, Player p2);
    void run();
    bool isWin(int arr[]);
    int randomGenerate();
};

// 2명의 플레이어 객체를 초기화하는 함수
GamblingGame::GamblingGame() {
    p = new Player[2];
}

// 3개의 숫자가 모두 일치하면 true를 반환하는 함수
bool GamblingGame::isWin(int arr[]) {
    if (arr[0] == arr[1])
        if (arr[1] == arr[2])
            return true;
    return false;
}

// 2명의 플레이어를 세팅하는 함수
void GamblingGame::setPlayer(Player p1, Player p2) {
    p[0] = p1;
    p[1] = p2;
}

// 게임 시작 함수
void GamblingGame::run() {
    int gameArray[3] = { 0 };

    // 무한루프를 돌면서 2명의 플레이어가 엔터를 누를때마다 겜블링 숫자를 받는다
    while (1) {
        cout << p[0].getName() << ": <Enter>";
        cin.get();
        gameArray[0] = randomGenerate();
        gameArray[1] = randomGenerate();
        gameArray[2] = randomGenerate();

        if (isWin(gameArray)) {
            cout << gameArray[0] << "     " << gameArray[1] << "    " << gameArray[2] << "   " << p[0].getName() << "님 승리!!" << endl;
            exit(0);
        }
        else
            cout << gameArray[0] << "     " << gameArray[1] << "    " << gameArray[2] << "   아쉽군요!" << endl;


        cout << p[1].getName() << ": <Enter>";
        cin.get();
        gameArray[0] = randomGenerate();
        gameArray[1] = randomGenerate();
        gameArray[2] = randomGenerate();

        if (isWin(gameArray)) {
            cout << gameArray[0] << "     " << gameArray[1] << "    " << gameArray[2] << "   " << p[1].getName() << "님 승리!!" << endl;
            exit(0);
        }
        else
            cout << gameArray[0] << "     " << gameArray[1] << "    " << gameArray[2] << "   아쉽군요!" << endl;
    }
}

// 난수를 리턴하는 함수
int GamblingGame::randomGenerate() {
    int tmp;
    tmp = rand() % 3;
    return tmp;
}

string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

int main(int argc, const char* argv[]) {
    // 난수 생성용 코드
    srand((unsigned)time(0));
    GamblingGame gg;
    Player p1;
    Player p2;
    string tmp;

    cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
    cout << "첫번째 선수 이름>> ";
    cin >> tmp;
    p1.setName(tmp);

    cout << "두번째 선수 이름>> ";
    cin >> tmp;
    cin.ignore();
    p2.setName(tmp);

    gg.setPlayer(p1, p2);
    gg.run();
    return 0;
}





// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
