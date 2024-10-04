#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(void)
{
    LinkedList<DATA> List;

    // 読み込むファイルの名前
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //開かなかった場合
		printf("ファイルが開けませんでした");
		return 0;
	}

    //受け取ったスコアと名前を入れておく変数
    DATA Data;

    while (file >> Data.Score >> Data.Name) {
        // 名前とスコアを表示(確認用)
        //printf("スコア: %s ,名前: %s \n", Score, Name);
        //リストの一番末尾に入れる
        List.InsertLast(Data);
    }

    //リストの中身を最初から末尾まで表示
    //Display(List);
    LinkedList<DATA>::Iterator it;
    it = List.GetBegin();
    while (!it.CheckDammy()) {
        printf("スコア: %s ,名前: %s \n", (*it).Score.c_str(), (*it).Name.c_str());
        it++;
        //++it;
    }

    file.close();

	return 0;
}