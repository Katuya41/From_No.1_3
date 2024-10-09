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
    std::string Res,Name;
    LinkedList<DATA>::Iterator it;

    while (file >> Res >> Name) {
        // ���O�ƃX�R�A��\��(�m�F�p)
        //printf("�X�R�A: %s ,���O: %s \n", Score, Name);
        //���X�g�̈�Ԗ����ɓ����
        DATA Data = { std::stoi(Res),Name};
        it = List.GetEnd();
        //Data.Score = std::stoi(Res);
        List.Insert(it, Data);
    }

    //���X�g�̒��g���ŏ����疖���܂ŕ\��
    //Display(List);
    //it = List.GetBegin();
    //for (it == List.GetBegin(); it != List.GetEnd(); it++)
    //{
    //    printf("�X�R�A: %d ,���O: %s \n", (*it).Score, (*it).Name.c_str());
    //}

    for (DATA Data: List)
    {
        printf("�X�R�A: %d ,���O: %s \n", Data.Score, Data.Name.c_str());
    }

    file.close();

	return 0;
}