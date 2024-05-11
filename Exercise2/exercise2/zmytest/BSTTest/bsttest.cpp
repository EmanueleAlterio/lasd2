#include<iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/iterator/iterator.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"

#include "../../zlasdtest/bst/bst.hpp"

using namespace std;


void testBSTInt(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BST<int> Test" << endl;

    try
    {
        lasd::BST<int> bst;
        Empty(loctestnum, loctesterr, bst, true);
        Size(loctestnum, loctesterr, bst, true, 0);

        InsertC(loctestnum, loctesterr, bst, true, 12);
        InsertC(loctestnum, loctesterr, bst, true, 5);
        InsertC(loctestnum, loctesterr, bst, true, 15);
        InsertC(loctestnum, loctesterr, bst, true, 3);
        InsertC(loctestnum, loctesterr, bst, true, 7);
        InsertC(loctestnum, loctesterr, bst, true, 13);
        InsertC(loctestnum, loctesterr, bst, true, 17);
        InsertC(loctestnum, loctesterr, bst, true, 1);
        InsertC(loctestnum, loctesterr, bst, true, 9);

        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
        Min(loctestnum, loctesterr, bst, true, 1);
        Max(loctestnum, loctesterr, bst, true, 17);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
        InsertC(loctestnum, loctesterr, bst, true, 19);
        InsertC(loctestnum, loctesterr, bst, true, 0);
        Size(loctestnum, loctesterr, bst, true, 11);
        Min(loctestnum, loctesterr, bst, true, 0);
        Max(loctestnum, loctesterr, bst, true, 19);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
        MinNRemove(loctestnum, loctesterr, bst, true, 0);
        MaxNRemove(loctestnum, loctesterr, bst, true, 19);
        Remove(loctestnum, loctesterr, bst, true, 7);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);
        Exists(loctestnum, loctesterr, bst, false, 7);
        Exists(loctestnum, loctesterr, bst, true, 13);

        Successor(loctestnum, loctesterr, bst, false, 13, 19);
        Successor(loctestnum, loctesterr, bst, true, 13, 15);
        Predecessor(loctestnum, loctesterr, bst, true, 13, 12);
        Successor(loctestnum, loctesterr, bst, false, 12, 15);
        Successor(loctestnum, loctesterr, bst, true, 12, 13);
        Predecessor(loctestnum, loctesterr, bst, true, 12, 9);

        PredecessorNRemove(loctestnum, loctesterr, bst, true, 12, 9);
        SuccessorNRemove(loctestnum, loctesterr, bst, true, 12, 13);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<int>);

        FoldPreOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 53);
        FoldInOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 53);
        FoldPostOrder(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 53);
        FoldBreadth(loctestnum, loctesterr, bst, true, &FoldAdd<int>, 0, 53);

        lasd::BST<int> copbst(bst);
        EqualBST(loctestnum, loctesterr, bst, copbst);

        Remove(loctestnum, loctesterr, copbst, true, 1);

        NonEqualBST(loctestnum, loctesterr, bst, copbst);

        InsertC(loctestnum, loctesterr, copbst, true, 1);

        EqualBST(loctestnum, loctesterr, bst, copbst);

        lasd::BST<int> movbst(move(copbst));
        EqualBST(loctestnum, loctesterr, bst, movbst);
        NonEqualBST(loctestnum, loctesterr, bst, copbst);
        Empty(loctestnum, loctesterr, copbst, true);
        Size(loctestnum, loctesterr, copbst, true, 0);

        lasd::BST<int> bst2 = copbst;
        Empty(loctestnum, loctesterr, bst2, true);
        bst2 = movbst;
        Empty(loctestnum, loctesterr, bst2, false);
        Size(loctestnum, loctesterr, bst2, true, 6);
        EqualBST(loctestnum, loctesterr, bst, movbst);

        bst2.Clear();
        Empty(loctestnum, loctesterr, bst2, true);
        bst2 = move(movbst);
        Empty(loctestnum, loctesterr, bst2, false);
        NonEqualBST(loctestnum, loctesterr, bst2, movbst);
        TraverseBreadth(loctestnum, loctesterr, bst2, true, &TraversePrint<int>);
        TraverseBreadth(loctestnum, loctesterr, movbst, true, &TraversePrint<int>);

        lasd::List<int> lst;
        InsertAtBack(loctestnum, loctesterr, lst, true, 12);
        InsertAtBack(loctestnum, loctesterr, lst, true, 9);
        InsertAtBack(loctestnum, loctesterr, lst, true, 22);
        InsertAtBack(loctestnum, loctesterr, lst, true, 1);
        InsertAtBack(loctestnum, loctesterr, lst, true, 3);
        InsertAtBack(loctestnum, loctesterr, lst, true, 25);

        lasd::BST<int> bst3(lst);
        TraversePreOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraverseBreadth(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);

        lasd::Vector<int> vec(6);
        SetAt(loctestnum, loctesterr, vec, true, 0, 12);
        SetAt(loctestnum, loctesterr, vec, true, 1, 9);
        SetAt(loctestnum, loctesterr, vec, true, 2, 25);
        SetAt(loctestnum, loctesterr, vec, true, 3, 1);
        SetAt(loctestnum, loctesterr, vec, true, 4, 3);
        SetAt(loctestnum, loctesterr, vec, true, 5, 22);

        lasd::BST<int> bst4(vec);
        TraversePreOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);
        TraverseBreadth(loctestnum, loctesterr, bst3, true, &TraversePrint<int>);

        EqualBST(loctestnum, loctesterr, bst3, bst4);

        lasd::BTBreadthIterator<int> itr4(bst4);
        GetItrValue(loctestnum, loctesterr, itr4, true, 12);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 9);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 25);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 1);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 22);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 3);


    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
    








void BSTTest(unsigned int & testnum, unsigned int & testerr){
    unsigned int loctestnum = 0;
    unsigned int loctesterr = 0;

    cout << endl << "Inizio Test BST" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    testBSTInt(loctestnum, loctesterr);

    cout << "-------------------------------------------------------------------------------" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
