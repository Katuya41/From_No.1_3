#pragma once
#include <string>
#include <iostream>

/**
 * これはLinkedListクラスの説明です。
 * このクラスは双方向リストで使用されます。
 *
 * @author 吉村括哉
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
     *データを入れる構造体です。
     *
     * @param Score スコア
     * @param Name  名前
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
     *ノードを入れる構造体です。
     *
     * @param prev  前のノード
     * @param next  次のノード
     * @param Data  データ
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //一個前のノード
        NODE* Next = nullptr;     //次のノード
        DATA Data;             //データ
        bool IsDammy = false;  //ダミーか
    };

    //ダミーノード
    NODE Dammy;

    //データの数
    int DataNum = 0;

public:
    /**
     * LinkedListクラスのコンストラクタ。
     * 初期化処理を行います。
     */
    LinkedList() { Dammy.Next = Dammy.Prev = &Dammy; }
    ~LinkedList() {}

    /**
     * データ数を返す関数です。
     * 現在のデータ数を返します
     */
    int GetDataNum() { return DataNum; }

    /**
    * 受け取ったデータをリストの先頭に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertFront(T& _score, T& _name)
    {
        //新しいノード作成
        NODE* NewNode;
        //データ入力
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //ノード作成
        NewNode = new NODE();
        NewNode->Data = Data;       
        NewNode->Prev = &Dammy;       //新しいノードの前はダミー(先頭)
        NewNode->Next = Dammy.Next;   //新しいノードの次はダミーの次(先頭だったノード)
        Dammy.Next->Prev = NewNode;   //先頭だったノードの前を新しいノード
        Dammy.Next = NewNode;
        DataNum++;
    }

    /**
    * 受け取ったデータをリストの末尾に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void InsertLast(T& _score, T& _name)
    {
        //新しいノード作成
        NODE* NewNode;
        DATA Data;
        Data.Score = _score;
        Data.Name = _name;
        //ノード作成
        NewNode = new NODE();
        NewNode->Data = Data;
        NewNode->Prev = Dammy.Prev;   //新しいノードの前はダミー(末尾だったノード)
        NewNode->Next = &Dammy;       //新しいノードの次はダミー
        Dammy.Prev->Next = NewNode;   //末尾だったノードの次を新しいノード
        Dammy.Prev = NewNode;
        DataNum++;
    }

    /**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    void Insert(Iterator _it, T _score, T _name)
    {
        //イテレータが空じゃないか確認
        if ((*_it) != nullptr)
        {
            //新しいノード作成
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
    * イテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    void Delete(Iterator _it)
    {
        //イテレータが空じゃないか確認
        if (_it.GetNode() != nullptr)
        {
            _it.GetNode()->Next->Prev = _it.GetNode()->Prev;
            _it.GetNode()->Prev->Next = _it.GetNode()->Next;
            delete _it.GetNode();
            DataNum--;
        }
    }

    /*
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList::Iterator GetBegin() {
        Iterator it;
        it = Dammy.Next;
        return it;
    }

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
     const LinkedList::ConstIterator GetBegin()const {
         LinkedList::ConstIterator it;
         it = Dammy.Next;
         return it;
    }

     /*
     * 末尾イテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    LinkedList::Iterator GetEnd() {
        Iterator it;
        it = Dammy.Prev;
        return it;
    }

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    LinkedList::ConstIterator GetConstEnd() const {
        LinkedList::ConstIterator it;
        it = Dammy.Prev;
        return it;
    }

    /*
     * リストの内容を先頭から順番に出力する関数です。
     */
    void display()  {
        LinkedList::Iterator it;
        it = GetBegin();
        while ((*it) != &Dammy) {
            printf("スコア: %s ,名前: %s \n", (*it)->Data.Score.c_str(), (*it)->Data.Name.c_str());
            it++;
            //++it;
        }
    }

    /*
    * これはConstIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
    class ConstIterator
    {
    protected:
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator(){}

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++() {
            Node = Node->Next;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Next;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--() {
            Node = Node->Prev;
            LinkedList::Iterator it;
            it.Node = Node;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = Node;
            Node = Node->Prev;
            return it;
        }

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const NODE* operator*() const { return Node; }
        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}
        //代入
        const LinkedList::ConstIterator operator=(const Iterator* _it) {
            if (this != _it) {
                LinkedList::ConstIterator NewConst;
                NewConst = _it;
                return NewConst;
            }
        }
        //代入
        LinkedList::ConstIterator operator=(NODE* _node) {
                LinkedList::ConstIterator NewConstit;
                NewConstit = _node;
                return NewConstit;
        }

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const {
            return Node == _constit.Node;
        }

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const {
            return Node != _constit.Node;
        }

    };

    /**
    * これはIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    //protected:
    //    //ノード
    //    NODE* Node = nullptr;
    public:

        /**
         * 現在のイテレータの要素を返す関数です。
         * @return イテレータの中身
        */
        NODE* GetNode() { return this->NodeNode; }

        /**
         * 現在のイテレータのノードのデータを返す関数です。
         * @return イテレータのノードの中身
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
         * イテレータの中身のノードのデータを変更する関数です。
         * @param _score   変更後のスコア
         * @param _name    変更後の名前
        */
        void ChengeData(std::string& _score, std::string& _name)
        {
            this->Node->Data.Score = _score;
            this->NodeNode->Data.Name = _name;
        }

        /**
         * 受け取ったイテレータが同一でないかを調べる関数です。
         * @param _it1   比較するイテレータ1
         * @param _it2   比較するイテレータ2
         * @return 比較したイテレータが同一でないかを返します
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
         * 受け取ったイテレータが同一かを調べる関数です。
         * @param _it1   比較するイテレータ1
         * @param _it2   比較するイテレータ2
         * @return 比較したイテレータが同一かを返します
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
         * イテレータのさす要素を取得する(非const)関数です。
         * @return イテレータの要素を返します
        */
        NODE* operator*() { return this->Node; }

        //オペレータ

        //代入
        LinkedList::Iterator operator=(NODE* _node) {
            this->Node = _node;
            return *this;
        }
    };
};
