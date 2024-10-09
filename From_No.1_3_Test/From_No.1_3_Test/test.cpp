#include "pch.h"

// GoogleTest�̃w�b�_�B�E�B�U�[�h�ɂĕʂ̃t�@�C���ɋL�q����Ă���ꍇ�́A�s�v�ł��B
//#include <gtest/gtest.h>

// ��B�����̃v���W�F�N�g�ɂ������w�b�_�t�@�C����include���Ă��������B
#include "LinkedList.h"

//#include "test.h"

//�����e�X�g�R�[�h
namespace ex01_DataStructure
{
	namespace chapter2
	{

		//=================================== �f�[�^���̎擾 ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����0�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
			LinkedList<int> list;
			EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^����1�����Ă���ΐ����ł��B\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.GetBegin();
			list.Insert(it, 1);
			EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		{
			// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
// 			LinkedList<DATA> list;
// 			LinkedList<DATA>::Iterator it = list.GetEnd();
// 			ASSERT_FALSE(list.Insert(it, 1));
// 			EXPECT_EQ(0, list.GetCount());
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̖߂�l
			@details	ID:���X�g-3\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsertList)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̑}�����s�����ۂ̖߂�l
			@details	ID:���X�g-4\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̑}�����s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumInsertListFailed)
		{
			//LinkedList<DATA> list;
			//LinkedList<DATA>::Iterator* Testit;
			//list.Insert(Testit);
			//EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̖߂�l
			@details	ID:���X�g-5\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteList)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator Testit = list.GetBegin();
			list.Insert(Testit, {1, "Test"});
			Testit = list.GetBegin();
			list.Delete(Testit);
			EXPECT_EQ(0, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜���s�����ۂ̖߂�l
			@details	ID:���X�g-6\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteListFailed)
		{
			//LinkedList<DATA> list;
			//LinkedList<DATA>::Iterator* Testit;
			//Testit = new LinkedList<DATA>::Iterator();
			//list.Insert(Testit);
			//delete Testit;
			//list.Delete(Testit);
			//EXPECT_EQ(1, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g����̎��Ƀf�[�^�̍폜���s�����ۂ̖߂�l
			@details	ID:���X�g-7\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂��B\n
						�f�[�^���������Ă��Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumDeleteListWhenEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator Testit;
			list.Delete(Testit);
			EXPECT_EQ(0, list.GetDataNum());
		}

		//=================================== �f�[�^�̑}�� ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�ɁA�f�[�^��ǉ������ۂ̋����e�X�g
			@details	ID:���X�g-9\n
						���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						���X�g����ł���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����}������Ă���ꍇ�ɁA�擪�Ƀf�[�^��ǉ������ۂ̋����e�X�g
			@details	ID:���X�g-10\n
						�f�[�^�}���ǉ��e�X�g�ł��B\n
						���X�g�ɕ����}������Ă���ꍇ�ɐ擪�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToListFront)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(it, list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����}������Ă���ꍇ�ɁA�����Ƀf�[�^��ǉ������ۂ̋����e�X�g
			@details	ID:���X�g-11\n
						�f�[�^�}���ǉ��e�X�g�ł��B\n
						���X�g�ɕ����}������Ă���ꍇ�ɖ����ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToListWhenEnd)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			list.Insert(it, {30, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����}������Ă���ꍇ�ɁA�f�[�^��ǉ������ۂ̋����e�X�g
			@details	ID:���X�g-12\n
						�f�[�^�}���ǉ��e�X�g�ł��B\n
						���X�g�ɕ����}������Ă���ꍇ�ɒǉ������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToList)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			list.Insert(it, {30, "Test"});
			EXPECT_EQ(3, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		constiterator���w�肵�đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-13\n
						�f�[�^�}���ǉ��e�X�g�ł��B\n
						constiterator���w�肵�đ}�������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushToConstIterator)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			it = list.GetBegin();
			EXPECT_EQ(true, list.Insert(it, {10, "Test"}));
			it = list.GetEnd();
			EXPECT_EQ(true, list.Insert(it, {20, "Test"}));
			EXPECT_EQ(true, list.Insert(it, {30, "Test"}));
		}

		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^��n���đ}�������ۂ̋����e�X�g
			@details	ID:���X�g-14\n
						�f�[�^�}���ǉ��e�X�g�ł��B\n
						�s���ȃC�e���[�^��n���đ}�������ۂ̋������m�F���Ă��܂��B\n
						�v�f���ǉ�����Ă��Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(PushBackTest, TestPushTofraudIterator)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			EXPECT_EQ(false, list.Insert(it, {10, "Test"}));
		}

		/**********************************************************************************//**
			@brief		���X�g����̏ꍇ�ɍ폜�����ۂ̋����e�X�g
			@details	ID:���X�g-16\n
						�f�[�^�폜�e�X�g�ł��B\n
						���X�g����̏ꍇ�ɍ폜�����ۂ̋������m�F���Ă��܂��B\n
						�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			EXPECT_EQ(false, list.Delete(it));
			//EXPECT_EQ(false, list.GetDataNum());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����i�[����Ă����ԂŐ擪�C�e���[�^��n���č폜�����ۂ̋����e�X�g
			@details	ID:���X�g-17\n
						�f�[�^�폜�e�X�g�ł��B\n
						���X�g�ɕ����i�[����Ă����ԂŐ擪�C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
						�폜�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToListWhenFront)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����i�[����Ă����ԂŖ����C�e���[�^��n���č폜�����ۂ̋����e�X�g
			@details	ID:���X�g-18\n
						�f�[�^�폜�e�X�g�ł��B\n
						���X�g�ɕ����i�[����Ă����ԂŖ����C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
						�폜�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToListWhenEnd)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(true, list.Delete(--it));
		}

		/**********************************************************************************//**
			@brief		���X�g�ɕ����i�[����Ă����ԂŐ擪�����ȊO�̃C�e���[�^��n���č폜�����ۂ̋����e�X�g
			@details	ID:���X�g-19\n
						�f�[�^�폜�e�X�g�ł��B\n
						���X�g�ɕ����i�[����Ă����ԂŐ擪�����ȊO�C�e���[�^��n���č폜�����ۂ̋������m�F���Ă��܂��B\n
						�폜�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToList)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			list.Insert(it, {30, "Test"});
			list.Insert(it, {40, "Test"});
			it = list.GetBegin();
			it++;
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		constiterator���w�肵�č폜�����ۂ̋����e�X�g
			@details	ID:���X�g-20\n
						�f�[�^�폜�e�X�g�ł��B\n
						constiterator���w�肵�č폜�����ۂ̋������m�F���Ă��܂��B\n
						�폜�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteToConstIterator)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(true, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		�s���ȃC�e���[�^���w�肵�č폜�����ۂ̋����e�X�g
			@details	ID:���X�g-21\n
						�f�[�^�폜�e�X�g�ł��B\n
						�s���ȃC�e���[�^���w�肵�č폜�����ۂ̋������m�F���Ă��܂��B\n
						�폜�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DeleteBackTest, TestDeleteTofraudIterator)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			EXPECT_EQ(false, list.Delete(it));
		}

		/**********************************************************************************//**
			@brief		���X�g����̏ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-23\n
						�擪�C�e���[�^�e�X�g�ł��B\n
						���X�g����̏ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�_�~�[�m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			EXPECT_EQ(true, list.GetBegin() == list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-24\n
						�擪�C�e���[�^�e�X�g�ł��B\n
						���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�擪�v�f���w���m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhen1Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(it, list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-25\n
						�擪�C�e���[�^�e�X�g�ł��B\n
						���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�擪�v�f���w���m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhen2Date)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(it, list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɑ}��������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-26\n
						�擪�C�e���[�^�e�X�g�ł��B\n
						���X�g�ɑ}��������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�_�~�[�m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhenInsertBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			EXPECT_EQ(it, list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g���폜������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-27\n
						�擪�C�e���[�^�e�X�g�ł��B\n
						���X�g���폜������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontIteratorTest, TestIteratorCheckToListWhenDeleteBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			list.Delete(it);
			it = list.GetBegin();
			EXPECT_EQ(it, list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g����̏ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-29\n
						�擪�R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g����̏ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�_�~�[�m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit;
			Constit = list.GetConstBegin();
			EXPECT_EQ(true, Constit == list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-30\n
						�擪�R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhen1Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			Constit = list.GetConstBegin();
			EXPECT_EQ(Constit, list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-31\n
						�擪�R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhen2Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			list.Insert(Constit, {20, "Test"});
			Constit = list.GetConstBegin();
			EXPECT_EQ(Constit, list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɑ}��������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-32\n
						�擪�R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g�ɑ}��������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhenIsertBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			list.Insert(Constit, {20, "Test"});
			Constit = list.GetConstBegin();
			EXPECT_EQ(Constit, list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g���폜������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-33\n
						�擪�R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g���폜������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(FrontConstIteratorTest, TestConstIteratorCheckToListWhenDeleteBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			list.Insert(Constit, {20, "Test"});
			it = list.GetBegin();
			list.Delete(it);
			Constit = list.GetConstBegin();
			EXPECT_EQ(Constit, list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g����̏ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-35\n
						�����C�e���[�^�e�X�g�ł��B\n
						���X�g����̏ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it;
			it = list.GetEnd();
			EXPECT_EQ(true, it == list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-36\n
						�����C�e���[�^�e�X�g�ł��B\n
						���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhen1Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-37\n
						�����C�e���[�^�e�X�g�ł��B\n
						���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhen2Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɑ}��������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-38\n
						�����C�e���[�^�e�X�g�ł��B\n
						���X�g�ɑ}��������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhenInsertBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g���폜������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-39\n
						�����C�e���[�^�e�X�g�ł��B\n
						���X�g���폜������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestEndIteratorCheckToListWhenDeleteBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			list.Delete(it);
			it = list.GetEnd();
			EXPECT_EQ(it, list.GetEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g����̏ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-41\n
						�����R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g����̏ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�_�~�[�m�[�h�擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToEmpty)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit;
			Constit = list.GetConstEnd();
			EXPECT_EQ(true, Constit == list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-42\n
						�����R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g��1�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhen1Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			Constit = list.GetConstEnd();
			EXPECT_EQ(Constit, list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-43\n
						�����R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g��2�}������Ă���ꍇ�ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhen2Data)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::ConstIterator Constit = list.GetBegin();
			list.Insert(Constit, {10, "Test"});
			list.Insert(Constit, {20, "Test"});
			Constit = list.GetConstEnd();
			EXPECT_EQ(Constit, list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɑ}��������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-44\n
						�����R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g�ɑ}��������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�v�f���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhenInsertBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			LinkedList<DATA>::ConstIterator Constit = list.GetConstEnd();
			EXPECT_EQ(Constit, list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g���폜������ɌĂяo�����ۂ̋����e�X�g
			@details	ID:���X�g-45\n
						�����R���X�g�C�e���[�^�e�X�g�ł��B\n
						���X�g���폜������ɌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						�_�~�[�m�[�h���擾�ł���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestEndConstIteratorCheckToListWhenDeleteBack)
		{
			LinkedList<DATA> list;
			LinkedList<DATA>::Iterator it = list.GetBegin();
			list.Insert(it, {10, "Test"});
			list.Insert(it, {20, "Test"});
			it = list.GetBegin();
			list.Delete(it);
			LinkedList<DATA>::ConstIterator Constit = list.GetConstEnd();
			EXPECT_EQ(Constit, list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-0\n
						�C�e���[�^�̂����v�f���擾����e�X�g�ł��B\n
						���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmpty)
		{
			LinkedList<DATA>::Iterator it;
			// ����ASSERT_EQ�͈Ӑ}�I�Ɏ��s���܂��B
			//ASSERT_EQ((*it), nullptr) << "This assertion is expected to fail";
			//(*it);
			EXPECT_DEATH(*it, "Iterator points to null!");
		}

		/**********************************************************************************//**
			@brief		�C�e���[�^����擾�����l�����ł��邩�̋����e�X�g
			@details	ID:Iterator-1\n
						�C�e���[�^�̂����v�f���擾����e�X�g�ł��B\n
						�C�e���[�^����擾�����l�����ł��邩�̋������m�F���Ă��܂��B\n
						�l���ύX����Ă���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenDifferentData)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {1, "Test1"});
			List.Insert(it, {2, "Test2"});
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetEnd();
			it2--;
			it2 = it;
			std::string Res = "Test2";
			EXPECT_EQ(2, (*it2).Score);
			EXPECT_EQ(Res, (*it2).Name);
		}

		/**********************************************************************************//**
			@brief		���X�g����̍ۂ̐擪�C�e���[�^���Ăяo�����ۂ̋����e�X�g
			@details	ID:Iterator-3\n
						�C�e���[�^�̂����v�f���擾����e�X�g�ł��B\n
						���X�g����̍ۂ̐擪�C�e���[�^���Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmptyToFrontIterator)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetBegin();
			//ASSERT_EQ((*it), nullptr) << "This assertion is expected to fail";
			//(*it);
			EXPECT_DEATH((*it), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		�����C�e���[�^���Ăяo�����ۂ̋����e�X�g
			@details	ID:Iterator-4\n
						�C�e���[�^�̂����v�f���擾����e�X�g�ł��B\n
						���X�g����̍ۂ̐擪�C�e���[�^���Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(IteratorDataTest, TestCheckIteratorDataWhenEmptyToEndIterator)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetEnd();
			//ASSERT_EQ((*it), nullptr) << "This assertion is expected to fail";
			//ASSERT_TRUE(it.GetNodeDataBool());
			EXPECT_DEATH((*it), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-5\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenNotList)
		{
			LinkedList<DATA>::Iterator it;
			///it++;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it++), "Iterator points to null!");
		}

		/**********************************************************************************//**
			@brief		���X�g����̏�ԂŐ擪�C�e���[�^�ɑ΂����ۂ̋����e�X�g
			@details	ID:Iterator-6\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŐ擪�C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenEmptyToFront)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetBegin();
			//it++;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it++), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		���X�g���^�̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋����e�X�g
			@details	ID:Iterator-7\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenEmptyToEnd)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetEnd();
			//it++;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it++), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�̗v�f�������Ԃő΂����ۂ̋����e�X�g
			@details	ID:Iterator-8\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListTo2Data)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetBegin();
			it++;
			std::string Res = "Test1";
			EXPECT_EQ(10, (*it).Score);
			EXPECT_EQ(Res, (*it).Name);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋����e�X�g
			@details	ID:Iterator-9\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						�O�u�C���N�������g���s�����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListFront)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetBegin();
			//++it;
			DATA TestData;
			TestData = (*(++it));
			EXPECT_EQ(10, TestData.Score);
			EXPECT_EQ("Test1", TestData.Name);
			EXPECT_EQ(10, (*it).Score);
			EXPECT_EQ("Test1", (*it).Name);
		}

		/**********************************************************************************//**
			@brief		��u�C���N�������g���s�����ۂ̋����e�X�g
			@details	ID:Iterator-10\n
						�C�e���[�^�����X�g�̖����Ɍ������Đi�߂�e�X�g�ł��B\n
						��u�C���N�������g���s�����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(AddIteratorTest, TestAddIteratorWhenListEnd)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetBegin();
			DATA TestData;
			TestData = (*(it++));
			EXPECT_EQ(20, TestData.Score);
			EXPECT_EQ("Test2", TestData.Name);
			EXPECT_EQ(10, (*it).Score);
			EXPECT_EQ("Test1", (*it).Name);
		}

		/**********************************************************************************//**
			@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋����e�X�g
			@details	ID:Iterator-11\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenNotList)
		{
			LinkedList<DATA>::Iterator it;
			//it--;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it--), "Iterator points to null!");
		}

		/**********************************************************************************//**
			@brief		���X�g����̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋����e�X�g
			@details	ID:Iterator-12\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŐ擪�C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenEmptyFront)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetBegin();
			//it--;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it--), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		���X�g����̏�ԂŐ擪�C�e���[�^�ɑ΂����ۂ̋����e�X�g
			@details	ID:Iterator-13\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						Assert����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListToFront)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			it = List.GetEnd();
			//it--;
			//ASSERT_EQ(true, it.IsDummy()) << "This assertion is expected to fail";
			EXPECT_DEATH((it--), "Iterator points to Dummy!");
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ�̗v�f�������Ԃő΂����ۂ̋����e�X�g
			@details	ID:Iterator-14\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Đi�߂�e�X�g�ł��B\n
						���X�g���^�̏�ԂŖ����C�e���[�^�ɑ΂����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListTo2Data)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetEnd();
			it--;
			it--;
			std::string Res = "Test2";
			EXPECT_EQ(20, (*it).Score);
			EXPECT_EQ(Res, (*it).Name);
		}

		/**********************************************************************************//**
			@brief		�O�u�C���N�������g���s�����ۂ̋����e�X�g
			@details	ID:Iterator-15\n
						�C�e���[�^�����X�g�̐擪�������Đi�߂�e�X�g�ł��B\n
						�O�u�C���N�������g���s�����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListFront)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetEnd();
			it--;
			DATA TestData;
			TestData = (*(--it));
			EXPECT_EQ(20, TestData.Score);
			EXPECT_EQ("Test2", TestData.Name);
			EXPECT_EQ(20, (*it).Score);
			EXPECT_EQ("Test2", (*it).Name);
		}

		/**********************************************************************************//**
			@brief		��u�C���N�������g���s�����ۂ̋����e�X�g
			@details	ID:Iterator-16\n
						�C�e���[�^�����X�g�̐擪�Ɍ������Đi�߂�e�X�g�ł��B\n
						��u�C���N�������g���s�����ۂ̋������m�F���Ă��܂��B\n
						�w�肳�ꂽ�������i�[����Ă����\n
		*//***********************************************************************************/
		TEST(SumIteratorTest, TestSumIteratorWhenListEnd)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test1"});
			List.Insert(it, {20, "Test2"});
			it = List.GetEnd();
			it--;
			DATA TestData;
			TestData = (*(it--));
			EXPECT_EQ(10, TestData.Score);
			EXPECT_EQ("Test1", TestData.Name);
			EXPECT_EQ(20, (*it).Score);
			EXPECT_EQ("Test2", (*it).Name);
		}

		/**********************************************************************************//**
			@brief		�R�s�[�R���X�g���N�^���s�����ۂ̋����e�X�g
			@details	ID:Iterator-18\n
						�C�e���[�^�̃R�s�[���s���e�X�g�ł��B\n
						�R�s�[�R���X�g���N�^���s�����ۂ̋������m�F���Ă��܂��B\n
						�R�s�[���̒l�Ɠ�������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(CopyTest, TestCopy)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test"});
			LinkedList<DATA>::ConstIterator constit;
			constit = List.GetConstBegin();
			LinkedList<DATA>::ConstIterator constit2(constit);
			int num = (*constit2).Score;
			EXPECT_EQ(10, num);
		}

		/**********************************************************************************//**
			@brief		������s�����ۂ̋����e�X�g
			@details	ID:Iterator-20\n
						�C�e���[�^�̑�����s���e�X�g�ł��B\n
						������s�����ۂ̋������m�F���Ă��܂��B\n
						������̒l�Ɠ�������ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(AssignmentTest, TestAssignment)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::ConstIterator Constit = List.GetConstBegin();
			List.Insert(Constit, {10, "Test1"});
			List.Insert(Constit, {20, "Test2"});
			Constit = List.GetConstBegin();
			LinkedList<DATA>::Iterator it2;
			it2 = List.GetEnd();
			it2--;
			std::string Res = "Test1";
			EXPECT_EQ(10, (*it2).Score);
			EXPECT_EQ(Res, (*it2).Name);
			Constit = it2;
			Res = "Test1";
			EXPECT_EQ(10, (*it2).Score);
			EXPECT_EQ(Res, (*it2).Name);
		}

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̖����Ɛ擪���r�����ۂ̋����e�X�g
			@details	ID:Iterator-21\n
						��̃C�e���[�^�����������ǂ������m�F����e�X�g�ł��B\n
						���X�g����̏�Ԃł̖����Ɛ擪���r�����ۂ̋������m�F���Ă��܂��B\n
						True�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenEmpty)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it;
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetEnd();
			bool IsTrue = false;
			if (it == it2)
				IsTrue = true;
			EXPECT_EQ(true, IsTrue);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋����e�X�g
			@details	ID:Iterator-22\n
						��̃C�e���[�^�����������ǂ������m�F����e�X�g�ł��B\n
						����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
						True�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenCorrectData)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test"});
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetBegin();
			bool IsTrue = false;
			if (it == it2)
				IsTrue = true;
			EXPECT_EQ(true, IsTrue);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
			@details	ID:Iterator-23\n
						��̃C�e���[�^�����������ǂ������m�F����e�X�g�ł��B\n
						�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
						False�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(CorrectTest, TestCorrectWhenDiffarentData)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test"});
			List.Insert(it, {20, "Test"});
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetEnd();
			bool IsTrue = false;
			if (it == it2)
				IsTrue = true;
			EXPECT_EQ(false, IsTrue);
		}

		/**********************************************************************************//**
			@brief		���X�g����̏�Ԃł̖����Ɛ擪���r�����ۂ̋����e�X�g
			@details	ID:Iterator-24\n
						��̃C�e���[�^���قȂ��Ă��邩�ǂ������m�F����e�X�g�ł��B\n
						���X�g����̏�Ԃł̖����Ɛ擪���r�����ۂ̋������m�F���Ă��܂��B\n
						False�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenEmpty)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			LinkedList<DATA>::Iterator it2 = List.GetEnd();
			bool IsTrue = false;
			if (it != it2)
				IsTrue = true;
			EXPECT_EQ(false, IsTrue);
		}

		/**********************************************************************************//**
			@brief		����̃C�e���[�^���r�����ۂ̋����e�X�g
			@details	ID:Iterator-25\n
						��̃C�e���[�^���قȂ��Ă��邩���m�F����e�X�g�ł��B\n
						����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
						False�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenCorrectData)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test"});
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetBegin();
			bool IsTrue = false;
			if (it != it2)
				IsTrue = true;
			EXPECT_EQ(false, IsTrue);
		}

		/**********************************************************************************//**
			@brief		�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
			@details	ID:Iterator-26\n
						��̃C�e���[�^���قȂ��Ă��邩���m�F����e�X�g�ł��B\n
						�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂��B\n
						True�Ȃ琬���ł��B\n
		*//***********************************************************************************/
		TEST(DiffarentTest, TestDiffarentWhenDiffarentData)
		{
			LinkedList<DATA> List;
			LinkedList<DATA>::Iterator it = List.GetBegin();
			List.Insert(it, {10, "Test"});
			List.Insert(it, {20, "Test"});
			LinkedList<DATA>::Iterator it2;
			it = List.GetBegin();
			it2 = List.GetEnd();
			bool IsTrue = false;
			if (it != it2)
				IsTrue = true;
			EXPECT_EQ(true, IsTrue);
		}

	}

}