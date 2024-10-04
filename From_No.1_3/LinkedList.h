#pragma once
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
    * �󂯎�����f�[�^�����X�g�̐擪�Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertFront(const T& _data)
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
    }

    /**
    * �󂯎�����f�[�^�����X�g�̖����Ɋi�[����֐��ł��B
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void InsertLast(const T& _data)
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
    }

    /**
    * �C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    void Insert(Iterator _it, const T& _data)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (_it.IsEmpty())
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
        }
    }

    /**
    * �C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    void Delete(Iterator _it)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if (_it.Node != nullptr)
        {
            _it.Node->Next->Prev = _it.Node->Prev;
            _it.Node->Prev->Next = _it.Node->Next;
            delete _it.Node;
            DataNum--;
        }
    }

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it.Node = Dammy.Next;
        return it;
    }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
     LinkedList::ConstIterator GetBegin()const {
         LinkedList::ConstIterator it;
         it.Node = Dammy.Next;
         return it;
    }

     /*
     * �����C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it.Node = Dammy.Prev;
        return it;
    }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator it;
        it.Node = Dammy.Prev;
        return it;
    }

    /*
    * �����ConstIterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
public:
    class ConstIterator
    {
    private:
        friend class LinkedList;


    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        //�R���X�g���N�^
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

        /*
         * �_�~�[�m�[�h�����ׂ܂�
         * @return �m�[�h���_�~�[�m�[�h���ǂ�����Ԃ��܂�
        */
        bool CheckDammy() {
            if (Node->IsDammy)
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
            Node = Node->Next;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Next;
            return Constit;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--() {
            Node = Node->Prev;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Prev;
            return Constit;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const T operator*() const { return Node->Data; }

        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        ////���
        //const LinkedList::ConstIterator operator=(const ConstIterator& _it) {
        //        LinkedList::ConstIterator NewConst;
        //        NewConst = _it;
        //        return NewConst;
        //}

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
            this->Node = this->Node->Next;
            LinkedList::Iterator it;
            it.Node = this->Node;
            return it;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++(int) {
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
            this->Node = this->Node->Prev;
            LinkedList::Iterator it;
            it.Node = this->Node;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = this->Node;
            this->Node = this->Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        T operator*() {
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
};
