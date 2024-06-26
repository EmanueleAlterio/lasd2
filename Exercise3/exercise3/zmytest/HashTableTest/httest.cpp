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

void mytestHashTableInt(unsigned int & testnum, unsigned int & testerr){



    
    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of HashTable<int> Test" << endl;

    cout << endl << "OPN ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
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

    lasd::HashTableOpnAdr<int> cophtopnadr(htopnadr);
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    lasd::HashTableOpnAdr<int> movhtopnadr(std::move(cophtopnadr));
    EqualHT(loctestnum, loctesterr, movhtopnadr, htopnadr);
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, movhtopnadr);
    cophtopnadr = htopnadr;
    EqualHT(loctestnum, loctesterr, movhtopnadr, cophtopnadr);
    lasd::HashTableOpnAdr<int> cop2htopnadr;
    cop2htopnadr = std::move(cophtopnadr);
    EqualHT(loctestnum, loctesterr, cop2htopnadr, htopnadr);
    lasd::HashTableOpnAdr<int> htdimconstropn(90);
    lasd::HashTableOpnAdr<int> htdimconstropn2(90000); 

     lasd::Vector<int> vec2(10);
    for (uint i = 0; i < 10; i++) {
      vec2[i] = i;
    }

    
    lasd::HashTableOpnAdr<int> htopnadr2(100, vec2);
    lasd::HashTableOpnAdr<int> htopnadr3(100, std::move(vec2));
    EqualHT(loctestnum, loctesterr, htopnadr2, htopnadr3);

    lasd::Vector<int> vec3(10);
    for (uint i = 0; i < 10; i++){
      vec3[i] = i;
    }

    lasd::HashTableOpnAdr<int> htopnadr4(vec3);
    lasd::HashTableOpnAdr<int> htopnadr5(std::move(vec3));
    EqualHT(loctestnum, loctesterr, htopnadr4, htopnadr5);

    cout << endl << endl << "CLS ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

/* -------------------------------------------------------------------------------------------------- */

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

    lasd::HashTableClsAdr<int> cophtclsadr(htclsadr);
    Size(loctestnum, loctesterr, htclsadr, true, 126);
    Size(loctestnum, loctesterr, cophtclsadr, true, 126);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    lasd::HashTableClsAdr<int> movhtclsadr(std::move(cophtclsadr));
    EqualHT(loctestnum, loctesterr, movhtclsadr, htclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, movhtclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, movhtclsadr, cophtclsadr);
    lasd::HashTableClsAdr<int> cop2htclsadr;
    cop2htclsadr = std::move(cophtclsadr);
    EqualHT(loctestnum, loctesterr, cop2htclsadr, htclsadr);
    lasd::HashTableClsAdr<int> htdimconstr(90);
    lasd::HashTableClsAdr<int> htdimconstr2(90000);

    lasd::Vector<int> vec4(10);
    for (uint i = 0; i < 10; i++) {
      vec4[i] = i;
    }

    
    lasd::HashTableClsAdr<int> htclsadr2(100, vec4);
    lasd::HashTableClsAdr<int> htclsadr3(100, std::move(vec4));
    EqualHT(loctestnum, loctesterr, htclsadr2, htclsadr3);

    lasd::Vector<int> vec5(10);
    for (uint i = 0; i < 10; i++){
      vec5[i] = i;
    }

    lasd::HashTableClsAdr<int> htclsadr4(vec5);
    lasd::HashTableClsAdr<int> htclsadr5(std::move(vec5));
    EqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);



    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mytestHashTableDouble(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of HashTable<double> Test" << endl;

    cout << endl << "OPN ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    try{
 
    
    lasd::Vector<double> vec(25);
    for (uint i = 0; i < 25; i++) {
      vec[i] = (pow(-2, i % 24) * ((61 * i + 29) % 127)) / (83 * pow(-3, i % 7));
    }


    lasd::HashTableOpnAdr<double> htopnadr(300, vec);
    Size(loctestnum, loctesterr, htopnadr, true, 25);  


    for (int i = 0; i < 12; i++){
        int j = i*2;
        Remove(loctestnum, loctesterr, htopnadr, vec[j]);
    }

    for (int i = 1; i < 25; i += 2) {
      Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
    }

    for (int i = 0; i < 25; i += 2) {
      InsertC(loctestnum, loctesterr, htopnadr, vec[i]);
    }
    
    for (int i = 1; i < 25; i += 2) {
      Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
    }

    htopnadr.Resize(4001);
    Size(loctestnum, loctesterr, htopnadr, true, 25);
    Empty(loctestnum, loctesterr, htopnadr, false);
    htopnadr.Clear();
    Empty(loctestnum, loctesterr, htopnadr, true);
    Size(loctestnum, loctesterr, htopnadr, true, 0);
    InsertC(loctestnum, loctesterr, htopnadr, vec);
    Size(loctestnum, loctesterr, htopnadr, true, 25);

    lasd::HashTableOpnAdr<double> cophtopnadr(htopnadr);
    EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
    lasd::HashTableOpnAdr<double> movhtopnadr(std::move(cophtopnadr));
    EqualHT(loctestnum, loctesterr, movhtopnadr, htopnadr);
    NonEqualHT(loctestnum, loctesterr, cophtopnadr, movhtopnadr);
    cophtopnadr = htopnadr;
    EqualHT(loctestnum, loctesterr, movhtopnadr, cophtopnadr);
    lasd::HashTableOpnAdr<double> cop2htopnadr;
    cop2htopnadr = std::move(cophtopnadr);
    EqualHT(loctestnum, loctesterr, cop2htopnadr, htopnadr);
    lasd::HashTableOpnAdr<double> htdimconstropn(90);
    lasd::HashTableOpnAdr<double> htdimconstropn2(90000); 

     lasd::Vector<double> vec2(10);
    for (uint i = 0; i < 10; i++) {
      vec2[i] = i + 1.3;
    }

    
    lasd::HashTableOpnAdr<double> htopnadr2(100, vec2);
    lasd::HashTableOpnAdr<double> htopnadr3(100, std::move(vec2));
    EqualHT(loctestnum, loctesterr, htopnadr2, htopnadr3);

    lasd::Vector<double> vec3(10);
    for (uint i = 0; i < 10; i++){
      vec3[i] = i + 1.3;
    }

    lasd::HashTableOpnAdr<double> htopnadr4(vec3);
    lasd::HashTableOpnAdr<double> htopnadr5(std::move(vec3));
    EqualHT(loctestnum, loctesterr, htopnadr4, htopnadr5);

    cout << endl << endl << "CLS ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

/* -------------------------------------------------------------------------------------------------- */

    lasd::HashTableClsAdr<double> htclsadr(100, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 25);

    for (int i = 0; i < 13; i++){
        int j = i*2;
        Remove(loctestnum, loctesterr, htclsadr, vec[j]);
    }

    for (int i = 0; i < 25; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, false, vec[i]);
    }

    for (int i = 0; i < 25; i += 2) {
      InsertC(loctestnum, loctesterr, htclsadr, vec[i]);
    }
    
    for (int i = 1; i < 25; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, true, vec[i]);
    }

    htclsadr.Resize(4001);
    Size(loctestnum, loctesterr, htclsadr, true, 25);
    Empty(loctestnum, loctesterr, htclsadr, false);
    htclsadr.Clear();
    Empty(loctestnum, loctesterr, htclsadr, true);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    InsertC(loctestnum, loctesterr, htclsadr, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 25);

    lasd::HashTableClsAdr<double> cophtclsadr(htclsadr);
    Size(loctestnum, loctesterr, htclsadr, true, 25);
    Size(loctestnum, loctesterr, cophtclsadr, true, 25);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    lasd::HashTableClsAdr<double> movhtclsadr(std::move(cophtclsadr));
    EqualHT(loctestnum, loctesterr, movhtclsadr, htclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, movhtclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, movhtclsadr, cophtclsadr);
    lasd::HashTableClsAdr<double> cop2htclsadr;
    cop2htclsadr = std::move(cophtclsadr);
    EqualHT(loctestnum, loctesterr, cop2htclsadr, htclsadr);
    lasd::HashTableClsAdr<double> htdimconstr(90);
    lasd::HashTableClsAdr<double> htdimconstr2(90000);

    lasd::Vector<double> vec4(10);
    for (uint i = 0; i < 10; i++) {
      vec4[i] = i + 1.3;
    }

    
    lasd::HashTableClsAdr<double> htclsadr2(100, vec4);
    lasd::HashTableClsAdr<double> htclsadr3(100, std::move(vec4));
    EqualHT(loctestnum, loctesterr, htclsadr2, htclsadr3);

    lasd::Vector<double> vec5(10);
    for (uint i = 0; i < 10; i++){
      vec5[i] = i + 1.3;
    }

    lasd::HashTableClsAdr<double> htclsadr4(vec5);
    lasd::HashTableClsAdr<double> htclsadr5(std::move(vec5));
    EqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);



    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}

