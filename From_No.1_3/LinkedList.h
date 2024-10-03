#pragma once
#include <string>
#include <iostream>

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
     *�f�[�^������\���̂ł��B
     *
     * @param Score �X�R�A
     * @param Name  ���O
     */
    struct DATA
    {
        T Score;
        T Name;

        //T Num;

        //std::string Score;
        //std::string Name;
    };

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
        DATA Data;             //�f�[�^
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
    LinkedList() { Dammy.Next = Dammy.Prev = &Dammy; }
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
    void InsertFront(T& _score, T& _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        //�f�[�^����
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
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
    void InsertLast(T& _score, T& _name)
    {
        //�V�����m�[�h�쐬
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
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
    void Insert(Iterator _it, T _score, T _name)
    {
        //�C�e���[�^���󂶂�Ȃ����m�F
        if ((*_it) != nullptr)
        {
            //�V�����m�[�h�쐬
            NODE* NewNode = new NODE();
            DATA Data;
            Data.Score = _score;
            Data.Name = _name;
            NewNode->Data = Data;
            NewNode->Next = _it.GetNode();
            NewNode->Prev = _it.GetNode()->Prev;
            _it.GetNode()->Prev = NewNode;
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
        if (_it.GetNode() != nullptr)
        {
            _it.GetNode()->Next->Prev = _it.GetNode()->Prev;
            _it.GetNode()->Prev->Next = _it.GetNode()->Next;
            delete _it.GetNode();
            DataNum--;
        }
    }

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it = Dammy.Next;
        return it;
    }

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
     const LinkedList::ConstIterator GetBegin()const {
         LinkedList::ConstIterator it;
         it = Dammy.Next;
         return it;
    }

     /*
     * �����C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it = Dammy.Prev;
        return it;
    }

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �擪�C�e���[�^
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator it;
        it = Dammy.Prev;
        return it;
    }

    /*
     * ���X�g�̓��e��擪���珇�Ԃɏo�͂���֐��ł��B
     */
    void display()  {
        LinkedList::Iterator it;
        it = GetBegin();
        while ((*it) != &Dammy) {
            printf("�X�R�A: %s ,���O: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
            it++;
            //++it;
        }
    }

    /*
    * �����ConstIterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class ConstIterator
    {
    protected:
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++() {
            Node = Node->Next;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Next;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--() {
            Node = Node->Prev;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const NODE* operator*() const { return Node; }
        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //���
        const LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
        }
        //���
        LinkedList::ConstIterator operator=(NODE* _node) {
                LinkedList::ConstIterator NewConstit;
                NewConstit = _node;
                return NewConstit;
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
    //protected:
    //    //�m�[�h
    //    NODE* Node = nullptr;
    public:

        /**
         * ���݂̃C�e���[�^�̗v�f��Ԃ��֐��ł��B
         * @return �C�e���[�^�̒��g
        */
        NODE* GetNode() { return this->NodeNode; }

        /**
         * ���݂̃C�e���[�^�̃m�[�h�̃f�[�^��Ԃ��֐��ł��B
         * @return �C�e���[�^�̃m�[�h�̒��g
        */
        DATA GetNodeData()
        {
            if (this->NodeNode != nullptr)
            {
                DATA Data;
                Data.Score = this->NodeNode->Data.Score;
                Data.Name = this->NodeNode->Data.Name;
                return Data;
            }
            else
            {
                DATA Data;
                Data.Score = "NULL";
                Data.Name = "NULL";
                return Data;
            }
        }

        /**
         * �C�e���[�^�̒��g�̃m�[�h�̃f�[�^��ύX����֐��ł��B
         * @param _score   �ύX��̃X�R�A
         * @param _name    �ύX��̖��O
        */
        void ChengeData(std::string& _score, std::string& _name)
        {
            this->Node->Data.Score = _score;
            this->NodeNode->Data.Name = _name;
        }

        /**
         * �󂯎�����C�e���[�^������łȂ����𒲂ׂ�֐��ł��B
         * @param _it1   ��r����C�e���[�^1
         * @param _it2   ��r����C�e���[�^2
         * @return ��r�����C�e���[�^������łȂ�����Ԃ��܂�
        */
        bool FalseCheckIterator(Iterator*& _it1, Iterator*& _it2)
        {
            if (_it1->Node != _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        /**
         * �󂯎�����C�e���[�^�����ꂩ�𒲂ׂ�֐��ł��B
         * @param _it1   ��r����C�e���[�^1
         * @param _it2   ��r����C�e���[�^2
         * @return ��r�����C�e���[�^�����ꂩ��Ԃ��܂�
        */
        bool TrueCheckIterator(Iterator* _it1, Iterator* _it2)
        {
            if (_it1->Node == _it2->Node)
            {
                return true;
            }
            else
                return false;
        }

        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        NODE* operator*() { return this->Node; }

        //�I�y���[�^

        //���
        LinkedList::Iterator operator=(NODE* _node) {
            this->Node = _node;
            return *this;
        }
    };
};
