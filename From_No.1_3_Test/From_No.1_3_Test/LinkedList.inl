#pragma once
#include"LinkedList.h"
/**
    * イテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
template <typename T>
bool InsertInl(Iterator& _it, const T& _data)
{
    //イテレータが空じゃないか確認
    if (_it.Node != nullptr)
    {
        //新しいノード作成
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
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
template <typename T>
bool InsertInl(ConstIterator& _it, const T& _data)
{
    //イテレータが空じゃないか確認
    if (!_it.IsEmpty())
    {
        //新しいノード作成
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
* イテレータを使用してリストの要素を削除する関数です。
* @param _it     受け取ったイテレータ
*/
bool DeleteInl(Iterator& _it)
{
    //イテレータが空じゃないか確認
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
* コンストイテレータを使用してリストの要素を削除する関数です。
* @param _it     受け取ったイテレータ
*/
bool DeleteInl(ConstIterator& _it)
{
    //イテレータが空じゃないか確認
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
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
Iterator GetBeginInl() {
    Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* 先頭コンストイテレータを取得する関数です。
* @return 先頭コンストイテレータ
*/
ConstIterator GetConstBeginInl() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* 末尾イテレータを取得する関数です。
* @return 先頭イテレータ
*/
Iterator GetEndInl() {
    Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * 末尾コンストイテレータを取得する関数です。
 * @return 先頭イテレータ
 */
ConstIterator GetConstEndInl() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
* ダミーノードか調べます
* @return ノードがダミーノードかどうかを返します
 */
bool IsDummyInl(NODE* _node) {
    if (&Dummy == _node)
        return true;
    else
        return false;
}

 /*
 * ダミーノードか調べます
 * @return ノードがダミーノードかどうかを返します
 */
bool IsDummyInl (ConstIterator _it) {
    if (&Dummy == _it.Node)
        return true;
    else
        return false;
}