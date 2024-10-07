#pragma once
//#ifndef LINKED_LIST_H
//#define LINKED_LIST_H
//#include <string>

#include "main.h"

/**
 * �����LinkedList�N���X�̐����ł��B
 * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
 *
 * @author �g������
 * @since 2024-10-02
 */
template <typename T>
class LinkedList
{
public:
    class Iterator;
    class ConstIterator;

private:

    /**
     *�m�[�h������\���̂ł��B
     *
     * @param prev  �O�̃m�[�h
     * @param next  ���̃m�[�h
     * @param Data  �f�[�^
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //��O�̃m�[�h
        NODE* Next = nullptr;     //���̃m�[�h
        T Data;             //�f�[�^
        bool IsDammy = false;  //�_�~�[��
    };

    //�_�~�[�m�[�h
    NODE Dammy;

    //�f�[�^�̐�
    int DataNum = 0;

public:
    /**
     * LinkedList�N���X�̃R���X�g���N�^�B
     * �������������s���܂��B
     */
    LinkedList() {
        Dammy.Next = Dammy.Prev = &Dammy;
        Dammy.IsDammy = true;
    }
    ~LinkedList() {}

    /**
     * �f�[�^����Ԃ��֐��ł��B
     * ���݂̃f�[�^����Ԃ��܂�
     */
    int GetDataNum() { return DataNum; }

    /**
    * �C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool Insert(LinkedList<T>::Iterator& _it, const T& _data) { return InsertInl(_it, _data); }

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool Insert(LinkedList<T>::ConstIterator& _it, const T& _data) { return InsertInl(_it, _data); }

    /**
    * �C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    bool Delete(LinkedList<T>::Iterator& _it) { return DeleteInl(_it); }

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    bool Delete(ConstIterator& _it) { return DeleteInl(_it); }

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
   Iterator GetBegin() { return GetBeginInl(); }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
    ConstIterator GetConstBegin()const { return GetConstBeginInl(); }

    /*
    * �����C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    Iterator GetEnd() { return GetEndInl(); }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    ConstIterator GetConstEnd() const { return GetConstEndInl(); }

    /*
    * �����ConstIterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class ConstIterator
    {
    private:
        friend class LinkedList;

    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator() {}

        /*
         * �m�[�h���󂩒��ׂ܂�
         * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
        */
        bool IsEmpty() {
            if (Node == nullptr)
                return true;
            else
                return false;
        }

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++() {
            this->Node = Node->Next;
            return *this;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Next;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--() {
            this->Node = Node->Prev;
            return *this;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const DATA operator*() const { return Node->Data; }
        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //���
        LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const {
            return Node == _constit.Node;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const {
            return Node != _constit.Node;
        }

    };

    /**
    * �����Iterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    private:
        friend class LinkedList;

    public:
        //�R���X�g���N�^
        LinkedList::Iterator() {}

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = this->Node->Next;
            return *this;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++(int) {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            LinkedList::Iterator it;
            it.Node = this->Node;
            this->Node = this->Node->Next;
            return it;

        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            this->Node = this->Node->Prev;
            return *this;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--(int) {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            LinkedList::Iterator it;
            it.Node = this->Node;
            this->Node = this->Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        DATA operator*() {
            //assert(Node != nullptr && "Iterator points to null!");
            //assert(Node->IsDummy != true && "Iterator points to Dummy!");
            return this->Node->Data;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::Iterator& _it) const {
            return this->Node == _it.Node;
        }

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::Iterator& _it) const {
            return this->Node != _it.Node;
        }
    };

    private:
    #include "LinkedList.inl"
};
