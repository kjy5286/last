#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

SceneID scene[4];
ObjectID start[3];
ObjectID peace3[25];
ObjectID peace[16];
ObjectID peace2[9];
ObjectID restart[3];
TimerID timer;
SoundID BGM;
int coor[16][2] = { {750,20},{600,20},{450,20},{300,20},{750,170},{600,170},{450,170},{300,170},{750,320},{600,320},{450,320},{300,320},{750,470},{600,470},{450,470},{300,470} };
int coor2[9][2] = { {850,240},{700,240},{550,240},{850,390},{700,390},{550,390},{850,540},{700,540},{550,540} };
int coor3[25][2] = { {1080,80},{960,80},{840,80},{720,80},{600,80},{1080,200},{960,200},{840,200},{720,200},{600,200},{1080,320},{960,320},{840,320},{720,320},{600,320},{1080,440},{960,440},{840,440},{720,440},{600,440},{1080,560},{960,560},{840,560},{720,560},{600,560} };
bool exist[25];
int count[3] = { 0,0,0 };
int time2 = 0;
char T[256];
char C1[256];
char C2[256];
char C3[256];

//음악 함수
SoundID createSound2(const char* sound, bool que) {
    SoundID music = createSound(sound);
    if (que == true) {
        playSound(music);
    }
    return music;
}

//오브젝트 생성 함수
ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
    ObjectID object = createObject(image);
    locateObject(object, scene, x, y);
    if (shown == true) {
        showObject(object);
    }
    return object;
}

//타이머 함수 
TimerID createTimer2(Second second) {
    TimerID timer = createTimer(second);
    return timer;
}

//게임 시작 함수
void gamestartI(int i) {
    if (i == 0) {
        stopSound(BGM);
        int rand_num = 0;
        srand(time(NULL));
        for (int i = 0; i <= 100; i++) {
            rand_num = rand() % 8;
            int bridge_X = coor2[0][0];
            coor2[0][0] = coor2[rand_num][0];
            coor2[rand_num][0] = bridge_X;
            int bridge_Y = coor2[0][1];
            coor2[0][1] = coor2[rand_num][1];
            coor2[rand_num][1] = bridge_Y;
            locateObject(peace2[rand_num], scene[2], coor2[rand_num][0], coor2[rand_num][1]);
            locateObject(peace2[0], scene[2], coor2[0][0], coor2[0][1]);
        }
        setTimer(timer, 1);
        startTimer(timer);
    }
    if (i == 1) {
        stopSound(BGM);
        int rand_num = 0;
        srand(time(NULL));
        for (int i = 0; i <= 100; i++) {
            rand_num = rand() % 15;
            int bridge_X = coor[0][0];
            coor[0][0] = coor[rand_num][0];
            coor[rand_num][0] = bridge_X;
            int bridge_Y = coor[0][1];
            coor[0][1] = coor[rand_num][1];
            coor[rand_num][1] = bridge_Y;
            locateObject(peace[rand_num], scene[1], coor[rand_num][0], coor[rand_num][1]);
            locateObject(peace[0], scene[1], coor[0][0], coor[0][1]);
        }
        setTimer(timer, 1);
        startTimer(timer);

    }
    if (i == 2) {
        stopSound(BGM);
        int rand_num = 0;
        srand(time(NULL));
        for (int i = 0; i <= 100; i++) {
            rand_num = rand() % 24;
            int bridge_X = coor3[0][0];
            coor3[0][0] = coor3[rand_num][0];
            coor3[rand_num][0] = bridge_X;
            int bridge_Y = coor3[0][1];
            coor3[0][1] = coor3[rand_num][1];
            coor3[rand_num][1] = bridge_Y;
            locateObject(peace3[rand_num], scene[3], coor3[rand_num][0], coor3[rand_num][1]);
            locateObject(peace3[0], scene[3], coor3[0][0], coor3[0][1]);
        }
        setTimer(timer, 1);
        startTimer(timer);
    }
}

