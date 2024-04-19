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

void ListTest(uint & testnum, uint & testerr){
    cout << endl << "Inizio Test Lista" << endl << endl;
    uint loctestnum = 0, loctesterr = 0;
    //testListInt(loctestnum, loctesterr);
    //testListDouble(loctestnum, loctesterr);
    //testListString(loctestnum, loctesterr);
    testnum += loctestnum;
    testerr += loctesterr;
    cout << endl << "Fine test Lista";
    cout << endl << "Errori: " << loctesterr << " Test: " << loctestnum << endl;
}