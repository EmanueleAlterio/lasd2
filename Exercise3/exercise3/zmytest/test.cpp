#include <iostream>
#include "./BinaryTreeTest/bttest.hpp"
#include "./BSTTest/bsttest.hpp"
/* ************************************************************************** */



using namespace std;

/* ************************************************************************** */

void mytest() {

  cout << endl << "~*~#~*~ Inizio My Test ~*~#~*~" << endl;

  unsigned int loctestnum, loctesterr;
  unsigned int testnum = 0, testerr = 0;
  loctestnum = 0; loctesterr = 0;
  BinaryTreeTest(loctestnum, loctesterr);
  BSTTest(loctestnum, loctesterr);

  testnum += loctestnum; testerr += loctesterr;
  
  cout << endl << "~*~#~*~ Fine My Test ~*~#~*~";
  cout << endl << "Errori: " << testerr << " Test: " << testnum << endl;
/*   cout << endl << "Errori: " << testerr << " Test: " << testnum << endl;

    cout << "---------------------------------HASHISH<int>---------------------------------" << endl;


    lasd::Vector<int> vec(127);
    for(unsigned long i = 0; i<127; i++){
        vec[i] = i;
    }

    lasd::HashTableOpnAdr<int> ht(83, vec);
    //cout << ht.tableSize << endl;
    

cout << "---------------------------------HASHISH<int>---------------------------------" << endl; */

}
