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

    // �ǂݍ��ރt�@�C���̖��O
	std::ifstream file("Scores.txt"); 
	if (!file.is_open()) {
        //�J���Ȃ������ꍇ
		printf("�t�@�C�����J���܂���ł���");
		return 0;
	}

    //�󂯎�����X�R�A�Ɩ��O�����Ă����ϐ�
    DATA Data;

    while (file >> Data.Score >> Data.Name) {
        // ���O�ƃX�R�A��\��(�m�F�p)
        //printf("�X�R�A: %s ,���O: %s \n", Score, Name);
        //���X�g�̈�Ԗ����ɓ����
        List.InsertLast(Data);
    }

    //���X�g�̒��g���ŏ����疖���܂ŕ\��
    //Display(List);
    LinkedList<DATA>::Iterator it;
    it = List.GetBegin();
    while (!it.CheckDammy()) {
        printf("�X�R�A: %s ,���O: %s \n", (*it).Score.c_str(), (*it).Name.c_str());
        it++;
        //++it;
    }

    file.close();

	return 0;
}