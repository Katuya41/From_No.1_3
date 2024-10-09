#pragma once
#include"LinkedList.h"

template<typename T>
inline LinkedList<T>::LinkedList()
{
    Dummy = new NODE();
    Dummy->Next = Dummy->Prev = Dummy;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
    //���X�g�̒��g���폜
    Clear();

    //�_�~�[�m�[�h�폜
    delete Dummy;
}

/**
 * �f�[�^����Ԃ��֐��ł��B
 * ���݂̃f�[�^����Ԃ��܂�
 */
template <typename T>
int LinkedList<T>::GetDataNum() const { return DataNum; }

/**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
template <typename T>
bool LinkedList<T>::Insert(LinkedList<T>::ConstIterator& _it, const T& _data)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (!_it.IsEmpty())
    {
        //�V�����m�[�h�쐬
        NODE* NewNode = new NODE();

        NewNode->Data = _data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = NewNode;
        _it.Node->Prev = NewNode;
        _it.Node = NewNode;
        DataNum++;
        return true;
    }
    return false;
}

/**
* �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
* @param _it     �󂯎�����C�e���[�^
*/
template <typename T>
bool LinkedList<T>::Delete(LinkedList<T>::ConstIterator& _it)
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

template<typename T>
inline void LinkedList<T>::Clear()
{
    if (Dummy == GetBegin().Node)
    {
        return;
    }

    NODE* Current = Dummy->Next;
    NODE* NextNode;

    do {
        NextNode = Current->Next; // ���̃m�[�h��ۑ�
        delete Current; // ���݂̃m�[�h�����
        Current = NextNode; // ���̃m�[�h�ɐi��
    } while (Current != Dummy); // ���X�g���ꏄ������I��

    Dummy->Next = Dummy->Prev = Dummy;

    DataNum = 0;
}

/*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetBegin() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy->Next;
    return it;
}

/*
* �擪�R���X�g�C�e���[�^���擾����֐��ł��B
* @return �擪�R���X�g�C�e���[�^
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstBegin() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy->Next;
    return it;
}

/*
* �����C�e���[�^���擾����֐��ł��B
* @return �_�~�[�m�[�h
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetEnd() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy;
    return it;
}

/*
 * �����R���X�g�C�e���[�^���擾����֐��ł��B
 * @return �_�~�[�m�[�h
 */
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstEnd() {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy;
    return it;
}

/*
* �͈�for�ɑΉ�����begin�֐��ł��B
* @return �擪�C�e���[�^
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    LinkedList<T>::Iterator it;
    it = GetBegin();
    return it;
}

/*
* �͈�for�ɑΉ�����end�֐��ł��B
* @return �����C�e���[�^
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    LinkedList<T>::Iterator it;
    it = GetEnd();
    return it;
}

/*
 * �m�[�h���󂩒��ׂ܂�
 * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
*/
template <typename T>
typename bool LinkedList<T>::ConstIterator::IsEmpty() { return Node == nullptr; }


template <typename T>
bool LinkedList<T>::ConstIterator::IsDummy() const {
    return this->Node == LinkedList<T>::Dummy;
}

//�R���X�g�C�e���[�^�N���X�̃I�y���[�^
/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator++()
{
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    this->Node = Node->Next;
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return *this;
}

/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    //assert(IsDummy() != true && "Iterator points to Dummy!");
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return it;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator--() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    this->Node = Node->Prev;
    //assert(this->Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    return *this;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    //assert(IsDummy() != true && "Iterator points to Dummy!");
    //assert(this->Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    return it;
}

/*
 * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
 * @return �m�[�h��Ԃ��܂�
*/
template <typename T>
const T& LinkedList<T>::ConstIterator::operator*() const { return this->Node->Data; }

/*
 * �������I�y���[�^�ł�
 *@return �R���X�g�C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(const Iterator& _it) {
    if ((*this) != _it) {
        this->Node = _it.Node;
        return *this;
    }
    return *this;
}

/*
 * ��r����I�y���[�^�ł�
 * @return ���ꂩ��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator==(const LinkedList<T>::ConstIterator& _constit) const {
    return Node == _constit.Node;
}

/*
 * ��r����I�y���[�^�ł�
 * @return �قȂ邩��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator!=(const LinkedList<T>::ConstIterator& _constit) const {
    return Node != _constit.Node;
}

//�C�e���[�^�N���X�̃I�y���[�^
/*
 * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
 * @return �C�e���[�^�̗v�f��Ԃ��܂�
*/
template <typename T>
T& LinkedList<T>::Iterator::operator*() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return this->Node->Data;
}

/*
 * ��r����I�y���[�^�ł�
 * @return ���ꂩ��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _it) const {
    return this->Node == _it.Node;
}

/*
 * ��r����I�y���[�^�ł�
 * @return �قȂ邩��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _it) const {
    return this->Node != _it.Node;
}