//퍼즐생성함수
void createpuzzle(int g) {
    if (g == 0) {
        peace2[0] = createObject("1_09.png", scene[2], coor2[0][0], coor2[0][1], exist[0]);
        peace2[1] = createObject("1_08.png", scene[2], coor2[1][0], coor2[1][1], exist[1]);
        peace2[2] = createObject("1_07.png", scene[2], coor2[2][0], coor2[2][1], exist[2]);
        peace2[3] = createObject("1_06.png", scene[2], coor2[3][0], coor2[3][1], exist[3]);
        peace2[4] = createObject("1_05.png", scene[2], coor2[4][0], coor2[4][1], exist[4]);
        peace2[5] = createObject("1_04.png", scene[2], coor2[5][0], coor2[5][1], exist[5]);
        peace2[6] = createObject("1_03.png", scene[2], coor2[6][0], coor2[6][1], exist[6]);
        peace2[7] = createObject("1_02.png", scene[2], coor2[7][0], coor2[7][1], exist[7]);
        peace2[8] = createObject("1_01.png", scene[2], coor2[8][0], coor2[8][1], exist[8]);

    }
    if (g == 1) {
        peace[0] = createObject("2_16.png", scene[1], coor[0][0], coor[0][1], exist[0]);
        peace[1] = createObject("2_15.png", scene[1], coor[1][0], coor[1][1], exist[1]);
        peace[2] = createObject("2_14.png", scene[1], coor[2][0], coor[2][1], exist[2]);
        peace[3] = createObject("2_13.png", scene[1], coor[3][0], coor[3][1], exist[3]);
        peace[4] = createObject("2_12.png", scene[1], coor[4][0], coor[4][1], exist[4]);
        peace[5] = createObject("2_11.png", scene[1], coor[5][0], coor[5][1], exist[5]);
        peace[6] = createObject("2_10.png", scene[1], coor[6][0], coor[6][1], exist[6]);
        peace[7] = createObject("2_09.png", scene[1], coor[7][0], coor[7][1], exist[7]);
        peace[8] = createObject("2_08.png", scene[1], coor[8][0], coor[8][1], exist[8]);
        peace[9] = createObject("2_07.png", scene[1], coor[9][0], coor[9][1], exist[9]);
        peace[10] = createObject("2_06.png", scene[1], coor[10][0], coor[10][1], exist[10]);
        peace[11] = createObject("2_05.png", scene[1], coor[11][0], coor[11][1], exist[11]);
        peace[12] = createObject("2_04.png", scene[1], coor[12][0], coor[12][1], exist[12]);
        peace[13] = createObject("2_03.png", scene[1], coor[13][0], coor[13][1], exist[13]);
        peace[14] = createObject("2_02.png", scene[1], coor[14][0], coor[14][1], exist[14]);
        peace[15] = createObject("2_01.png", scene[1], coor[15][0], coor[15][1], exist[15]);
    }
    if (g == 2) {
        peace3[0] = createObject("3_25.png", scene[3], coor3[0][0], coor3[0][1], exist[0]);
        peace3[1] = createObject("3_24.png", scene[3], coor3[1][0], coor3[1][1], exist[1]);
        peace3[2] = createObject("3_23.png", scene[3], coor3[2][0], coor3[2][1], exist[2]);
        peace3[3] = createObject("3_22.png", scene[3], coor3[3][0], coor3[3][1], exist[3]);
        peace3[4] = createObject("3_21.png", scene[3], coor3[4][0], coor3[4][1], exist[4]);
        peace3[5] = createObject("3_20.png", scene[3], coor3[5][0], coor3[5][1], exist[5]);
        peace3[6] = createObject("3_19.png", scene[3], coor3[6][0], coor3[6][1], exist[6]);
        peace3[7] = createObject("3_18.png", scene[3], coor3[7][0], coor3[7][1], exist[7]);
        peace3[8] = createObject("3_17.png", scene[3], coor3[8][0], coor3[8][1], exist[8]);
        peace3[9] = createObject("3_16.png", scene[3], coor3[9][0], coor3[9][1], exist[9]);
        peace3[10] = createObject("3_15.png", scene[3], coor3[10][0], coor3[10][1], exist[10]);
        peace3[11] = createObject("3_14.png", scene[3], coor3[11][0], coor3[11][1], exist[11]);
        peace3[12] = createObject("3_13.png", scene[3], coor3[12][0], coor3[12][1], exist[12]);
        peace3[13] = createObject("3_12.png", scene[3], coor3[13][0], coor3[13][1], exist[13]);
        peace3[14] = createObject("3_11.png", scene[3], coor3[14][0], coor3[14][1], exist[14]);
        peace3[15] = createObject("3_10.png", scene[3], coor3[15][0], coor3[15][1], exist[15]);
        peace3[16] = createObject("3_09.png", scene[3], coor3[16][0], coor3[16][1], exist[16]);
        peace3[17] = createObject("3_08.png", scene[3], coor3[17][0], coor3[17][1], exist[17]);
        peace3[18] = createObject("3_07.png", scene[3], coor3[18][0], coor3[18][1], exist[18]);
        peace3[19] = createObject("3_06.png", scene[3], coor3[19][0], coor3[19][1], exist[19]);
        peace3[20] = createObject("3_05.png", scene[3], coor3[20][0], coor3[20][1], exist[20]);
        peace3[21] = createObject("3_04.png", scene[3], coor3[21][0], coor3[21][1], exist[21]);
        peace3[22] = createObject("3_03.png", scene[3], coor3[22][0], coor3[22][1], exist[22]);
        peace3[23] = createObject("3_02.png", scene[3], coor3[23][0], coor3[23][1], exist[23]);
        peace3[24] = createObject("3_01.png", scene[3], coor3[24][0], coor3[24][1], exist[24]);
    }
}

