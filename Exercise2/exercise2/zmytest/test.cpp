
#include "./BinaryTreeTest/bttest.hpp"
#include "./BSTTest/bsttest.hpp"
/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
    cout << endl << "*************Inizio My Test*************" << endl;

    unsigned int loctestnum, loctesterr;
    unsigned int testnum = 0, testerr = 0;
    loctestnum = 0; loctesterr = 0;
    BinaryTreeTest(loctestnum, loctesterr);
    BSTTest(loctestnum, loctesterr);

  testnum += loctestnum; testerr += loctesterr;

  cout << endl << "*************Fine My Test*************";
  cout << endl << "Errori: " << testerr << " Test: " << testnum << endl;
}
