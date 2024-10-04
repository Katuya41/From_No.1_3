#pragma once
#include"LinkedList.h"
/**
    * �󂯎�����f�[�^�����X�g�̐擪�Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
   template <typename T>
bool InsertFrontInl(const T& _data)
{
    //�V�����m�[�h�쐬
    NODE* NewNode;
    //�f�[�^����
    T Data;
    Data.Score = _data.Score;
    Data.Name = _data.Name;
    //�m�[�h�쐬
    NewNode = new NODE();
    NewNode->Data = Data;
    NewNode->Prev = &Dammy;       //�V�����m�[�h�̑O�̓_�~�[(�擪)
    NewNode->Next = Dammy.Next;   //�V�����m�[�h�̎��̓_�~�[�̎�(�擪�������m�[�h)
    Dammy.Next->Prev = NewNode;   //�擪�������m�[�h�̑O��V�����m�[�h
    Dammy.Next = NewNode;
    DataNum++;
    return true;
}

/**
    * �󂯎�����f�[�^�����X�g�̖����Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
template <typename T>
bool InsertLastInl(const T& _data)
{
    //�V�����m�[�h�쐬
    NODE* NewNode;
    T Data;
    Data.Score = _data.Score;
    Data.Name = _data.Name;
    //�m�[�h�쐬
    NewNode = new NODE();
    NewNode->Data = Data;
    NewNode->Prev = Dammy.Prev;   //�V�����m�[�h�̑O�̓_�~�[(�����������m�[�h)
    NewNode->Next = &Dammy;       //�V�����m�[�h�̎��̓_�~�[
    Dammy.Prev->Next = NewNode;   //�����������m�[�h�̎���V�����m�[�h
    Dammy.Prev = NewNode;
    DataNum++;
    return true;
}

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
    if (!_it.IsEmpty())
    {
        //�V�����m�[�h�쐬
        NODE* NewNode = new NODE();
        T Data;
        Data.Score = _data.Score;
        Data.Name = _data.Name;
        NewNode->Data = Data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
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
        T Data;
        Data.Score = _data.Score;
        Data.Name = _data.Name;
        NewNode->Data = Data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
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
    if (_it.Node != nullptr)
    {
        _it.Node->Next->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = _it.Node->Next;
        delete _it.Node;
        DataNum--;
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
    if (_it.Node != nullptr)
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
    it.Node = Dammy.Next;
    return it;
}

/*
* �擪�R���X�g�C�e���[�^���擾����֐��ł��B
* @return �擪�R���X�g�C�e���[�^
*/
ConstIterator GetConstBeginInl() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dammy.Next;
    return it;
}

/*
* �����C�e���[�^���擾����֐��ł��B
* @return �擪�C�e���[�^
*/
Iterator GetEndInl() {
    Iterator it;
    it.Node = Dammy.Prev;
    return it;
}

/*
 * �����R���X�g�C�e���[�^���擾����֐��ł��B
 * @return �擪�C�e���[�^
 */
ConstIterator GetConstEndInl() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dammy.Prev;
    return it;
}