#include <iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"

using namespace std;

void testVectorInt(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;

    try{
        {
            lasd::Vector<int> vec;
            Empty(loctestnum, loctesterr, vec, true);
            SetAt(loctestnum, loctesterr, vec, false, 0, 1);
            GetFront(loctestnum, loctesterr, vec, false, 1);
            GetBack(loctestnum, loctesterr, vec, false, 5);
            Exists(loctestnum, loctesterr, vec, false, 4);
        }
        {
            cout << endl << "<<Creazione di un vettore con specific constructor(size = 3).>>" << endl;
            lasd::Vector<int> vec(3);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 3);
            Size(loctestnum, loctesterr, vec, false, 4);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 3);
            SetAt(loctestnum, loctesterr, vec, false, 3, 4);
            GetFront(loctestnum, loctesterr, vec, false, 2);
            GetFront(loctestnum, loctesterr, vec, true, 1);
            GetBack(loctestnum, loctesterr, vec, false, 5);
            GetBack(loctestnum, loctesterr, vec, true, 3);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 6);
            FoldPreOrder(loctestnum, loctesterr, vec, false, &FoldAdd<int>, 0, 3);
            vec.Resize(1);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 1);
            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            vec.Resize(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 3);

            cout << endl << "<<specific constructor(copy)>>" << endl;
            lasd::Vector<int> copvec(vec);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

            EqualVector(loctestnum, loctesterr, vec, copvec, true);
            SetAt(loctestnum, loctesterr, copvec, true, 2, 10);
            EqualVector(loctestnum, loctesterr, vec, copvec, false);
        }
        {
            lasd::Vector<int> vec(2);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 2);

            cout << endl << "<<specific constructor(move)>>" << endl;
            lasd::Vector<int> copvec(vec);
            lasd::Vector<int> movvec(move(vec));
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
            EqualVector(loctestnum, loctesterr, vec, movvec, false);
            EqualVector(loctestnum, loctesterr, movvec, copvec, true);
            movvec.Clear();
            Size(loctestnum, loctesterr, movvec, true, 0);


        }
    }catch(...){
            loctestnum++; loctesterr++;
            cout << endl << "Errore!" << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void testVectorDouble(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;

    try{
        {
            lasd::Vector<double> vec;
            Empty(loctestnum, loctesterr, vec, true);
            SetAt(loctestnum, loctesterr, vec, false, 0, 1.1);
            GetFront(loctestnum, loctesterr, vec, false, 1.2);
            GetBack(loctestnum, loctesterr, vec, false, 5.1);
            Exists(loctestnum, loctesterr, vec, false, 4.2);
        }
        {
            cout << endl << "<<Creazione di un vettore con specific constructor(size = 3).>>" << endl;
            lasd::Vector<double> vec(3);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 3);
            Size(loctestnum, loctesterr, vec, false, 4);
            SetAt(loctestnum, loctesterr, vec, true, 0, 5.5);
            SetAt(loctestnum, loctesterr, vec, true, 1, 3.5);
            SetAt(loctestnum, loctesterr, vec, true, 2, 2.5);
            SetAt(loctestnum, loctesterr, vec, false, 3, 4.0);
            GetFront(loctestnum, loctesterr, vec, false, 2.0);
            GetFront(loctestnum, loctesterr, vec, true, 5.5);
            GetBack(loctestnum, loctesterr, vec, false, 5.0);
            GetBack(loctestnum, loctesterr, vec, true, 2.5);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0 , 11.5 );
            FoldPreOrder(loctestnum, loctesterr, vec, false, &FoldAdd<double>, 0.0 , 3.0 );
            vec.Resize(1);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 1);
            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            vec.Resize(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 1.2);
            SetAt(loctestnum, loctesterr, vec, true, 2, 1.3);

            cout << endl << "<<specific constructor(copy)>>" << endl;
            lasd::Vector<double> copvec(vec);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

            EqualVector(loctestnum, loctesterr, vec, copvec, true);
            SetAt(loctestnum, loctesterr, copvec, true, 2, 10.5);
            EqualVector(loctestnum, loctesterr, vec, copvec, false);
        }
        {
            lasd::Vector<double> vec(2);
            SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);
            SetAt(loctestnum, loctesterr, vec, true, 1, 1.2);

            cout << endl << "<<specific constructor(move)>>" << endl;
            lasd::Vector<double> copvec(vec);
            lasd::Vector<double> movvec(move(vec));
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
            EqualVector(loctestnum, loctesterr, vec, movvec, false);
            EqualVector(loctestnum, loctesterr, movvec, copvec, true);
            movvec.Clear();
            Size(loctestnum, loctesterr, movvec, true, 0);


        }
    }catch(...){
            loctestnum++; loctesterr++;
            cout << endl << "Errore!" << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void testVectorString(uint & testnum, uint & testerr) {
    uint loctestnum = 0, loctesterr = 0;

    try{
        {
            lasd::Vector<string> vec;
            Empty(loctestnum, loctesterr, vec, true);
            SetAt(loctestnum, loctesterr, vec, false, 0, string("A"));
            GetFront(loctestnum, loctesterr, vec, false, string("A"));
            GetBack(loctestnum, loctesterr, vec, false, string("A"));
            Exists(loctestnum, loctesterr, vec, false, string("A"));
        }
        {
            cout << endl << "<<Creazione di un vettore con specific constructor(size = 3).>>" << endl;
            lasd::Vector<string> vec(3);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 3);
            Size(loctestnum, loctesterr, vec, false, 4);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
            SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
            SetAt(loctestnum, loctesterr, vec, false, 3, string("D"));
            GetFront(loctestnum, loctesterr, vec, false, string("B"));
            GetFront(loctestnum, loctesterr, vec, true, string("A"));
            GetBack(loctestnum, loctesterr, vec, false, string("D"));
            GetBack(loctestnum, loctesterr, vec, true, string("C"));
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<string>, string("?") , string("?ABC") );
            FoldPreOrder(loctestnum, loctesterr, vec, false, &FoldAdd<string>, string("?") , string("ABC") );
            vec.Resize(1);
            Empty(loctestnum, loctesterr, vec, false);
            Size(loctestnum, loctesterr, vec, true, 1);
            vec.Resize(0);
            Empty(loctestnum, loctesterr, vec, true);
            vec.Resize(3);
            SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
            SetAt(loctestnum, loctesterr, vec, true, 1, string("A"));
            SetAt(loctestnum, loctesterr, vec, true, 2,  string("A"));

            cout << endl << "<<specific constructor(copy)>>" << endl;
            lasd::Vector<string> copvec(vec);
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

            EqualVector(loctestnum, loctesterr, vec, copvec, true);
            SetAt(loctestnum, loctesterr, copvec, true, 2, string("C"));
            EqualVector(loctestnum, loctesterr, vec, copvec, false);
        }
        {
            lasd::Vector<string> vec(2);
            SetAt(loctestnum, loctesterr, vec, true, 0,  string("N"));
            SetAt(loctestnum, loctesterr, vec, true, 1,  string("A"));

            cout << endl << "<<specific constructor(move)>>" << endl;
            lasd::Vector<string> copvec(vec);
            lasd::Vector<string> movvec(move(vec));
            TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
            EqualVector(loctestnum, loctesterr, vec, movvec, false);
            EqualVector(loctestnum, loctesterr, movvec, copvec, true);
            movvec.Clear();
            Size(loctestnum, loctesterr, movvec, true, 0);

        }
    }catch(...){
            loctestnum++; loctesterr++;
            cout << endl << "Errore!" << endl;
    }


    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void VectorTest(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    cout << endl << "Inizio Test Vettori" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    cout << endl << "~~~VECTOR<INT>~~~" << endl;
    testVectorInt(loctestnum, loctesterr);

    cout << endl << "~~~VECTOR<DOUBLE>~~~" << endl;
    testVectorDouble(loctestnum, loctesterr);

    cout << endl << "~~~VECTOR<STRING>~~~" << endl;
    testVectorString(loctestnum, loctesterr);
    testnum += loctestnum;
    testerr += loctesterr;

    cout << endl << "Fine Test Vettori";
    cout << endl << "Errori: " << loctesterr << " Test: " << loctestnum << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

}