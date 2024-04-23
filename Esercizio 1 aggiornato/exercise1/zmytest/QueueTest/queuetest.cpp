#include <iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"

using namespace std;

template <typename Que>
void testQueueInt(Que & que, uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    try
    {
        Empty(loctestnum, loctesterr, que, true);
        Size(loctestnum, loctesterr, que, true, 0);

        EnqueueC(loctestnum, loctesterr, que, 1);
        EnqueueC(loctestnum, loctesterr, que, 2);
        EnqueueC(loctestnum, loctesterr, que, 5);
        EnqueueC(loctestnum, loctesterr, que, 12);
        EnqueueC(loctestnum, loctesterr, que, 51);

        Empty(loctestnum, loctesterr, que, false);
        Size(loctestnum, loctesterr, que, true, 5);
        Head(loctestnum, loctesterr, que, true, 1);


        cout << endl << "<<queue con specific constructor (copy)>>"<< endl;
        Que copque(que);    
        EqualQueue(loctestnum, loctesterr, que, copque, true);
        NonEqualQueue(loctestnum, loctesterr, que, copque, false);
        HeadNDequeue(loctestnum, loctesterr, que, true, 1);
        Dequeue(loctestnum, loctesterr, que, true);
        EqualQueue(loctestnum, loctesterr, que, copque, false);
        NonEqualQueue(loctestnum, loctesterr, que, copque, true);

        copque = que;
        EqualQueue(loctestnum, loctesterr, que, copque, true);

        copque = move(que);
        HeadNDequeue(loctestnum, loctesterr, copque, true, 5);
        Dequeue(loctestnum, loctesterr, copque, true);
        Head(loctestnum, loctesterr, copque, true, 51);
        


        Que movque(move(copque));
        Head(loctestnum, loctesterr, movque, true, 51);
        Size(loctestnum, loctesterr, que, true, 3);
        Head(loctestnum, loctesterr, copque, false, 51);


    }
    catch(...)
    {
        loctestnum++; loctesterr++;
        cout << endl << "Errore! " << endl;
    }

    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    
}


template <typename Que>
void testQueueDouble(Que & que, uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    try
    {
        Empty(loctestnum, loctesterr, que, true);
        Size(loctestnum, loctesterr, que, true, 0);

        EnqueueC(loctestnum, loctesterr, que, 4.3);
        EnqueueC(loctestnum, loctesterr, que, 3.4);
        EnqueueC(loctestnum, loctesterr, que, 8.2);
        EnqueueC(loctestnum, loctesterr, que, 51.2);

        Empty(loctestnum, loctesterr, que, false);
        Size(loctestnum, loctesterr, que, false, 3);
        Size(loctestnum, loctesterr, que, true, 4);
        Head(loctestnum, loctesterr, que, true, 4.3);


        cout << endl << "<<queue con specific constructor (copy)>>"<< endl;
        Que copque(que);    
        EqualQueue(loctestnum, loctesterr, que, copque, true);
        NonEqualQueue(loctestnum, loctesterr, que, copque, false);
        HeadNDequeue(loctestnum, loctesterr, que, true, 4.3);
        Dequeue(loctestnum, loctesterr, que, true);
        EqualQueue(loctestnum, loctesterr, que, copque, false);
        NonEqualQueue(loctestnum, loctesterr, que, copque, true);

        copque = que;
        EqualQueue(loctestnum, loctesterr, que, copque, true);

        copque = move(que);
        HeadNDequeue(loctestnum, loctesterr, copque, true, 8.2);
        Dequeue(loctestnum, loctesterr, copque, true);
        Head(loctestnum, loctesterr, copque, false, 51.2);
        EnqueueC(loctestnum, loctesterr, copque, 51.2);


        Que movque(move(copque));
        Head(loctestnum, loctesterr, movque, true, 51.2);
        Size(loctestnum, loctesterr, movque, true, 1);
        Head(loctestnum, loctesterr, movque, true, 51.2);


    }
    catch(...)
    {
        loctestnum++; loctesterr++;
        cout << endl << "Errore! " << endl;
    }
    
    testnum += loctestnum;
    testerr += loctesterr;

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
}


