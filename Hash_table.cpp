#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <list>
#include <cstring>
using namespace std;

// creating a hash table using chaining(underlying implementation is doubly linked list)
class Hashtable
{
private:
    static const int hashGroup= 7; // size of the bucket
    list< pair<int, string> > mylist[hashGroup]; // creating a list of size 10 where each room contains an int and a string
public:
    bool isEmpty() const;
    int hasFunction( int key);
    void inseritem (int key, string value);
    void removeItem(int key);
    string searchmylist(int key);
    void printlist();
    
};

bool Hashtable::isEmpty() const
{
    int sum{};
    for ( int i {}; i< hashGroup; i++)
    {
        sum+= mylist[i].size();
    }
    if (!sum)
        return true; // emepty
    else
        return false; // not empty
}

int Hashtable::hasFunction(int key)
{
    return key% hashGroup;
}

void Hashtable::inseritem(int key, string value)
{
    int hasvalue = hasFunction(key); // calculating the has value
    auto& cell_number = mylist [hasvalue]; // finding the right cell to insert the key,value
    
    auto bitr= begin(cell_number); // bitr is an iterator.
    bool keyexist= false;
    // This for loop will iterate over the list to insert the key/value to the end of this list.
    for (;bitr!=end(cell_number); bitr++)
    {
        if ( bitr->first==key)
        {
            keyexist= true;
            bitr->second= value;
            cout<< " Key exist but value has been replaced. " << endl;
            break;
        }
    }
    
    if(!keyexist)
    {
        cell_number.emplace_back(key, value);
    }
    return;
    
 }

void Hashtable::removeItem(int key)
{
    int hasvalue = hasFunction(key);
    auto& cell_num = mylist [hasvalue]; // finding the right cell to insert the key,value
    
    auto bitr= begin(cell_num); // bitr is an iterator.
    bool keyexist= false;
    for (;bitr!=end(cell_num); bitr++)
    {
        if ( bitr->first==key)
        {
            keyexist= true;
            bitr= cell_num.erase(bitr); // erase () will return an iterator that points to the next cell
           
            cout<< "Item has been removed." << endl;
            break;
        }
    }
    if (!keyexist)
    {
        cout<< " Item is not the table. " << endl;
    }
}

void Hashtable::printlist()
{
    // This for loop will iterate over the table
    for ( int i{}; i<hashGroup; i++)
    {
        if (mylist[i].size()==0)
            continue;
        
        auto bitr= mylist[i].begin();
        for(;bitr!=mylist[i].end();bitr++) // Iterating over a particular list, until the iterator becomes equal to the end itaror of the list.
        {
            cout<<" key : " << bitr->first << " Value: " <<bitr->second << endl;
        }
            
        
    }
        
    
}

int main()
{
    Hashtable Ht;
    if ( Ht.isEmpty())
    {
        cout<< " correct answer, " << endl;
    }
    else
        cout<< " need to check code " << endl;
    Ht.inseritem(55, "john");
    Ht.inseritem(3, "Amy");
    Ht.inseritem(11, "Liz");
    Ht.inseritem(30, "Kate");
    Ht.inseritem(47, "James");
    Ht.inseritem(77, "Steven");
    Ht.inseritem(23, "Jane");
    Ht.inseritem(31, "Bob");
    Ht.inseritem(44, "Frank");
    Ht.inseritem(41, "Mike");
    Ht.printlist();
    
    Ht.removeItem(124);
    Ht.removeItem(100);
    
    if ( Ht.isEmpty())
    {
        cout<< " check your code " << endl;
    }
    else
        cout<< " Good Job" << endl;
    
    
}
