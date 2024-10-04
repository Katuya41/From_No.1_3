#include "pch.h"

//--------------------------------------------------------------------------------
// �t�@�C���ˑ��֌W
//--------------------------------------------------------------------------------
// GoogleTest�̃w�b�_�B�E�B�U�[�h�ɂĕʂ̃t�@�C���ɋL�q����Ă���ꍇ�́A�s�v�ł��B
#include <gtest/gtest.h>

// ��B�����̃v���W�F�N�g�ɂ������w�b�_�t�@�C����include���Ă��������B
#include "LinkedList.h"

#include "TestManual.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// �R���p�C���֘A�蓮�e�X�g
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-8(�蓮)\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
						TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const LinkedList list;
			EXPECT_EQ(0, list.GetDataNum());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-34(�蓮)\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
						TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetFrontConstIterateWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const LinkedList list;
			EXPECT_EQ(true, list.GetConstBeginBool());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}



		/**********************************************************************************//**
			@brief		���X�g�擪�f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
			@details	ID:���X�g-15(�蓮)\n
						���X�g�擪�f�[�^�ǉ��e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

			@return		�Ȃ�
		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* it = new LinkedList::ConstIterator();
			it = list.GetConstBegin();
			list.Insert(it, 1);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		���X�g�擪�̃f�[�^�폜�ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
			@details	ID:���X�g-22(�蓮)\n
						���X�g�擪�f�[�^�ǉ��e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

			@return		�Ȃ�
		*//***********************************************************************************/
		TEST(ListManualTest, TestDeleteWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* it = new LinkedList::ConstIterator();
			it = list.GetConstBegin();
			list.Delete(it);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ����̃e�X�g
			@details	ID:���X�g-40(�蓮)\n
						���X�g�擪�f�[�^�ǉ��e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

			@return		�Ȃ�
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = list.GetBegin();//�G���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ����̃e�X�g
			@details	ID:Iterator-17(�蓮)\n
						ConstIterator����AIterator�̃R�s�[���쐬����Ȃ����̃e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

			@return		�Ȃ�
		*//***********************************************************************************/
		TEST(ListManualTest, TestCopyWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			LinkedList::ConstIterator* Constit = new LinkedList::ConstIterator();
			LinkedList::Iterator* it = new LinkedList::Iterator();
			Constit->CopyConst(it);	//�G���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		Iterator��ConstIterator�����ł��Ȃ����̃e�X�g
			@details	ID:Iterator-19(�蓮)\n
						Iterator��ConstIterator�����ł��Ȃ����̃e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
						TT_TEST_PUSH_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n

			@return		�Ȃ�
		*//***********************************************************************************/
		TEST(ListManualTest, TestSetWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const LinkedList list;
			const LinkedList::ConstIterator* Constit = new LinkedList::ConstIterator();
			LinkedList::Iterator* it = new LinkedList::Iterator();
			it = Constit;	//�G���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}


	}	// chapter2
}	//	ex01_DataStructure