void mytestHashTableString(unsigned int & testnum, unsigned int & testerr){

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of HashTable<string> Test" << endl;

    cout << endl << "OPN ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    try{
 
    lasd::Vector<string> vec3(50);
    vec3[0] = "@";
    for (uint i = 1; i < 50; i++){
      vec3[i] = vec3[i - 1] + static_cast<char>(32 + ((126 * i + 31) % 95));
    }

    
    lasd::HashTableOpnAdr<string> htopnadr4(vec3);
    Size(loctestnum, loctesterr, htopnadr4, true, 50);
    for (int i = 0; i < 10; i++){
      Remove(loctestnum, loctesterr, htopnadr4, vec3[i]);
    }
    Size(loctestnum, loctesterr, htopnadr4, true, 40);
    htopnadr4.Clear();
    Size(loctestnum, loctesterr, htopnadr4, true, 0);

    cout << endl << endl << "CLS ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

/* -------------------------------------------------------------------------------------------------- */
    
    lasd::Vector<string> vec4(10);
    vec4[0] = "@";
    for (uint i = 1; i < 10; i++) {
      vec4[i] = vec4[i - 1] + static_cast<char>(32 + ((126 * i + 31) % 95));
    }

    
    lasd::HashTableClsAdr<string> htclsadr2(100, vec4);
    lasd::HashTableClsAdr<string> htclsadr3(100, std::move(vec4));
    EqualHT(loctestnum, loctesterr, htclsadr2, htclsadr3);

    lasd::Vector<string> vec5(10);
    vec5[0] = "@";
    for (uint i = 1; i < 10; i++){
      vec5[i] = vec5[i - 1] + static_cast<char>(32 + ((126 * i + 31) % 95));
    }

    lasd::HashTableClsAdr<string> htclsadr4(vec5);
    lasd::HashTableClsAdr<string> htclsadr5(std::move(vec5));
    EqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);
    htclsadr4.Clear();
    NonEqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);
    htclsadr5.Clear();
    EqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);





    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
void myHashTableTest(unsigned int & testnum, unsigned int & testerr){
    unsigned int loctestnum = 0;
    unsigned int loctesterr = 0;

    cout << endl << "Inizio Test Hash Table" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    mytestHashTableInt(loctestnum, loctesterr);
    mytestHashTableDouble(loctestnum, loctesterr);
    mytestHashTableString(loctestnum, loctesterr);

    cout << "-------------------------------------------------------------------------------" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}