//재시작 함수
void restartI(int h) {
    if (h == 0) {
        playSound(BGM);
        coor2[0][0] = 850;
        coor2[0][1] = 240;
        coor2[1][0] = 700;
        coor2[1][1] = 240;
        coor2[2][0] = 550;
        coor2[2][1] = 240;
        coor2[3][0] = 850;
        coor2[3][1] = 390;
        coor2[4][0] = 700;
        coor2[4][1] = 390;
        coor2[5][0] = 550;
        coor2[5][1] = 390;
        coor2[6][0] = 850;
        coor2[6][1] = 540;
        coor2[7][0] = 700;
        coor2[7][1] = 540;
        coor2[8][0] = 550;
        coor2[8][1] = 540;
        for (int x = 0; x <= 8; x++) {
            locateObject(peace2[x], scene[2], coor2[x][0], coor2[x][1]);
        }
        setTimer(timer, 10000);
        time2 = 0;
    }
    if (h == 1) {
        playSound(BGM);
        coor[0][0] = 750;
        coor[0][1] = 20;
        coor[1][0] = 600;
        coor[1][1] = 20;
        coor[2][0] = 450;
        coor[2][1] = 20;
        coor[3][0] = 300;
        coor[3][1] = 20;
        coor[4][0] = 750;
        coor[4][1] = 170;
        coor[5][0] = 600;
        coor[5][1] = 170;
        coor[6][0] = 450;
        coor[6][1] = 170;
        coor[7][0] = 300;
        coor[7][1] = 170;
        coor[8][0] = 750;
        coor[8][1] = 320;
        coor[9][0] = 600;
        coor[9][1] = 320;
        coor[10][0] = 450;
        coor[10][1] = 320;
        coor[11][0] = 300;
        coor[11][1] = 320;
        coor[12][0] = 750;
        coor[12][1] = 470;
        coor[13][0] = 600;
        coor[13][1] = 470;
        coor[14][0] = 450;
        coor[14][1] = 470;
        coor[15][0] = 300;
        coor[15][1] = 470;
        for (int x = 0; x <= 15; x++) {
            locateObject(peace[x], scene[1], coor[x][0], coor[x][1]);
        }
        setTimer(timer, 10000);
        time2 = 0;
    }
    if (h == 2) {
        playSound(BGM);
        coor3[0][0] = 1080;
        coor3[0][1] = 80;
        coor3[1][0] = 960;
        coor3[1][1] = 80;
        coor3[2][0] = 840;
        coor3[2][1] = 80;
        coor3[3][0] = 720;
        coor3[3][1] = 80;
        coor3[4][0] = 600;
        coor3[4][1] = 80;
        coor3[5][0] = 1080;
        coor3[5][1] = 200;
        coor3[6][0] = 960;
        coor3[6][1] = 200;
        coor3[7][0] = 840;
        coor3[7][1] = 200;
        coor3[8][0] = 720;
        coor3[8][1] = 200;
        coor3[9][0] = 600;
        coor3[9][1] = 200;
        coor3[10][0] = 1080;
        coor3[10][1] = 320;
        coor3[11][0] = 960;
        coor3[11][1] = 320;
        coor3[12][0] = 840;
        coor3[12][1] = 320;
        coor3[13][0] = 720;
        coor3[13][1] = 320;
        coor3[14][0] = 600;
        coor3[14][1] = 320;
        coor3[15][0] = 1080;
        coor3[15][1] = 440;
        coor3[16][0] = 960;
        coor3[16][1] = 440;
        coor3[17][0] = 840;
        coor3[17][1] = 440;
        coor3[18][0] = 720;
        coor3[18][1] = 440;
        coor3[19][0] = 600;
        coor3[19][1] = 440;
        coor3[20][0] = 1080;
        coor3[20][1] = 560;
        coor3[21][0] = 960;
        coor3[21][1] = 560;
        coor3[22][0] = 840;
        coor3[22][1] = 560;
        coor3[23][0] = 720;
        coor3[23][1] = 560;
        coor3[24][0] = 600;
        coor3[24][1] = 560;
        for (int x = 0; x <= 24; x++) {
            locateObject(peace3[x], scene[3], coor3[x][0], coor3[x][1]);
        }
        setTimer(timer, 10000);
        time2 = 0;
    }
}

