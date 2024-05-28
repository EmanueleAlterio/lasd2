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
        TraversePreOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<int>);
        TraverseBreadth(loctestnum, loctesterr, bst4, true, &TraversePrint<int>);

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

        lasd::BTInOrderIterator<int> itr5(bst4);
        GetItrValue(loctestnum, loctesterr, itr5, true, 1);
        ++itr5;
        GetItrValue(loctestnum, loctesterr, itr5, true, 3);
        ++itr5;
        GetItrValue(loctestnum, loctesterr, itr5, true, 9);
        ++itr5;
        GetItrValue(loctestnum, loctesterr, itr5, true, 12);
        ++itr5;
        GetItrValue(loctestnum, loctesterr, itr5, true, 22);
        ++itr5;
        GetItrValue(loctestnum, loctesterr, itr5, true, 25);

        lasd::BTPostOrderIterator<int> itr6(bst4);
        GetItrValue(loctestnum, loctesterr, itr6, true, 3);
        ++itr6;
        GetItrValue(loctestnum, loctesterr, itr6, true, 1);
        ++itr6;
        GetItrValue(loctestnum, loctesterr, itr6, true, 9);
        ++itr6;
        GetItrValue(loctestnum, loctesterr, itr6, true, 22);
        ++itr6;
        GetItrValue(loctestnum, loctesterr, itr6, true, 25);
        ++itr6;
        GetItrValue(loctestnum, loctesterr, itr6, true, 12);

        lasd::BTPreOrderIterator<int> itr7(bst4);
        GetItrValue(loctestnum, loctesterr, itr7, true, 12);
        ++itr7;
        GetItrValue(loctestnum, loctesterr, itr7, true, 9);
        ++itr7;
        GetItrValue(loctestnum, loctesterr, itr7, true, 1);
        ++itr7;
        GetItrValue(loctestnum, loctesterr, itr7, true, 3);
        ++itr7;
        GetItrValue(loctestnum, loctesterr, itr7, true, 25);
        ++itr7;
        GetItrValue(loctestnum, loctesterr, itr7, true, 22);

    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
    

