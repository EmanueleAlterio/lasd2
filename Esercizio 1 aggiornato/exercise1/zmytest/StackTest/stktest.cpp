#include <iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"

using namespace std;

template <typename Stk>
void testStackInt(Stk & stk, uint & testnum, uint & testerr) {

    uint loctestnum = 0, loctesterr = 0;
    try
    {
        Empty(loctestnum, loctesterr, stk, true);
        PushC(loctestnum, loctesterr, stk, 1);
        PushC(loctestnum, loctesterr, stk, 2);
        PushC(loctestnum, loctesterr, stk, 3);
        PushC(loctestnum, loctesterr, stk, 4);
        PushC(loctestnum, loctesterr, stk, 5);
        PushC(loctestnum, loctesterr, stk, 6);
        PushC(loctestnum, loctesterr, stk, 7);
        Empty(loctestnum, loctesterr, stk, false);
        Pop(loctestnum, loctesterr, stk, true);
        Top(loctestnum, loctesterr, stk, false, 7);
        Top(loctestnum, loctesterr, stk, true, 6);
        TopNPop(loctestnum, loctesterr, stk, true, 6);


        cout << endl << "stack con specific constructor(copy)" << endl;
        Stk copstk(stk);
        EqualStack(loctestnum, loctesterr, stk, copstk, true);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, false);

        TopNPop(loctestnum, loctesterr, stk, true, 5);
        
        EqualStack(loctestnum, loctesterr, stk, copstk, false);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, true);


        cout << endl << "stack con specific constructor(move)" << endl;
        Stk movstk(move(stk));
        Stk movs2(move(copstk));

        Empty(loctestnum, loctesterr, stk, true);
        EqualStack(loctestnum, loctesterr, stk, movstk, false);
        EqualStack(loctestnum, loctesterr, copstk, movs2, false);



    }
    catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Errore!" << endl;
    }
  
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    
}


template <typename Stk>
void testStackDouble(Stk & stk, uint & testnum, uint & testerr) {

    uint loctestnum = 0, loctesterr = 0;
    try
    {
        Empty(loctestnum, loctesterr, stk, true);
        PushC(loctestnum, loctesterr, stk, 1.3);
        PushC(loctestnum, loctesterr, stk, 2.7);
        PushC(loctestnum, loctesterr, stk, 3.4);
        PushC(loctestnum, loctesterr, stk, 4.7);
        PushC(loctestnum, loctesterr, stk, 5.9);
        PushC(loctestnum, loctesterr, stk, 6.4);
        PushC(loctestnum, loctesterr, stk, 7.1);
        Empty(loctestnum, loctesterr, stk, false);
        Pop(loctestnum, loctesterr, stk, true);
        Top(loctestnum, loctesterr, stk, false, 7.1);
        Top(loctestnum, loctesterr, stk, true, 6.4);
        TopNPop(loctestnum, loctesterr, stk, true, 6.4);


        cout << endl << "stack con specific constructor(copy)" << endl;
        Stk copstk(stk);
        EqualStack(loctestnum, loctesterr, stk, copstk, true);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, false);

        TopNPop(loctestnum, loctesterr, stk, true, 5.9);
        
        EqualStack(loctestnum, loctesterr, stk, copstk, false);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, true);


        cout << endl << "stack con specific constructor(move)" << endl;
        Stk movstk(move(stk));

        Empty(loctestnum, loctesterr, stk, true);
        EqualStack(loctestnum, loctesterr, stk, movstk, false);
        EqualStack(loctestnum, loctesterr, copstk, movstk, false);



    }
    catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Errore!" << endl;
    }
  
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    
}



template <typename Stk>
void testStackString(Stk & stk, uint & testnum, uint & testerr) {

    uint loctestnum = 0, loctesterr = 0;
    try
    {
        Empty(loctestnum, loctesterr, stk, true);
        PushC(loctestnum, loctesterr, stk, string("A"));
        PushC(loctestnum, loctesterr, stk, string("B"));
        PushC(loctestnum, loctesterr, stk, string("C"));
        PushC(loctestnum, loctesterr, stk, string("D"));
        PushC(loctestnum, loctesterr, stk, string("E"));
        PushC(loctestnum, loctesterr, stk, string("F"));
        PushC(loctestnum, loctesterr, stk, string("G"));
        Empty(loctestnum, loctesterr, stk, false);
        Pop(loctestnum, loctesterr, stk, true);
        Top(loctestnum, loctesterr, stk, false, string("G"));
        Top(loctestnum, loctesterr, stk, true, string("F"));
        TopNPop(loctestnum, loctesterr, stk, true, string("F"));


        cout << endl << "stack con specific constructor(copy)" << endl;
        Stk copstk(stk);
        EqualStack(loctestnum, loctesterr, stk, copstk, true);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, false);

        TopNPop(loctestnum, loctesterr, stk, true, string("E"));
        
        EqualStack(loctestnum, loctesterr, stk, copstk, false);
        NonEqualStack(loctestnum, loctesterr, stk, copstk, true);


        cout << endl << "stack con specific constructor(move)" << endl;
        Stk movstk(move(stk));

        Empty(loctestnum, loctesterr, stk, true);
        EqualStack(loctestnum, loctesterr, stk, movstk, false);
        EqualStack(loctestnum, loctesterr, copstk, movstk, false);



    }
    catch (...) {
        loctestnum++; loctesterr++;
        cout << endl << "Errore!" << endl;
    }
  
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    
}


void StackTest(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    cout << endl << endl << "Inizio Test Stack" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    cout << endl << "~~~STACKVEC<INT>~~~" << endl;
    lasd::StackVec<int> stackvecint;
    testStackInt(stackvecint, loctestnum, loctesterr);

    cout << endl << "~~~STACKVEC<DOUBLE>~~~" << endl;
    lasd::StackVec<double> stackvecdouble;
    testStackDouble(stackvecdouble, loctestnum, loctesterr);

    cout << endl << "~~~STACKVEC<STRING>~~~" << endl;
    lasd::StackVec<string> stackvecstr;
    testStackString(stackvecstr, loctestnum, loctesterr);

    cout << endl << "~~~STACKLIST<INT>~~~" << endl;
    lasd::StackLst<int> stacklstint;
    testStackInt(stacklstint, loctestnum, loctesterr);

    cout << endl << "~~~STACKLIST<DOUBLE>~~~" << endl;
    lasd::StackLst<double> stacklstdouble;
    testStackDouble(stacklstdouble, loctestnum, loctesterr);

    cout << endl << "~~~STACKLIST<STRING>~~~" << endl;
    lasd::StackLst<string> stacklststr;
    testStackString(stacklststr, loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Fine Test Stack";
    cout << endl << "Errori: " << loctesterr << " Test: " << loctestnum << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
}