//1단계 종료 함수
void endGame1() {
    if (coor2[0][0] == 850 && coor2[0][1] == 240 && coor2[1][0] == 700 && coor2[1][1] == 240 && coor2[2][0] == 550 && coor2[2][1] == 240 && coor2[3][0] == 850 && coor2[3][1] == 390 && coor2[4][0] == 700 && coor2[4][1] == 390 && coor2[5][0] == 550 && coor2[5][1] == 390 && coor2[6][0] == 850 && coor2[6][1] == 540 && coor2[7][0] == 700 && coor2[7][1] == 540 && coor2[8][0] == 550 && coor2[8][1] == 540) {
        showObject(start[0]);
        enterScene(scene[0]);
        count[0]++;
        if (count[0] == 1) {
            showMessage(C1);
            setTimer(timer, 10000);
            time2 = 0;
        }
        else {
            showMessage(T);
            setTimer(timer, 10000);
            time2 = 0;
        }
        playSound(BGM);

    }
}

//2단계 종료 함수
void endGame2() {
    if (coor[0][0] == 750 && coor[0][1] == 20 && coor[1][0] == 600 && coor[1][1] == 20 && coor[2][0] == 450 && coor[2][1] == 20 && coor[3][0] == 300 && coor[3][1] == 20 && coor[4][0] == 750 && coor[4][1] == 170 && coor[5][0] == 600 && coor[5][1] == 170 && coor[6][0] == 450 && coor[6][1] == 170 && coor[7][0] == 300 && coor[7][1] == 170 && coor[8][0] == 750 && coor[8][1] == 320 && coor[9][0] == 600 && coor[9][1] == 320 && coor[10][0] == 450 && coor[10][1] == 320 && coor[11][0] == 300 && coor[11][1] == 320 && coor[12][0] == 750 && coor[12][1] == 470 && coor[13][0] == 600 && coor[13][1] == 470 && coor[14][0] == 450 && coor[14][1] == 470 && coor[15][0] == 300 && coor[15][1] == 470) {
        showObject(start[2]);
        enterScene(scene[0]);
        count[1]++;
        if (count[1] == 1) {
            showMessage(C2);
            setTimer(timer, 10000);
            time2 = 0;
        }
        else {
            showMessage(T);
            setTimer(timer, 10000);
            time2 = 0;
        }
        playSound(BGM);
    }
}

