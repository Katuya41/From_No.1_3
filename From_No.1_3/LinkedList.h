#pragma once
//#ifndef LINKED_LIST_H
//#define LINKED_LIST_H
//#include <string>

#include "main.h"

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
        T Data;             //データ
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
    LinkedList() {
        Dammy.Next = Dammy.Prev = &Dammy;
        Dammy.IsDammy = true;
    }
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
    bool InsertFront(const T& _data) { return InsertFrontInl(_data); }

    /**
    * 受け取ったデータをリストの末尾に格納する関数です。
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool InsertLast(const T& _data) { return InsertLastInl(_data); }

    /**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool Insert(LinkedList<T>::Iterator& _it, const T& _data) { return InsertInl(_it, _data); }

    /**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool Insert(LinkedList<T>::ConstIterator& _it, const T& _data) { return InsertInl(_it, _data); }

    /**
    * イテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    bool Delete(LinkedList<T>::Iterator& _it) { return DeleteInl(_it); }

    /**
    * コンストイテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    bool Delete(ConstIterator& _it) { return DeleteInl(_it); }

    /*
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
   Iterator GetBegin() { return GetBeginInl(); }

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
    ConstIterator GetConstBegin()const { return GetConstBeginInl(); }

    /*
    * 末尾イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    Iterator GetEnd() { return GetEndInl(); }

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return 先頭イテレータ
     */
    ConstIterator GetConstEnd() const { return GetConstEndInl(); }

    /*
    * これはConstIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
public:
    class ConstIterator
    {
    private:
        friend class LinkedList;

        
    protected:
        //ノード
        NODE* Node = nullptr;

    public:
        //コンストラクタ
        LinkedList::ConstIterator() {}

        /*
         * ノードが空か調べます
         * @return ノードが空かどうかを返します
        */
        bool IsEmpty() {
            if (Node == nullptr)
                return true;
            else
                return false;
        }

        /*
         * ダミーノードか調べます
         * @return ノードがダミーノードかどうかを返します
        */
        bool CheckDammy() {
            if (Node->IsDammy)
                return true;
            else
                return false;
        }

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++() {
            Node = Node->Next;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Next;
            return Constit;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--() {
            Node = Node->Prev;
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            return Constit;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--(int) {
            LinkedList::ConstIterator Constit;
            Constit.Node = Node;
            Node = Node->Prev;
            return Constit;
        }

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const T operator*() const { return Node->Data; }

        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        ////代入
        //const LinkedList::ConstIterator operator=(const ConstIterator& _it) {
        //        LinkedList::ConstIterator NewConst;
        //        NewConst = _it;
        //        return NewConst;
        //}

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
    private:
        friend class LinkedList;

    public:
        //コンストラクタ
        LinkedList::Iterator() {}

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++() {
            this->Node = this->Node->Next;
            LinkedList::Iterator it;
            it.Node = this->Node;
            return it;
        }

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator++(int) {
            LinkedList::Iterator it;
            it.Node = this->Node;
            this->Node = this->Node->Next;
            return it;

        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--() {
            this->Node = this->Node->Prev;
            LinkedList::Iterator it;
            it.Node = this->Node;
            return it;
        }

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::Iterator operator--(int) {
            LinkedList::Iterator it;
            it.Node = this->Node;
            this->Node = this->Node->Prev;
            return it;
        }

        /*
         * イテレータのさす要素を取得する(非const)関数です。
         * @return イテレータの要素を返します
        */
        T operator*() {
            return this->Node->Data;
        }

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::Iterator& _it) const {
            return this->Node == _it.Node;
        }

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::Iterator& _it) const {
            return this->Node != _it.Node;
        }
    };

    private:
    #include "LinkedList.inl"
};
