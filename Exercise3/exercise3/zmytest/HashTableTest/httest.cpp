#include<iostream>

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"

#include "../../zlasdtest/iterator/iterator.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

#include "../../zlasdtest/binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../hashtable/hashtable.hpp"
#include "../../zlasdtest/hashtable/hashtable.hpp"
#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"


using namespace std;

void testHashTableInt(unsigned int & testnum, unsigned int & testerr){
    
    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of HashTable<int> Test" << endl;
    try{

    
    lasd::Vector<int> vec(126);
    for (uint i = 0; i < 126; i++) {
      vec[i] = i;
    }

    lasd::HashTableOpnAdr<int> htopnadr(100, vec);
    Size(loctestnum, loctesterr, htopnadr, true, 126);

    lasd::Vector<int> container(63);
    for(uint i = 0; i < 63; i++){
        container[i] = 2 * i;
    }

    CountHT(loctestnum, loctesterr, htopnadr, container, 63);

    for (int i = 0; i < 63; i++){
        int j = i*2;
        Remove(loctestnum, loctesterr, htopnadr, vec[j]);
    }

    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htopnadr, false, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      InsertC(loctestnum, loctesterr, htopnadr, vec[i]);
    }
    
    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
    }

    htopnadr.Resize(4001);
    Size(loctestnum, loctesterr, htopnadr, true, 126);
    Empty(loctestnum, loctesterr, htopnadr, false);
    htopnadr.Clear();
    Empty(loctestnum, loctesterr, htopnadr, true);
    Size(loctestnum, loctesterr, htopnadr, true, 0);
    InsertC(loctestnum, loctesterr, htopnadr, vec);
    Size(loctestnum, loctesterr, htopnadr, true, 126);



    lasd::HashTableClsAdr<int> htclsadr(100, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 126);

    CountHT(loctestnum, loctesterr, htclsadr, container, 63);

    for (int i = 0; i < 63; i++){
        int j = i*2;
        Remove(loctestnum, loctesterr, htclsadr, vec[j]);
    }

    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, true, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, false, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      InsertC(loctestnum, loctesterr, htclsadr, vec[i]);
    }
    
    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, true, vec[i]);
    }

    htclsadr.Resize(4001);
    Size(loctestnum, loctesterr, htclsadr, true, 126);
    Empty(loctestnum, loctesterr, htclsadr, false);
    htclsadr.Clear();
    Empty(loctestnum, loctesterr, htclsadr, true);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    InsertC(loctestnum, loctesterr, htclsadr, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 126);



    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


void HashTableTest(unsigned int & testnum, unsigned int & testerr){
    unsigned int loctestnum = 0;
    unsigned int loctesterr = 0;

    cout << endl << "Inizio Test Hash Table" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    testHashTableInt(loctestnum, loctesterr);

    cout << "-------------------------------------------------------------------------------" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