//3단계 종료 함수
void endGame3() {
    if (coor3[0][0] == 1080 && coor3[0][1] == 80 && coor3[1][0] == 960 && coor3[1][1] == 80 && coor3[2][0] == 840 && coor3[2][1] == 80 && coor3[3][0] == 720 && coor3[3][1] == 80 && coor3[4][0] == 600 && coor3[4][1] == 80 && coor3[5][0] == 1080 && coor3[5][1] == 200 && coor3[6][0] == 960 && coor3[6][1] == 200 && coor3[7][0] == 840 && coor3[7][1] == 200 && coor3[8][0] == 720 && coor3[8][1] == 200 && coor3[9][0] == 600 && coor3[9][1] == 200 && coor3[10][0] == 1080 && coor3[10][1] == 320 && coor3[11][0] == 960 && coor3[11][1] == 320 && coor3[12][0] == 840 && coor3[12][1] == 320 && coor3[13][0] == 720 && coor3[13][1] == 320 && coor3[14][0] == 600 && coor3[14][1] == 320 && coor3[15][0] == 1080 && coor3[15][1] == 440 && coor3[16][0] == 960 && coor3[16][1] == 440 && coor3[17][0] == 840 && coor3[17][1] == 440 && coor3[18][0] == 720 && coor3[18][1] == 440 && coor3[19][0] == 600 && coor3[19][1] == 440 && coor3[20][0] == 1080 && coor3[20][1] == 560 && coor3[21][0] == 960 && coor3[21][1] == 560 && coor3[22][0] == 840 && coor3[22][1] == 560 && coor3[23][0] == 720 && coor3[23][1] == 560 && coor3[24][0] == 600 && coor3[24][1] == 560) {
        enterScene(scene[0]);
        count[2]++;
        if (count[2] == 1) {
            showMessage(C3);
            setTimer(timer, 10000);
            time2 = 0;
        }
        else {
            showMessage(T);
            setTimer(timer, 10000);
            time2 = 0;
        }
        playSound(BGM);
    }
}

//1단계 조각 이동 함수
void movepeace2(int j) {
    if ((coor2[j][0] - 150 == coor2[0][0] && coor2[j][1] == coor2[0][1]) || (coor2[j][0] + 150 == coor2[0][0] && coor2[j][1] == coor2[0][1]) || (coor2[j][0] == coor2[0][0] && coor2[j][1] - 150 == coor2[0][1]) || (coor2[j][0] == coor2[0][0] && coor2[j][1] + 150 == coor2[0][1])) {
        int bridge_X = coor2[0][0];
        coor2[0][0] = coor2[j][0];
        coor2[j][0] = bridge_X;
        int bridge_Y = coor2[0][1];
        coor2[0][1] = coor2[j][1];
        coor2[j][1] = bridge_Y;
        locateObject(peace2[j], scene[2], coor2[j][0], coor2[j][1]);
        locateObject(peace2[0], scene[2], coor2[0][0], coor2[0][1]);
    }
}

//2단계 조각 이동 함수
void movepeace(int j) {
    if ((coor[j][0] - 150 == coor[0][0] && coor[j][1] == coor[0][1]) || (coor[j][0] + 150 == coor[0][0] && coor[j][1] == coor[0][1]) || (coor[j][0] == coor[0][0] && coor[j][1] - 150 == coor[0][1]) || (coor[j][0] == coor[0][0] && coor[j][1] + 150 == coor[0][1])) {
        int bridge_X = coor[0][0];
        coor[0][0] = coor[j][0];
        coor[j][0] = bridge_X;
        int bridge_Y = coor[0][1];
        coor[0][1] = coor[j][1];
        coor[j][1] = bridge_Y;
        locateObject(peace[j], scene[1], coor[j][0], coor[j][1]);
        locateObject(peace[0], scene[1], coor[0][0], coor[0][1]);
    }
}

