/**
*	@author Rebekah Manweiler
*	@date 10/31/16
*	@file TestSuite.cpp
*/

#include "TestSuite.h"

void TestSuite::runTests(){
    std::cout<<"---------------- Begin Tests --------------------------------------------------\n\n";
    testList = new LinkedListOfInts();
    std::cout<<"---------------- a new list was created ---------------------------------------\n";
    std::cout<<"\ntestConstructor: expected result 'testList was successfully created'-----------\n";
    
    if(testConstructor()){
        std::cout<<"\ntestIsEmpty: expected result 'testList is empty'-----------------------------\n";
        testIsEmpty();
        std::cout<<"\ntestSize: expected result 'testList contians 0'--------------------------------\n";
        testSize();
        std::cout<<"\n--------------Tests on empty list successful--------------------------------\n";
        std::cout<<"\n--------------Add nodes one at a time with addFront-------------------------\n";
        for(int i = 0; i < 10; i++){
            std::cout<<"\ntestAddFront: expected result '"<<i<<" added to the front'-------------------------\n";
            testAddFront(i);
        }
        std::cout<<"\ntestIsEmpty: expected result 'testList is not empty'\n";
        testIsEmpty();
        std::cout<<"\ntestSize: expected result 'testList contains 10'\n";
        testSize();
        std::cout<<"\n-------------addition of nodes using addFront successful-----------------------";
        std::cout<<"\n-------------isEmpty test on list with nodes fails-----------------------------";
        std::cout<<"\n-------------size test on lsit with nodes successful---------------------------\n";
        std::cout<<"\n-------------Test removeFront on list with nodes-------------------------------\n";
        std::cout<<"\ntestRemoveFront: expected result '8,7,6,5,4,3,2,1,0'\n";
        testRemoveFront();
        std::cout<<"\ntestIsEmpty: expected result 'testList is not empty'\n";
        testIsEmpty();
        std::cout<<"\ntestSize: expected result 'testList contains 9'\n";
        testSize();
        std::cout<<"\n---------------All tests on removeFront fail------------------------------------";
        std::cout<<"\n---------------size is still 10-------------------------------------------------\n";
        std::cout<<"\n---------------Test removeBack on list with nodes-------------------------------\n";
        std::cout<<"\ntestRemoveBack: expected result '9,8,7,6,5,4,3,2,1'\n";
        testRemoveBack();
        std::cout<<"\ntestIsEmpty: expected result 'testList is not empty'\n";
        testIsEmpty();
        std::cout<<"\ntestSize: expected result 'testList contains 9'\n";
        testSize();
        std::cout<<"\n---------------All tests on removeBack fail------------------------------------";
        std::cout<<"\n---------------size is still 10-------------------------------------------------\n";
        std::cout<<"\n---------------Test search------------------------------------------------------\n";
        printList();
        for(int i = 0; i < 10; i++){
            std::cout<<"\ntestSearch: expected result 'test list contains "<<i<<"\n";
            testSearch(i);
        }
        std::cout<<"\ntestSearch: expected result 'test list did not contain 52\n";
        testSearch(52);
        std::cout<<"\ntestSearch: expected result 'test list did not contain 'c''\n";
        testSearch('c');
        std::cout<<"\n---------------Search test on list successful----------------------------------\n";
        std::cout<<"\n---------------Test destructor -------------------------------------------------\n";
        std::cout<<"\ntestDestructor: check memory leaks with valgrind\n";
        testDestructor();
        std::cout<<"\ntestDestructor: pointer still points to same memory location\n";
        std::cout<<"\ntestDestructor: unclear if list object or nodes are still there until valgrind is run\n";
        std::cout<<"\ntestDestructor: after destructor is called toVector still works but other funtions of the list do not\n";
        //segfaults occur when these tests are run
        //std::cout<<"\ntestIsEmpty: expected result 'testList is empty'\n";
        //testIsEmpty();
        //std::cout<<"\ntestSize: expected result 'testList contains 0'\n";
        //testSize();
        //std::cout<<"\ntestAddFront: expected result ' 1 added to the front'-------------------------------\n";
        //testAddFront(52);
        std::cout<<"\n---------------Making a new list-----------------------------------------------\n";
        testList = new LinkedListOfInts();
        std::cout<<"\n---------------Add 1000 nodes with addFront------------------------------------\n";
        for(int i = 0; i < 1000; i++){
            testList->addFront(i);
        }
        std::cout<<"\ntestSize: expected result 'test list contains 1000'\n";
        testSize();
        std::cout<<"\n---------------Add 1000 nodes with addBack--------------------------------------\n";
        for(int i = 0; i < 1000; i++){
            testList->addBack(i);
        }
        std::cout<<"\ntestSize: expected result 'test list contains 2000'\n";
        testSize();
        std::cout<<"------------------Tests on size are successful--------------------------------------\n";
        std::cout<<"------------------Add back test is unsuccessful, works like addFront ---------------\n";
        std::cout<<"\n------------------Test removeFront and removeBack on a large list------------------\n";
        std::cout<<"\ntestRemoveFront: expected result 'front node successful removed'\n";
        testRemoveFront();
        std::cout<<"\ntestRemoveBack: expected result 'back node successful removed'\n";
        testRemoveBack();
        std::cout<<"\n-------------------Remove tests unsuccessful on large list--------------------------\n";
        std::cout<<"\n-------------------Test search on large list ---------------------------------------\n";
        std::cout<<"\ntestSearch: expected result 'test list contains 849'\n";
        testSearch(849);
        std::cout<<"\ntestSearch: expected result 'test list did not contain 2001'\n";
        testSearch(2001);
        std::cout<<"\ntestSearch: expected result 'test list contains 0'\n";
        testSearch(0);
        std::cout<<"\n-------------------Search test on large list successful------------------------------\n";
        
        std::cout<<"-------------------Tests Completed-------------------------------------------------\n";
        
    }
    else{
        std::cout<<"--------------- Tests Aborted -------------------------------------------------\n";
    }
}











