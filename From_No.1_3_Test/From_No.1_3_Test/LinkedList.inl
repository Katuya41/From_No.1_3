#pragma once
#include"LinkedList.h"
/**
    * �C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
template <typename T>
bool InsertInl(Iterator& _it, const T& _data)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (_it.Node != nullptr)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode = new NODE();
        DATA Data;
        Data.Score = _data.Score;
        Data.Name = _data.Name;
        NewNode->Data = Data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = NewNode;
        _it.Node->Prev = NewNode;
        DataNum++;
        return true;
    }
    return false;
}

/**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
template <typename T>
bool InsertInl(ConstIterator& _it, const T& _data)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (!_it.IsEmpty())
    {
        //�V�����m�[�h�쐬
        NODE* NewNode = new NODE();
        DATA Data;
        Data.Score = _data.Score;
        Data.Name = _data.Name;
        NewNode->Data = Data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = NewNode;
        _it.Node->Prev = NewNode;
        DataNum++;
        return true;
    }
    return false;
}

/**
* �C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
* @param _it     �󂯎�����C�e���[�^
*/
bool DeleteInl(Iterator& _it)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (!_it.IsEmpty())
    {
        NODE* DeleteNode = _it.Node;
        _it.Node->Next->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = _it.Node->Next;
        delete _it.Node;
        DataNum--;
        _it.Node = DeleteNode->Next;
        return true;
    }
    return false;
}

/**
* �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
* @param _it     �󂯎�����C�e���[�^
*/
bool DeleteInl(ConstIterator& _it)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (!_it.IsEmpty())
    {
        _it.Node->Next->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = _it.Node->Next;
        delete _it.Node;
        DataNum--;
        return true;
    }
    return false;
}

/*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
Iterator GetBeginInl() {
    Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* �擪�R���X�g�C�e���[�^���擾����֐��ł��B
* @return �擪�R���X�g�C�e���[�^
*/
ConstIterator GetConstBeginInl() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* �����C�e���[�^���擾����֐��ł��B
* @return �擪�C�e���[�^
*/
Iterator GetEndInl() {
    Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * �����R���X�g�C�e���[�^���擾����֐��ł��B
 * @return �擪�C�e���[�^
 */
ConstIterator GetConstEndInl() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
* �_�~�[�m�[�h�����ׂ܂�
* @return �m�[�h���_�~�[�m�[�h���ǂ�����Ԃ��܂�
 */
bool IsDummyInl(NODE* _node) {
    if (&Dummy == _node)
        return true;
    else
        return false;
}

 /*
 * �_�~�[�m�[�h�����ׂ܂�
 * @return �m�[�h���_�~�[�m�[�h���ǂ�����Ԃ��܂�
 */
bool IsDummyInl (ConstIterator _it) {
    if (&Dummy == _it.Node)
        return true;
    else
        return false;
}