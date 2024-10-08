#pragma once
#include"LinkedList.h"

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
        DATA* Data = new DATA();
        Data->Score = _data.Score;
        Data->Name = _data.Name;
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

/*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetBegin() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* �擪�R���X�g�C�e���[�^���擾����֐��ł��B
* @return �擪�R���X�g�C�e���[�^
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstBegin() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* �����C�e���[�^���擾����֐��ł��B
* @return �擪�C�e���[�^
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetEnd() {
    LinkedList<T>::Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * �����R���X�g�C�e���[�^���擾����֐��ł��B
 * @return �擪�C�e���[�^
 */
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstEnd() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * �m�[�h���󂩒��ׂ܂�
 * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
*/
template <typename T>
typename bool LinkedList<T>::ConstIterator::IsEmpty() { return Node == nullptr; }

//�R���X�g�C�e���[�^�N���X�̃I�y���[�^
/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++() 
{
    this->Node = Node->Next;
    return *this;
}

/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    return it;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--() {
    this->Node = Node->Prev;
    return *this;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    return it;
}

/*
 * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
 * @return �m�[�h��Ԃ��܂�
*/
template <typename T>
const T* LinkedList<T>::ConstIterator::operator*() const { return Node->Data; }

/*
 * �������I�y���[�^�ł�
 *@return �R���X�g�C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator=(const Iterator* _it) {
    if (this != _it) {
        LinkedList::ConstIterator NewConst;
        NewConst = _it;
        return NewConst;
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
* �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
* @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++() {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
    this->Node = Node->Next;
    return *this;
}

/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    return it;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--() {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    this->Node = Node->Prev;
    return *this;
}

/*
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int) {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    return it;
}

/*
 * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
 * @return �C�e���[�^�̗v�f��Ԃ��܂�
*/
template <typename T>
T* LinkedList<T>::Iterator::operator*() {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
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