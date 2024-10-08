#pragma once
#include"LinkedList.h"

/**
 * データ数を返す関数です。
 * 現在のデータ数を返します
 */
template <typename T>
int LinkedList<T>::GetDataNum() const { return DataNum; }

/**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
template <typename T>
bool LinkedList<T>::Insert(LinkedList<T>::ConstIterator& _it, const T& _data)
{
    //イテレータが空じゃないか確認
    if (!_it.IsEmpty())
    {
        //新しいノード作成
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
* コンストイテレータを使用してリストの要素を削除する関数です。
* @param _it     受け取ったイテレータ
*/
template <typename T>
bool LinkedList<T>::Delete(LinkedList<T>::ConstIterator& _it)
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
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetBegin() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* 先頭コンストイテレータを取得する関数です。
* @return 先頭コンストイテレータ
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstBegin() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* 末尾イテレータを取得する関数です。
* @return 先頭イテレータ
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetEnd() {
    LinkedList<T>::Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * 末尾コンストイテレータを取得する関数です。
 * @return 先頭イテレータ
 */
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstEnd() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * ノードが空か調べます
 * @return ノードが空かどうかを返します
*/
template <typename T>
typename bool LinkedList<T>::ConstIterator::IsEmpty() { return Node == nullptr; }

//コンストイテレータクラスのオペレータ
/*
 * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++()
{
    this->Node = Node->Next;
    return *this;
}

/*
 * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
 * @return 次のノードを取得したイテレータを返します
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
 * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
 * @return 前ノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--() {
    this->Node = Node->Prev;
    return *this;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
 * @return 前のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    return it;
}

/*
 * イテレータのさす要素を取得するオペレータ(const)です
 * @return ノードを返します
*/
template <typename T>
const T* LinkedList<T>::ConstIterator::operator*() const { return Node->Data; }

/*
 * 代入するオペレータです
 *@return コンストイテレータを返します
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
 * 比較するオペレータです
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator==(const LinkedList<T>::ConstIterator& _constit) const {
    return Node == _constit.Node;
}

/*
 * 比較するオペレータです
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator!=(const LinkedList<T>::ConstIterator& _constit) const {
    return Node != _constit.Node;
}

//イテレータクラスのオペレータ
/*
* イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
* @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++() {
    //assert(Node != nullptr && "Iterator points to null!");
    //assert(Node->Data != nullptr && "Iterator points to Dummy!");
    this->Node = this->Node->Next;
    return *this;
}

/*
 * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    //assert(Node != nullptr && "Iterator points to null!");
    //assert(Node->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = this->Node;
    this->Node = this->Node->Next;
    return it;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
 * @return 前ノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--() {
    //assert(Node != nullptr && "Iterator points to null!");
    //assert(Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    this->Node = this->Node->Prev;
    return *this;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
 * @return 前のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int) {
    //assert(Node != nullptr && "Iterator points to null!");
    //assert(Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = this->Node;
    this->Node = this->Node->Prev;
    return it;
}

/*
 * イテレータのさす要素を取得する(非const)関数です。
 * @return イテレータの要素を返します
*/
template <typename T>
T* LinkedList<T>::Iterator::operator*() {
    //assert(Node != nullptr && "Iterator points to null!");
    //assert(Node->Data != nullptr && "Iterator points to Dummy!");
    return this->Node->Data;
}

/*
 * 比較するオペレータです
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _it) const {
    return this->Node == _it.Node;
}

/*
 * 比較するオペレータです
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _it) const {
    return this->Node != _it.Node;
}