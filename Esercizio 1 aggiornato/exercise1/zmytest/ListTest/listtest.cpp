#include<iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"

using namespace std;

void testListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Inizio List<int> Test:" << endl;
  try {
    {
      lasd::List<int> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);

      GetFront(loctestnum, loctesterr, lst, false, 0);
      GetBack(loctestnum, loctesterr, lst, false, 0);

      Exists(loctestnum, loctesterr, lst, false, 0);

      InsertAtFront(loctestnum, loctesterr, lst, true, 2);
      InsertAtBack(loctestnum, loctesterr, lst, true, 3);
      InsertAtFront(loctestnum, loctesterr, lst, true, 1);

      Size(loctestnum, loctesterr, lst, true, 3);

      GetFront(loctestnum, testerr, lst, true, 1);
      GetBack(loctestnum, testerr, lst, true, 3);

      Exists(loctestnum, loctesterr, lst, true, 1);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);

      GetAt(loctestnum, loctesterr, lst, false, 2, 4);
      GetAt(loctestnum, loctesterr, lst, true, 2, 3);
      GetAt(loctestnum, loctesterr, lst, false, 3, 1);

      SetAt(loctestnum, loctesterr, lst, true, 2, 10);
      SetAt(loctestnum, loctesterr, lst, false, 3, 4);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, false);
      Empty(loctestnum, loctesterr, lst, true);
    }
    {
      lasd::List<int> lst;
      InsertAtFront(loctestnum, loctesterr, lst, true, 1);
      InsertAtFront(loctestnum, loctesterr, lst, true, 2);
      InsertAtFront(loctestnum, loctesterr, lst, true, 3);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);


      cout << endl << "<<specific constructor(copy)>>" << endl;
      lasd::List<int> coplist(lst);
      EqualList(loctestnum, loctesterr, lst, coplist, true);
      Size(loctestnum, loctesterr, lst, true, 3);
      InsertAtFront(loctestnum, loctesterr, lst, true, 4);
      EqualList(loctestnum, loctesterr, lst, coplist, false);
      NonEqualList(loctestnum, loctesterr, lst, coplist, true);
      FrontNRemove(loctestnum, loctesterr, lst, true, 4);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<int>);


      cout << endl << "<<specific constructor(move)>>" << endl;
      lasd::List<int> movlist(move(lst));
      EqualList(loctestnum, loctesterr, lst, movlist, false);
      EqualList(loctestnum, loctesterr, movlist, coplist, true);

      cout << endl << "<<specific constructor(list from vector)>>" << endl;
      lasd::Vector<int> vec(5);

      SetAt(loctestnum, loctesterr, vec, true, 0, 1);
      SetAt(loctestnum, loctesterr, vec, true, 1, 2);
      SetAt(loctestnum, loctesterr, vec, true, 2, 3);
      SetAt(loctestnum, loctesterr, vec, true, 3, 4);
      SetAt(loctestnum, loctesterr, vec, true, 4, 5);

      lasd::List<int> veclist(vec);
      EqualLinear(loctestnum, loctesterr, vec, veclist, true);
      
      cout << endl << "<<Implementazione lista con dictionary (copy)>>" << endl;
      lasd::List<int> dictionary;
      InsertC(loctestnum ,loctesterr, dictionary, true, 10);
      InsertC(loctestnum ,loctesterr, dictionary, true, 11);
      InsertC(loctestnum ,loctesterr, dictionary, true, 12);
      InsertC(loctestnum ,loctesterr, dictionary, false, 10);

      InsertAllC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<int>);

      InsertSomeC(loctestnum, loctesterr, coplist, false, dictionary);
      InsertC(loctestnum ,loctesterr, dictionary, true, 4);
      InsertSomeC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<int>);

      lasd::List<int> lst2;
      cout << endl << "<<Implementazione lista con dictionary (move)>>" << endl;
      InsertAllM(loctestnum, loctesterr, lst2, true, move(dictionary));
      TraversePreOrder(loctestnum, loctesterr, lst2, true, &TraversePrint<int>);
      dictionary.Clear();
      Empty(loctestnum, loctesterr, dictionary, true);

    }


  }catch (...){
    loctestnum++; loctesterr++;
    cout << endl << "Errore!" << endl;
  }
    
    testnum += loctestnum;
    testerr += loctesterr;

    cout << endl <<  "Fine List<int> Test!" ;
    cout << endl<< "Errori: "<< loctesterr << " Test: " << loctestnum << endl;

}


void testListDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Inizio List<double> Test:" << endl;
  try {
    {
      lasd::List<double> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);

      GetFront(loctestnum, loctesterr, lst, false, 0.0);
      GetBack(loctestnum, loctesterr, lst, false, 0.0);

      Exists(loctestnum, loctesterr, lst, false, 0.0);

      InsertAtFront(loctestnum, loctesterr, lst, true, 2.5);
      InsertAtBack(loctestnum, loctesterr, lst, true, 3.5);
      InsertAtFront(loctestnum, loctesterr, lst, true, 1.5);

      Size(loctestnum, loctesterr, lst, true, 3);

      GetFront(loctestnum, testerr, lst, true, 1.5);
      GetBack(loctestnum, testerr, lst, true, 3.5);

      Exists(loctestnum, loctesterr, lst, true, 1.5);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);

      GetAt(loctestnum, loctesterr, lst, false, 2, 4.0);
      GetAt(loctestnum, loctesterr, lst, true, 2, 3.5);
      GetAt(loctestnum, loctesterr, lst, false, 3, 1.0);

      SetAt(loctestnum, loctesterr, lst, true, 2, 10.0);
      SetAt(loctestnum, loctesterr, lst, false, 3, 4.5);

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, false);
      Empty(loctestnum, loctesterr, lst, true);
    }
    {
      lasd::List<double> lst;
      InsertAtFront(loctestnum, loctesterr, lst, true, 1.5);
      InsertAtFront(loctestnum, loctesterr, lst, true, 2.5);
      InsertAtFront(loctestnum, loctesterr, lst, true, 3.5);
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<double>);


      cout << endl << "<<specific constructor(copy)>>" << endl;
      lasd::List<double> coplist(lst);
      EqualList(loctestnum, loctesterr, lst, coplist, true);
      Size(loctestnum, loctesterr, lst, true, 3);
      InsertAtFront(loctestnum, loctesterr, lst, true, 4.5);
      EqualList(loctestnum, loctesterr, lst, coplist, false);
      NonEqualList(loctestnum, loctesterr, lst, coplist, true);
      FrontNRemove(loctestnum, loctesterr, lst, true, 4.5);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<double>);


      cout << endl << "<<specific constructor(move)>>" << endl;
      lasd::List<double> movlist(move(lst));
      EqualList(loctestnum, loctesterr, lst, movlist, false);
      EqualList(loctestnum, loctesterr, movlist, coplist, true);

      cout << endl << "<<specific constructor(list from vector)>>" << endl;
      lasd::Vector<double> vec(5);

      SetAt(loctestnum, loctesterr, vec, true, 0, 1.5);
      SetAt(loctestnum, loctesterr, vec, true, 1, 2.5);
      SetAt(loctestnum, loctesterr, vec, true, 2, 3.5);
      SetAt(loctestnum, loctesterr, vec, true, 3, 4.5);
      SetAt(loctestnum, loctesterr, vec, true, 4, 5.5);

      lasd::List<double> veclist(vec);
      EqualLinear(loctestnum, loctesterr, vec, veclist, true);
      
      cout << endl << "<<Implementazione lista con dictionary (copy)>>" << endl;
      lasd::List<double> dictionary;
      InsertC(loctestnum ,loctesterr, dictionary, true, 10.3);
      InsertC(loctestnum ,loctesterr, dictionary, true, 11.4);
      InsertC(loctestnum ,loctesterr, dictionary, true, 12.2);
      InsertC(loctestnum ,loctesterr, dictionary, false, 10.3);

      InsertAllC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<double>);

      InsertSomeC(loctestnum, loctesterr, coplist, false, dictionary);
      InsertC(loctestnum ,loctesterr, dictionary, true, 4.7);
      InsertSomeC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<double>);

      lasd::List<double> lst2;
      cout << endl << "<<Implementazione lista con dictionary (move)>>" << endl;
      InsertAllM(loctestnum, loctesterr, lst2, true, move(dictionary));
      TraversePreOrder(loctestnum, loctesterr, lst2, true, &TraversePrint<double>);
      dictionary.Clear();
      Empty(loctestnum, loctesterr, dictionary, true);

    }


  }catch (...){
    loctestnum++; loctesterr++;
    cout << endl << "Errore!" << endl;
  }
    
    testnum += loctestnum;
    testerr += loctesterr;

    cout << endl <<  "Fine List<double> Test!" ;
    cout << endl<< "Errori: "<< loctesterr << " Test: " << loctestnum << endl;

}

void testListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Inizio List<string> Test:" << endl;
  try {
    {
      lasd::List<string> lst;
      Empty(loctestnum, loctesterr, lst, true);
      Size(loctestnum, loctesterr, lst, true, 0);

      GetFront(loctestnum, loctesterr, lst, false, string("A"));
      GetBack(loctestnum, loctesterr, lst, false, string("A"));

      Exists(loctestnum, loctesterr, lst, false, string("A"));

      InsertAtFront(loctestnum, loctesterr, lst, true, string("B"));
      InsertAtBack(loctestnum, loctesterr, lst, true, string("C"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("A"));

      Size(loctestnum, loctesterr, lst, true, 3);

      GetFront(loctestnum, testerr, lst, true, string("A"));
      GetBack(loctestnum, testerr, lst, true, string("C"));

      Exists(loctestnum, loctesterr, lst, true, string("B"));
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);

      GetAt(loctestnum, loctesterr, lst, false, 2, string("F"));
      GetAt(loctestnum, loctesterr, lst, true, 2, string("C"));
      GetAt(loctestnum, loctesterr, lst, false, 3, string("A"));

      SetAt(loctestnum, loctesterr, lst, true, 2, string("Z"));
      SetAt(loctestnum, loctesterr, lst, false, 3, string("L"));

      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, true);
      RemoveFromFront(loctestnum, loctesterr, lst, false);
      Empty(loctestnum, loctesterr, lst, true);
    }
    {
      lasd::List<string> lst;
      InsertAtFront(loctestnum, loctesterr, lst, true, string("C"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("B"));
      InsertAtFront(loctestnum, loctesterr, lst, true, string("A"));
      TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<string>);


      cout << endl << "<<specific constructor(copy)>>" << endl;
      lasd::List<string> coplist(lst);
      EqualList(loctestnum, loctesterr, lst, coplist, true);
      Size(loctestnum, loctesterr, lst, true, 3);
      InsertAtFront(loctestnum, loctesterr, lst, true, string("M"));
      EqualList(loctestnum, loctesterr, lst, coplist, false);
      NonEqualList(loctestnum, loctesterr, lst, coplist, true);
      FrontNRemove(loctestnum, loctesterr, lst, true, string("M"));
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<string>);


      cout << endl << "<<specific constructor(move)>>" << endl;
      lasd::List<string> movlist(move(lst));
      EqualList(loctestnum, loctesterr, lst, movlist, false);
      EqualList(loctestnum, loctesterr, movlist, coplist, true);

      cout << endl << "<<specific constructor(list from vector)>>" << endl;
      lasd::Vector<string> vec(5);

      SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("E"));

      lasd::List<string> veclist(vec);
      EqualLinear(loctestnum, loctesterr, vec, veclist, true);
      
      cout << endl << "<<Implementazione lista con dictionary (copy)>>" << endl;
      lasd::List<string> dictionary;
      InsertC(loctestnum ,loctesterr, dictionary, true, string("T"));
      InsertC(loctestnum ,loctesterr, dictionary, true, string("Y"));
      InsertC(loctestnum ,loctesterr, dictionary, true, string("H"));
      InsertC(loctestnum ,loctesterr, dictionary, false, string("T"));

      InsertAllC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<string>);

      InsertSomeC(loctestnum, loctesterr, coplist, false, dictionary);
      InsertC(loctestnum ,loctesterr, dictionary, true, string("Z"));
      InsertSomeC(loctestnum, loctesterr, coplist, true, dictionary);
      TraversePreOrder(loctestnum, loctesterr, coplist, true, &TraversePrint<string>);

      lasd::List<string> lst2;
      cout << endl << "<<Implementazione lista con dictionary (move)>>" << endl;
      InsertAllM(loctestnum, loctesterr, lst2, true, move(dictionary));
      TraversePreOrder(loctestnum, loctesterr, lst2, true, &TraversePrint<string>);
      dictionary.Clear();
      Empty(loctestnum, loctesterr, dictionary, true);

    }


  }catch (...){
    loctestnum++; loctesterr++;
    cout << endl << "Errore!" << endl;
  }
    
    testnum += loctestnum;
    testerr += loctesterr;

    cout << endl <<  "Fine List<int> Test!" ;
    cout << endl<< "Errori: "<< loctesterr << " Test: " << loctestnum << endl;

}


void ListTest(uint & testnum, uint & testerr){
    cout << endl << "Inizio Test Lista" << endl << endl;
    uint loctestnum = 0, loctesterr = 0;
    testListInt(loctestnum, loctesterr);
    testListDouble(loctestnum, loctesterr);
    testListString(loctestnum, loctesterr);

    cout << endl << "Fine test Lista";
    cout << endl << "Errori: " << loctesterr << " Test: " << loctestnum << endl;

    testnum += loctestnum;
    testerr += loctesterr;
}