//3단계 조각 이동 함수
void movepeace3(int j) {
    if ((coor3[j][0] - 120 == coor3[0][0] && coor3[j][1] == coor3[0][1]) || (coor3[j][0] + 120 == coor3[0][0] && coor3[j][1] == coor3[0][1]) || (coor3[j][0] == coor3[0][0] && coor3[j][1] - 120 == coor3[0][1]) || (coor3[j][0] == coor3[0][0] && coor3[j][1] + 120 == coor3[0][1])) {
        int bridge_X = coor3[0][0];
        coor3[0][0] = coor3[j][0];
        coor3[j][0] = bridge_X;
        int bridge_Y = coor3[0][1];
        coor3[0][1] = coor3[j][1];
        coor3[j][1] = bridge_Y;
        locateObject(peace3[j], scene[3], coor3[j][0], coor3[j][1]);
        locateObject(peace3[0], scene[3], coor3[0][0], coor3[0][1]);
    }
}

//게임 종료시 메세지 함수
void endMessage() {
    sprintf(C1, "총 %d초가 걸렸습니다!\n 2단계가 열렸습니다!", time2);
    sprintf(C2, "총 %d초가 걸렸습니다!\n 3단계가 열렸습니다!", time2);
    sprintf(C3, "총 %d초가 걸렸습니다!\n 축하합니다 모두 클리어 하셨습니다!", time2);
    sprintf(T, "총 %d초가 걸렸습니다!", time2);
}

//마우스 콜백 함수
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

    //2단계 시작
    if (object == start[0]) {
        enterScene(scene[1]);
        gamestartI(1);
    }

    //1단계 시작
    if (object == start[1]) {
        enterScene(scene[2]);
        gamestartI(0);
    }

    //3단계 시작
    if (object == start[2]) {
        enterScene(scene[3]);
        gamestartI(2);
    }

    //3단계 퍼즐
    if (object == peace3[1]) {
        movepeace3(1);
        endGame3();
    }
    if (object == peace3[2]) {
        movepeace3(2);
        endGame3();
    }
    if (object == peace3[3]) {
        movepeace3(3);
        endGame3();
    }
    if (object == peace3[4]) {
        movepeace3(4);
        endGame3();
    }
    if (object == peace3[5]) {
        movepeace3(5);
        endGame3();
    }
    if (object == peace3[6]) {
        movepeace3(6);
        endGame3();
    }
    if (object == peace3[7]) {
        movepeace3(7);
        endGame3();
    }
    if (object == peace3[8]) {
        movepeace3(8);
        endGame3();
    }
    if (object == peace3[9]) {
        movepeace3(9);
        endGame3();
    }
    if (object == peace3[10]) {
        movepeace3(10);
        endGame3();
    }
    if (object == peace3[11]) {
        movepeace3(11);
        endGame3();
    }
    if (object == peace3[12]) {
        movepeace3(12);
        endGame3();
    }
    if (object == peace3[13]) {
        movepeace3(13);
        endGame3();
    }
    if (object == peace3[14]) {
        movepeace3(14);
        endGame3();
    }
    if (object == peace3[15]) {
        movepeace3(15);
        endGame3();
    }
    if (object == peace3[16]) {
        movepeace3(16);
        endGame3();
    }
    if (object == peace3[17]) {
        movepeace3(17);
        endGame3();
    }
    if (object == peace3[18]) {
        movepeace3(18);
        endGame3();
    }
    if (object == peace3[19]) {
        movepeace3(19);
        endGame3();
    }
    if (object == peace3[20]) {
        movepeace3(20);
        endGame3();
    }
    if (object == peace3[21]) {
        movepeace3(21);
        endGame3();
    }
    if (object == peace3[22]) {
        movepeace3(22);
        endGame3();
    }
    if (object == peace3[23]) {
        movepeace3(23);
        endGame3();
    }
    if (object == peace3[24]) {
        movepeace3(24);
        endGame3();
    }

    //2단계 퍼즐
    if (object == peace[1]) {
        movepeace(1);
        endGame2();
    }
    if (object == peace[2]) {
        movepeace(2);
        endGame2();
    }
    if (object == peace[3]) {
        movepeace(3);
        endGame2();
    }
    if (object == peace[4]) {
        movepeace(4);
        endGame2();
    }
    if (object == peace[5]) {
        movepeace(5);
        endGame2();
    }
    if (object == peace[6]) {
        movepeace(6);
        endGame2();
    }
    if (object == peace[7]) {
        movepeace(7);
        endGame2();
    }
    if (object == peace[8]) {
        movepeace(8);
        endGame2();
    }
    if (object == peace[9]) {
        movepeace(9);
        endGame2();
    }
    if (object == peace[10]) {
        movepeace(10);
        endGame2();
    }
    if (object == peace[11]) {
        movepeace(11);
        endGame2();
    }
    if (object == peace[12]) {
        movepeace(12);
        endGame2();
    }
    if (object == peace[13]) {
        movepeace(13);
        endGame2();
    }
    if (object == peace[14]) {
        movepeace(14);
        endGame2();
    }
    if (object == peace[15]) {
        movepeace(15);
        endGame2();
    }

    //재시작 버튼
    if (object == restart[0]) {
        enterScene(scene[0]);
        restartI(1);
    }
    if (object == restart[1]) {
        enterScene(scene[0]);
        restartI(0);
    }
    if (object == restart[2]) {
        enterScene(scene[0]);
        restartI(2);
    }

    //1단계 퍼즐
    if (object == peace2[1]) {
        movepeace2(1);
        endGame1();
    }
    if (object == peace2[2]) {
        movepeace2(2);
        endGame1();
    }
    if (object == peace2[3]) {
        movepeace2(3);
        endGame1();
    }
    if (object == peace2[4]) {
        movepeace2(4);
        endGame1();
    }
    if (object == peace2[5]) {
        movepeace2(5);
        endGame1();
    }
    if (object == peace2[6]) {
        movepeace2(6);
        endGame1();
    }
    if (object == peace2[7]) {
        movepeace2(7);
        endGame1();
    }
    if (object == peace2[8]) {
        movepeace2(8);
        endGame1();
    }
}