void testBSTDouble(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BST<double> Test" << endl;

    try
    {
        lasd::BST<double> bst;
        Empty(loctestnum, loctesterr, bst, true);
        Size(loctestnum, loctesterr, bst, true, 0);

        InsertC(loctestnum, loctesterr, bst, true, 12.1);
        InsertC(loctestnum, loctesterr, bst, true, 5.3);
        InsertC(loctestnum, loctesterr, bst, true, 15.2);
        InsertC(loctestnum, loctesterr, bst, true, 3.9);
        InsertC(loctestnum, loctesterr, bst, true, 7.7);
        InsertC(loctestnum, loctesterr, bst, true, 13.5);
        InsertC(loctestnum, loctesterr, bst, true, 17.1);
        InsertC(loctestnum, loctesterr, bst, true, 1.4);
        InsertC(loctestnum, loctesterr, bst, true, 9.1);

        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<double>);
        Min(loctestnum, loctesterr, bst, true, 1.4);
        Max(loctestnum, loctesterr, bst, true, 17.1);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<double>);
        InsertC(loctestnum, loctesterr, bst, true, 19.2);
        InsertC(loctestnum, loctesterr, bst, true, 0.2);
        Size(loctestnum, loctesterr, bst, true, 11);
        Min(loctestnum, loctesterr, bst, true, 0.2);
        Max(loctestnum, loctesterr, bst, true, 19.2);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<double>);
        MinNRemove(loctestnum, loctesterr, bst, true, 0.2);
        MaxNRemove(loctestnum, loctesterr, bst, true, 19.2);
        Remove(loctestnum, loctesterr, bst, true, 7.7);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<double>);
        Exists(loctestnum, loctesterr, bst, false, 7.7);
        Exists(loctestnum, loctesterr, bst, true, 13.5);

        Successor(loctestnum, loctesterr, bst, false, 13.5, 19.2);
        Successor(loctestnum, loctesterr, bst, true, 13.5, 15.2);
        Predecessor(loctestnum, loctesterr, bst, true, 13.5, 12.1);
        Successor(loctestnum, loctesterr, bst, false, 12.1, 15.2);
        Successor(loctestnum, loctesterr, bst, true, 12.1, 13.5);
        Predecessor(loctestnum, loctesterr, bst, true, 12.1, 9.1);

        PredecessorNRemove(loctestnum, loctesterr, bst, true, 12.1, 9.1);
        SuccessorNRemove(loctestnum, loctesterr, bst, true, 12.1, 13.5);
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<double>);


        lasd::BST<double> copbst(bst);
        EqualBST(loctestnum, loctesterr, bst, copbst);

        Remove(loctestnum, loctesterr, copbst, true, 1.4);

        NonEqualBST(loctestnum, loctesterr, bst, copbst);

        InsertC(loctestnum, loctesterr, copbst, true, 1.4);

        EqualBST(loctestnum, loctesterr, bst, copbst);

        lasd::BST<double> movbst(move(copbst));
        EqualBST(loctestnum, loctesterr, bst, movbst);
        NonEqualBST(loctestnum, loctesterr, bst, copbst);
        Empty(loctestnum, loctesterr, copbst, true);
        Size(loctestnum, loctesterr, copbst, true, 0);

        lasd::BST<double> bst2 = copbst;
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
        TraverseBreadth(loctestnum, loctesterr, bst2, true, &TraversePrint<double>);
        TraverseBreadth(loctestnum, loctesterr, movbst, true, &TraversePrint<double>);

        lasd::List<double> lst;
        InsertAtBack(loctestnum, loctesterr, lst, true, 12.3);
        InsertAtBack(loctestnum, loctesterr, lst, true, 9.9);
        InsertAtBack(loctestnum, loctesterr, lst, true, 22.1);
        InsertAtBack(loctestnum, loctesterr, lst, true, 1.5);
        InsertAtBack(loctestnum, loctesterr, lst, true, 3.3);
        InsertAtBack(loctestnum, loctesterr, lst, true, 25.4);

        lasd::BST<double> bst3(lst);
        TraversePreOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<double>);
        TraverseInOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<double>);
        TraverseBreadth(loctestnum, loctesterr, bst3, true, &TraversePrint<double>);

        lasd::Vector<double> vec(6);
        SetAt(loctestnum, loctesterr, vec, true, 0, 12.3);
        SetAt(loctestnum, loctesterr, vec, true, 1, 9.9);
        SetAt(loctestnum, loctesterr, vec, true, 2, 25.4);
        SetAt(loctestnum, loctesterr, vec, true, 3, 1.5);
        SetAt(loctestnum, loctesterr, vec, true, 4, 3.3);
        SetAt(loctestnum, loctesterr, vec, true, 5, 22.1);

        lasd::BST<double> bst4(vec);
        TraversePreOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<double>);
        TraverseInOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<double>);
        TraverseBreadth(loctestnum, loctesterr, bst4, true, &TraversePrint<double>);

        EqualBST(loctestnum, loctesterr, bst3, bst4);

        lasd::BTBreadthIterator<double> itr4(bst4);
        GetItrValue(loctestnum, loctesterr, itr4, true, 12.3);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 9.9);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 25.4);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 1.5);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 22.1);
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, 3.3);

    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void testBSTString(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BST<string> Test" << endl;

    try
    {
        lasd::BST<string> bst;
        Empty(loctestnum, loctesterr, bst, true);
        Size(loctestnum, loctesterr, bst, true, 0);

        InsertC(loctestnum, loctesterr, bst, true, string("B"));
        InsertC(loctestnum, loctesterr, bst, true, string("C"));
        InsertC(loctestnum, loctesterr, bst, true, string("D"));
        InsertC(loctestnum, loctesterr, bst, true, string("E"));
        InsertC(loctestnum, loctesterr, bst, true, string("F"));
        InsertC(loctestnum, loctesterr, bst, true, string("G"));
        InsertC(loctestnum, loctesterr, bst, true, string("H"));
        InsertC(loctestnum, loctesterr, bst, true, string("I"));
        InsertC(loctestnum, loctesterr, bst, true, string("L"));

        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<string>);
        Min(loctestnum, loctesterr, bst, true, string("B"));
        Max(loctestnum, loctesterr, bst, true, string("L"));
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<string>);
        InsertC(loctestnum, loctesterr, bst, true, string("A"));
        InsertC(loctestnum, loctesterr, bst, true, string("M"));
        Size(loctestnum, loctesterr, bst, true, 11);
        Min(loctestnum, loctesterr, bst, true, string("A"));
        Max(loctestnum, loctesterr, bst, true, string("M"));
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<string>);
        MinNRemove(loctestnum, loctesterr, bst, true, string("A"));
        MaxNRemove(loctestnum, loctesterr, bst, true, string("M"));
        Remove(loctestnum, loctesterr, bst, true, string("F"));
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<string>);
        Exists(loctestnum, loctesterr, bst, false, string("F"));
        Exists(loctestnum, loctesterr, bst, true, string("E"));

        Successor(loctestnum, loctesterr, bst, false, string("D"), string("F"));
        Successor(loctestnum, loctesterr, bst, true, string("D"), string("E"));
        Predecessor(loctestnum, loctesterr, bst, true, string("D"), string("C"));
        Successor(loctestnum, loctesterr, bst, false, string("I"), string("I"));
        Successor(loctestnum, loctesterr, bst, true, string("E"), string("G"));
        Predecessor(loctestnum, loctesterr, bst, true, string("G"), string("E"));

        PredecessorNRemove(loctestnum, loctesterr, bst, true, string("D"), string("C"));
        SuccessorNRemove(loctestnum, loctesterr, bst, true, string("D"), string("E"));
        TraverseBreadth(loctestnum, loctesterr, bst, true, &TraversePrint<string>);


        lasd::BST<string> copbst(bst);
        EqualBST(loctestnum, loctesterr, bst, copbst);

        Remove(loctestnum, loctesterr, copbst, true, string("D"));

        NonEqualBST(loctestnum, loctesterr, bst, copbst);

        InsertC(loctestnum, loctesterr, copbst, true, string("D"));

        EqualBST(loctestnum, loctesterr, bst, copbst);

        lasd::BST<string> movbst(move(copbst));
        EqualBST(loctestnum, loctesterr, bst, movbst);
        NonEqualBST(loctestnum, loctesterr, bst, copbst);
        Empty(loctestnum, loctesterr, copbst, true);
        Size(loctestnum, loctesterr, copbst, true, 0);

        lasd::BST<string> bst2 = copbst;
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
        TraverseBreadth(loctestnum, loctesterr, bst2, true, &TraversePrint<string>);
        TraverseBreadth(loctestnum, loctesterr, movbst, true, &TraversePrint<string>);

        lasd::List<string> lst;
        InsertAtBack(loctestnum, loctesterr, lst, true, string("L"));
        InsertAtBack(loctestnum, loctesterr, lst, true, string("D"));
        InsertAtBack(loctestnum, loctesterr, lst, true, string("O"));
        InsertAtBack(loctestnum, loctesterr, lst, true, string("E"));
        InsertAtBack(loctestnum, loctesterr, lst, true, string("A"));
        InsertAtBack(loctestnum, loctesterr, lst, true, string("M"));

        lasd::BST<string> bst3(lst);
        TraversePreOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<string>);
        TraverseInOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, bst3, true, &TraversePrint<string>);
        TraverseBreadth(loctestnum, loctesterr, bst3, true, &TraversePrint<string>);

        lasd::Vector<string> vec(6);
        SetAt(loctestnum, loctesterr, vec, true, 0, string("D"));
        SetAt(loctestnum, loctesterr, vec, true, 1, string("M"));
        SetAt(loctestnum, loctesterr, vec, true, 2, string("O"));
        SetAt(loctestnum, loctesterr, vec, true, 3, string("E"));
        SetAt(loctestnum, loctesterr, vec, true, 4, string("A"));
        SetAt(loctestnum, loctesterr, vec, true, 5, string("L"));

        lasd::BST<string> bst4(vec);
        TraversePreOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<string>);
        TraverseInOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, bst4, true, &TraversePrint<string>);
        TraverseBreadth(loctestnum, loctesterr, bst4, true, &TraversePrint<string>);

        EqualBST(loctestnum, loctesterr, bst3, bst4);

        lasd::BTBreadthIterator<string> itr4(bst4);
        GetItrValue(loctestnum, loctesterr, itr4, true, string("D"));
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, string("A"));
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, string("M"));
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, string("E"));
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, string("O"));
        ++itr4;
        GetItrValue(loctestnum, loctesterr, itr4, true, string("L"));

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
    testBSTDouble(loctestnum, loctesterr);
    testBSTString(loctestnum, loctesterr);


    cout << "-------------------------------------------------------------------------------" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
