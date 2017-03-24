/**
 * CS 225 lab_avl
 * @file main.cpp
 * @author Daniel Hoodin in Spring 2008.
 * Modified by Kyle Johnson in Fall 2010.
 * Modified by Sean Massung in Summer 2012:
 *  - added templates
 *  - CRTP tree printing
 *  - doxygen
 */

#include <iostream>
#include <sstream>
#include <string>
#include "avltree.h"
#include "coloredout.h"

using namespace std;

void printHeader(const string& headline)
{
    cout << string(64, colored_out::BORDER_CHAR) << endl;
    colored_out::output_bold(headline);
    cout << endl << string(64, colored_out::BORDER_CHAR) << endl;
}

void printBefore()
{
    cout << "~";
    colored_out::output_bold("Before");
    cout << "~" << endl;
}

void printAfter(int inserted)
{
    cout << endl << "~";
    colored_out::output_bold("After insert(");
    colored_out::output_bold(inserted);
    colored_out::output_bold(")");
    cout << "~" << endl;
}

void printEnd()
{
    cout << endl << endl;
}

void testFind()
{
    AVLTree<string, string> tree;
    printHeader("Testing Find");
    tree.insert("C", "C++");
    tree.insert("free", "delete");
    tree.insert("malloc", "new");
    tree.insert("bool", "void");
    cout << "find(C) -> " << tree.find("C") << endl;
    cout << "find(free) -> " << tree.find("free") << endl;
    cout << "find(malloc) -> " << tree.find("malloc") << endl;
    cout << "find(bool) -> " << tree.find("bool") << endl;
    printEnd();
}

void testRotateLeft()
{
    AVLTree<int, int> tree;
    printHeader("Left Rotation");
    tree.insert(4, 4);
    tree.insert(6, 6);
    tree.insert(2, 2);
    tree.insert(7, 7);
    tree.insert(5, 5);
    printBefore();
    tree.print();
    printAfter(9);
    tree.insert(9, 9);
    tree.print();
    printEnd();
}

void testRotateRight()
{
    AVLTree<int, int> tree;
    printHeader("Right Rotation");
    tree.insert(3, 3);
    tree.insert(0, 0);
    tree.insert(8, 8);
    tree.insert(6, 6);
    printBefore();
    tree.print();
    printAfter(5);
    tree.insert(5, 5);
    tree.print();
    printEnd();
}

void testRotateRightLeft()
{
    AVLTree<int, int> tree;
    printHeader("Right-Left Rotation");
    tree.insert(3, 3);
    tree.insert(8, 8);
    printBefore();
    tree.print();
    printAfter(6);
    tree.insert(6, 6);
    tree.print();
    printEnd();
}

void testRotateLeftRight()
{
    AVLTree<int, int> tree;
    printHeader("Left-Right Rotation");
    tree.insert(5, 5);
    tree.insert(1, 1);
    tree.insert(8, 8);
    tree.insert(0, 0);
    tree.insert(3, 3);
    printBefore();
    tree.print();
    printAfter(2);
    tree.insert(2, 2);
    tree.print();
    printEnd();
}

void testManyInsertions()
{
    AVLTree<int, string> tree;
    printHeader("Testing Many Insertions");
    tree.insert(94, "data for 94");
	tree.print();
    cout<<"1"<<endl;	
    tree.insert(87, "data for 87");
    tree.print();
    cout<<"2"<<endl;
    /*tree.insert(61, "data for 61");    	
    tree.print();
    cout<<"3"<<endl;
    tree.insert(96, "data for 96");
	tree.print();        
    cout<<"4"<<endl;
    tree.insert(76, "data for 76");
    tree.print();
    cout<<"5"<<endl;
    tree.insert(92, "data for 92");
    tree.print();
    cout<<"6"<<endl;
    tree.insert(42, "data for 42");
    tree.print();
    cout<<"7"<<endl;
    tree.insert(78, "data for 78");
    tree.print();
    cout<<"8"<<endl;
    tree.insert(17, "data for 17");
    tree.print();
    cout<<"9"<<endl;
    tree.insert(11, "data for 11");
    tree.print();
    cout<<"10"<<endl;
    tree.insert(41, "data for 41");
    tree.print();
    cout<<"11"<<endl;
    tree.insert(95, "data for 95");
    tree.print();
    cout<<"12"<<endl;
    tree.insert(36, "data for 36");
    tree.print();
    cout<<"13"<<endl;
    tree.insert(26, "data for 26");
    tree.print();
    cout<<"14"<<endl;
    tree.insert(23, "data for 23");
    tree.print();
    cout<<"15"<<endl;
    tree.insert(93, "data for 93");
    tree.print();
    cout<<"16"<<endl;
    tree.insert(31, "data for 31");
    tree.print();
    cout<<"17"<<endl;
    tree.insert( 3, "data for 3");
    tree.print();
    cout<<"18"<<endl;
    tree.insert(45, "data for 45");
    tree.print();
    cout<<"19"<<endl;
    tree.insert(18, "data for 18");
    tree.print();
    cout<<"20"<<endl;
    tree.insert(73, "data for 73");
    cout<<"21"<<endl;
    tree.insert(24, "data for 24");
    tree.print();
    cout<<"22"<<endl;
    tree.insert(74, "data for 74");
    tree.print();
    cout<<"23"<<endl;
    tree.insert( 1, "data for 1");
    tree.print();
    cout<<"24"<<endl;
    tree.insert(71, "data for 71");
    tree.print();
    cout<<"25"<<endl;
    tree.insert(82, "data for 82");
    cout<<"done"<<endl;
    cout<<"26"<<endl;
    tree.print();
    */
    printEnd();
}

void testManyRemovals()
{
    AVLTree<int, string> tree;
    printHeader("Testing Many Removals");
    tree.insert(94, "data for 94");
    tree.insert(87, "data for 87");
    tree.insert(61, "data for 61");
    tree.insert(96, "data for 96");
    tree.insert(76, "data for 76");
    tree.insert(92, "data for 92");
    tree.insert(42, "data for 42");
    tree.insert(78, "data for 78");
    tree.insert(17, "data for 17");
    tree.insert(11, "data for 11");
    tree.insert(41, "data for 41");
    tree.insert(95, "data for 95");
    tree.insert(36, "data for 36");
    tree.insert(26, "data for 26");
    tree.insert(23, "data for 23");
    tree.insert(93, "data for 93");
    tree.insert(31, "data for 31");
    tree.insert( 3, "data for 3");
    tree.insert(45, "data for 45");
    tree.insert(18, "data for 18");
    tree.insert(73, "data for 73");
    tree.insert(24, "data for 24");
    tree.insert(74, "data for 74");
    tree.insert( 1, "data for 1");
    tree.insert(71, "data for 71");
    tree.insert(82, "data for 82");
    tree.remove(95);
    tree.remove(94);;
    tree.remove(61);
    tree.remove(76);
    tree.remove(73);
    tree.remove(71);
    tree.print();
    printEnd();
}

int main(int argc, char** argv)
{
    // Set up Colored Output (if 'color' parameter passed)
    bool is_colored
        = (argc > 1 && tolower(argv[1][0]) == 'c') && isatty(STDOUT_FILENO);
    colored_out coloroutput;
    if (is_colored) {
        coloroutput.set_expected_file("soln_testavl.out");
        int status = coloroutput.start();
        if (status < 0)
            return 0;
    }

    // Test AVL Tree
    testFind();
    testRotateLeft();
    testRotateRight();
    testRotateLeftRight();
    testRotateRightLeft();
    testManyInsertions();
    testManyRemovals();
    return 0;
}