//타이머 콜백 함수
void timerCallback(TimerID timer) {
    time2++;
    endMessage();
    setTimer(timer, 1);
    startTimer(timer);
}

//메인 함수
int main() {

    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setMouseCallback(mouseCallback);
    setTimerCallback(timerCallback);



    //장면 생성
    scene[0] = createScene("Hero puzzle", "background3.jpg");
    scene[1] = createScene("2-STAGE(4X4)", "2-STAGE.png");
    scene[2] = createScene("1-STAGE(3X3)", "1-STAGE.jpg");
    scene[3] = createScene("FINAL-STAGE(5x5)", "FINAL-STAGE.png");

    //타이머
    timer = createTimer2(1);

    //스타트 버튼 생성
    start[0] = createObject("play2.png", scene[0], 500, 50, false);
    start[1] = createObject("play2.png", scene[0], 200, 50, true);
    start[2] = createObject("play2.png", scene[0], 800, 50, false);
    for (int i = 0; i <= 24; i++) {
        exist[i] = true;
    }
    exist[0] = false;
    for (int k = 0; k <= 2; k++) {
        scaleObject(start[k], 0.1f);
    }

    //퍼즐조각생성
    createpuzzle(0);
    createpuzzle(1);
    createpuzzle(2);

    //재시작 버튼 생성
    restart[0] = createObject("restart.png", scene[1], 10, 10, true);
    restart[1] = createObject("restart.png", scene[2], 10, 10, true);
    restart[2] = createObject("restart.png", scene[3], 10, 10, true);
    for (int k = 0; k <= 2; k++) {
        scaleObject(restart[k], 0.1f);
    }

    //음악재생
    BGM = createSound2("avengers.mp3", true);

    showMessage("한 단계를 클리어 하시면 다음 단계가 등장합니다!");
    startGame(scene[0]);
}