bool TestSuite::testConstructor(){
    if(testList != nullptr){
        std::cout<<"testConstructor: result 'testList was successfully created'\n";
        return true;
    }
    else{
        std::cout<<"testConstructor: result 'testList creation was unsuccessful'\n";
        return false;
    }
}

bool TestSuite::testDestructor(){
    std::cout<<"testDestructor: testptr created, also looking at our list\n";
    LinkedListOfInts* testptr = testList;
    delete testList;
    std::cout<<"testDestructor: result 'testList is looking at "<<testList<<"'\n";
    std::cout<<"testDestructor: result 'testptr is looking at "<<testptr<<"'\n";
    printList();
    testList = nullptr;
}

void TestSuite::testIsEmpty(){
    if(testList->isEmpty()){
        std::cout<<"testIsEmpty: result 'testList is empty'\n";
    }
    else{
        std::cout<<"testIsEmpty: result 'testList is not empty'\n";
    }
}

void TestSuite::testSize(){
    std::cout<<"testSize: result 'testList contains "<<testList->size()<<"'\n";
    printList();
}

void TestSuite::testSearch(int value){
    if(testList->search(value)){
        std::cout<<"testSearch: result 'testList contains "<<value<<"'\n";
    }
    else{
        std::cout<<"testSearch: result 'testList did not contain "<<value<<"'\n";
    }
}

void TestSuite::testAddBack(int value){
    testList->addBack(value);
    std::cout<<"testAddBack: result '"<<value<<" added to the back\n";
    printList();
}

void TestSuite::testAddFront(int value){
    testList->addFront(value);
    std::cout<<"testAddFront: result '"<<value<<" added to the front\n";
    printList();
}

void TestSuite::testRemoveBack(){
    if(testList->removeBack()){
        std::cout<<"testRemoveBack: result 'back node removed successfully'\n";
        printList();
    }
    else{
        std::cout<<"testRemoveBack: result 'back node removal not successful'\n";
        printList();
    }
}

void TestSuite::testRemoveFront(){
    if(testList->removeFront()){
        std::cout<<"testRemoveFront: result 'front node removed successfully'\n";
        printList();
    }
    else{
        std::cout<<"testRemoveFront: result 'front node removal not successful'\n";
        printList();
    }
}

void TestSuite::printList(){
    std::vector<int> list = testList->toVector();
    std::cout<<"printList: ";
    for(int i = 0; i < list.size(); i++){
        std::cout<<list[i]<<", ";
    }
    std::cout<<"\n";
}