template <typename Que>
void testQueueString(Que & que, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    Empty(loctestnum, loctesterr, que, true);
    EnqueueM(loctestnum, loctesterr, que, string("A"));
    EnqueueM(loctestnum, loctesterr, que, string("B"));
    EnqueueM(loctestnum, loctesterr, que, string("C"));
    EnqueueM(loctestnum, loctesterr, que, string("D"));

    Empty(loctestnum, loctesterr, que, false);
    Size(loctestnum, loctesterr, que, true, 4);

    cout << endl << "<<queue con specific constructor (copy)>>"<< endl;
    Que copque(que);    

    HeadNDequeue(loctestnum, loctesterr, que, true, string("A"));
    Head(loctestnum, loctesterr, copque, true, string("A"));
    Head(loctestnum, loctesterr, que, true, string("B"));
    Dequeue(loctestnum, loctesterr, que, true);
    Dequeue(loctestnum, loctesterr, que, true);
    Dequeue(loctestnum, loctesterr, que, true);
    Empty(loctestnum, loctesterr, que, true);
    Que movque(move(copque));
    Empty(loctestnum, loctesterr, movque, false);
    Head(loctestnum, loctesterr, movque, true, string("A"));
    Size(loctestnum, loctesterr, movque, true, 4);
    Head(loctestnum, loctesterr, movque, false, string("B"));
    que.Clear();
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Errore! " << endl;
  }

  testnum += loctestnum;
  testerr += loctesterr;
  
  cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;

}


void QueueTest(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    cout << endl << endl << "Inizio Test Queue" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    cout << endl << "~~~QUEVEC<INT>~~~" << endl;
    lasd::QueueVec<int> queuevecint;
    testQueueInt(queuevecint, loctestnum, loctesterr);


    cout << endl << "~~~QUELIST<INT>~~~" << endl;
    lasd::QueueLst<int> queuelstint;
    testQueueInt(queuelstint, loctestnum, loctesterr);


    cout << endl << "~~~QUEVEC<DOUBLE>~~~" << endl;
    lasd::QueueVec<double> queuevecdouble;
    testQueueDouble(queuevecdouble, loctestnum, loctesterr);

    cout << endl << "~~~QUELIST<DOUBLE>~~~" << endl;
    lasd::QueueLst<double> queuelstdouble;
    testQueueDouble(queuelstdouble, loctestnum, loctesterr);

    cout << endl << "~~~QUEVEC<STRING>~~~" << endl;
    lasd::QueueVec<string> queuevecstr;
    testQueueString(queuevecstr, loctestnum, loctesterr);

    cout << endl << "~~~QUELIST<STRING>~~~" << endl;
    lasd::QueueLst<string> queuelststr;
    testQueueString(queuelststr, loctestnum, loctesterr);

    try {
        lasd::Vector<string> vec(3);
        SetAt(loctestnum, loctesterr, vec, true, 0, string("S"));
        SetAt(loctestnum, loctesterr, vec, true, 1, string("L"));
        SetAt(loctestnum, loctesterr, vec, true, 2, string("P"));



        EnqueueM(loctestnum, loctesterr, queuevecstr, string("S"));
        EnqueueM(loctestnum, loctesterr, queuevecstr, string("L"));
        EnqueueM(loctestnum, loctesterr, queuevecstr, string("P"));

        lasd::QueueVec<string> newquevec(vec);
        EqualQueue(loctestnum, loctesterr, queuevecstr, newquevec, true);



        EnqueueM(loctestnum, loctesterr, queuelststr, string("S"));
        EnqueueM(loctestnum, loctesterr, queuelststr, string("L"));
        EnqueueM(loctestnum, loctesterr, queuelststr, string("P"));
        lasd::QueueLst<string> newquelst(vec);
        EqualQueue(loctestnum, loctesterr, queuelststr, newquelst, true);
        


    }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }


    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Fine Test Queue" << endl;
    cout << endl << "Errori: " << loctesterr << " Test: " << loctestnum << endl;
    cout << "-------------------------------------------------------------------------------"<< endl;

}

