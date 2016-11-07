/**
*	@file TestSuite.h
*	@author Rebekah Manweiler 
*	@date 10/31/16
*/

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"

class TestSuite 
{
    
public:
    /** @brief uses the test methods to test certain aspects of the LinkedListOfInts*/
    void runTests();
    
private:
    
    /** @brief conditions for LinkedListOfInts(): (pre: None, post: An empty list is created)
     * @pre none
     * @post the testList has been created and tested
     * @return false if creation failed and no other testing methods will run
    */
    bool testConstructor();
    
    /** @brief conditionf for ~LinkedListofInts(): (pre: None, post: Deletes all nodes in the list)
     * @pre all other test methods have been run 
     *   @returns true if all the nodes in the list have been deleted
    */
    bool testDestructor();
    
    /** @brief conditions for isEmpty(): (return: true if the list is empty, false otherwise)
     * @pre testConstructor returned true
    *   @return true if isEmpty returns the correct values
    */
    void testIsEmpty();
    
    /** @brief conditions for size(): (return: the number of elements in the list)
     * @pre testConstructor returned true
    *   @return true if size returns the correct number of nodes in the list
    */
    void testSize();
    
    /** @brief conditions for search(): (pre: the value is a valid T, return: true if the value is in the list, false otherwise)
     * @pre testConstructor returned true
    *   @return true if search returns the correct values 
    */
    void testSearch(int value);
    
    /** @brief conditions for addBack(): (pre: the value is a valid T, post:one new element added to the end of the list) 
     * @pre testconstructor returned true
    *   @return true if a node was added to the back
    */
    void testAddBack(int value);
    
    /** @brief conditions for addFront(): (pre: the value is a valid T, post:one new element added to the front of the list) 
     * @pre testConstructor returned true
    *   @return true if a node was added to the front
    */
    void testAddFront(int value);
    
    /** @brief conditions for removeBack(): (post: one element is removed from the back of the list, return: true if the back element was removed, false if the list is empty) 
     * @pre testconstructor returned true
    *   @return true if the back element was removed or removeBack returned the correct value
    */
    void testRemoveBack();
    
    /** @brief conditions for removeFront(): (post: one element is removed from the front of the list, return: true if the front element was removed, false if the list is empty) 
     * @pre testconstructor returned true
    *   @return true if the front element was removed or removeFront returned the correct value
    */
    void testRemoveFront();
    
    void printList();
    
    LinkedListOfInts* testList;
    
};

#endif
