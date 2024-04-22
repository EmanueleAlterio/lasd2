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
    
}



void QueueTest(uint & testnum, uint & testerr){
    uint loctestnum = 0, loctesterr = 0;

    cout << endl << "Inizio Test Queue" << endl << endl;

    lasd::QueueVec<int> queuevecint;
    testQueueInt(queuevecint, loctestnum, loctesterr);

    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Fine Test Queue" << endl;
}