#include<iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/iterator/iterator.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

using namespace std;

void testBinaryTreeInt(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BinaryTree<int> Test" << endl;
    try {
        lasd::Vector<int> vec(9);
        SetAt(loctestnum, loctesterr, vec, true, 0, 1);
        SetAt(loctestnum, loctesterr, vec, true, 1, 2);
        SetAt(loctestnum, loctesterr, vec, true, 2, 3);
        SetAt(loctestnum, loctesterr, vec, true, 3, 4);
        SetAt(loctestnum, loctesterr, vec, true, 4, 5);
        SetAt(loctestnum, loctesterr, vec, true, 5, 6);
        SetAt(loctestnum, loctesterr, vec, true, 6, 7);
        SetAt(loctestnum, loctesterr, vec, true, 7, 8);
        SetAt(loctestnum, loctesterr, vec, true, 8, 9);

        
        lasd::BinaryTreeVec<int> btvec(vec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);
        TraverseBreadth(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);
        Size(loctestnum, loctesterr, btvec, true, 9);
        Fold(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 45);
        FoldPreOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 45);
        FoldPostOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 45);
        FoldInOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 45);
        FoldBreadth(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 45);
        lasd::BinaryTreeVec<int> copbtvec(btvec);
        EqualBT(loctestnum, loctesterr, copbtvec, btvec);
        Root(loctestnum, loctesterr, copbtvec, true, 1);
        Root(loctestnum, loctesterr, btvec, true, 1);
        Traverse(loctestnum, loctesterr, copbtvec, true, &TraversePrint<int>);
        copbtvec.Clear();
        NonEqualBT(loctestnum, loctesterr, copbtvec, btvec);
        lasd::BinaryTreeVec<int> movbtvec(move(btvec));
        NonEqualBT(loctestnum, loctesterr, movbtvec, btvec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<int>);




    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void testBinaryTreeDouble(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BinaryTree<double> Test" << endl;
    try {
        lasd::Vector<double> vec(9);
        SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
        SetAt(loctestnum, loctesterr, vec, true, 1, 1.2);
        SetAt(loctestnum, loctesterr, vec, true, 2, 2.0);
        SetAt(loctestnum, loctesterr, vec, true, 3, 1.4);
        SetAt(loctestnum, loctesterr, vec, true, 4, 1.5);
        SetAt(loctestnum, loctesterr, vec, true, 5, 1.6);
        SetAt(loctestnum, loctesterr, vec, true, 6, 1.1);
        SetAt(loctestnum, loctesterr, vec, true, 7, 1.3);
        SetAt(loctestnum, loctesterr, vec, true, 8, 1.4);

        

        cout << endl << "Begin of BinaryTreeVec<double> Test:" << endl;
        lasd::BinaryTreeVec<double> btvec(vec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        TraversePreOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        TraversePostOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        TraverseInOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        TraverseBreadth(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        Size(loctestnum, loctesterr, btvec, true, 9);
        Fold(loctestnum, loctesterr, btvec, true, &FoldAdd<double>, 0.0, 12.6);
        FoldPreOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<double>, 0.0, 12.6);
        FoldPostOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<double>, 0.0, 12.6);
        FoldInOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<double>, 0.0, 12.6);
        FoldBreadth(loctestnum, loctesterr, btvec, true, &FoldAdd<double>, 0.0, 12.6);
        lasd::BinaryTreeVec<double> copbtvec(btvec);
        EqualBT(loctestnum, loctesterr, copbtvec, btvec);
        Root(loctestnum, loctesterr, copbtvec, true, 1.1);
        Root(loctestnum, loctesterr, btvec, true, 1.1);
        Traverse(loctestnum, loctesterr, copbtvec, true, &TraversePrint<double>);
        copbtvec.Clear();
        NonEqualBT(loctestnum, loctesterr, copbtvec, btvec);
        lasd::BinaryTreeVec<double> movbtvec(move(btvec));
        NonEqualBT(loctestnum, loctesterr, movbtvec, btvec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<double>);
        



    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void testBinaryTreeString(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of BinaryTree<string> Test" << endl;
    try {
        lasd::Vector<string> vec(9);
        SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
        SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
        SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
        SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
        SetAt(loctestnum, loctesterr, vec, true, 4, string("E"));
        SetAt(loctestnum, loctesterr, vec, true, 5, string("F"));
        SetAt(loctestnum, loctesterr, vec, true, 6, string("G"));
        SetAt(loctestnum, loctesterr, vec, true, 7, string("H"));
        SetAt(loctestnum, loctesterr, vec, true, 8, string("I"));

        

        cout << endl << "Begin of BinaryTreeVec<string> Test:" << endl;
        lasd::BinaryTreeVec<string> btvec(vec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        TraversePreOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        TraversePostOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        TraverseInOrder(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        TraverseBreadth(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        Size(loctestnum, loctesterr, btvec, true, 9);
        Fold(loctestnum, loctesterr, btvec, true, &FoldAdd<string>, string("?"), string("?ABDHIECFG"));
        FoldPreOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<string>, string("?"), string("?ABDHIECFG"));
        FoldPostOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<string>, string("?"), string("?HIDEBFGCA"));
        FoldInOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<string>, string("?"), string("?HDIBEAFCG"));
        FoldBreadth(loctestnum, loctesterr, btvec, true, &FoldAdd<string>, string("?"), string("?ABCDEFGHI"));
        lasd::BinaryTreeVec<string> copbtvec(btvec);
        EqualBT(loctestnum, loctesterr, copbtvec, btvec);
        Root(loctestnum, loctesterr, copbtvec, true, string("A"));
        Root(loctestnum, loctesterr, btvec, true, string("A"));
        Traverse(loctestnum, loctesterr, copbtvec, true, &TraversePrint<string>);
        copbtvec.Clear();
        NonEqualBT(loctestnum, loctesterr, copbtvec, btvec);
        lasd::BinaryTreeVec<string> movbtvec(move(btvec));
        NonEqualBT(loctestnum, loctesterr, movbtvec, btvec);
        Traverse(loctestnum, loctesterr, btvec, true, &TraversePrint<string>);
        



    }catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void BinaryTreeTest(unsigned int & testnum, unsigned int & testerr){
    unsigned int loctestnum = 0;
    unsigned int loctesterr = 0;

    cout << endl << "Inizio Test BinaryTree" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    testBinaryTreeInt(loctestnum, loctesterr);
    testBinaryTreeDouble(loctestnum, loctesterr);
    testBinaryTreeString(loctestnum, loctesterr);


    cout << "-------------------------------------------------------------------------------" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
