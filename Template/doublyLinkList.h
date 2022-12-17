#include <iostream>
using namespace std;

class doublyNode
{
public:
     T data;
    doublyNode *next;
    doublyNode *previous;
};
class DLL
{
public:
    doublyNode *start;
    doublyNode *last;
    doublyNode *loc;
    doublyNode *ploc;
    doublyNode *sloc;
    DLL()
    {
        start = nullptr;
        last = nullptr;
        loc = nullptr;
        ploc = nullptr;
        sloc = nullptr;
    }
    bool isEmpty()
    {
        return start == nullptr;
    }
    void insertAtFront( T val)
    {
        doublyNode *nn = new doublyNode();
        nn->data = val;
        if (isEmpty())
        {
            start = nn;
            last = nn;
            nn->next = nullptr;
            nn->previous = nullptr;
        }
        else
        {
            nn->next = start;
            nn->previous = nullptr;
            start->previous = nn;
            start = nn;
        }
    }
    void insertAtEnd( T val)
    {
        doublyNode *nn = new doublyNode();
        nn->data = val;
        if (isEmpty())
        {
            last = nn;
            start = nn;
            nn->next = nullptr;
            nn->previous = nullptr;
        }
        else
        {
            last->next = nn;
            nn->previous = last;
            nn->next = nullptr;
            last = nn;
        }
    }
    void pr TList()
    {
        doublyNode *temp = start;
        if (!(isEmpty()))
        {
            while (temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    void searchValue( T val)
    {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->data < val)
        {
            ploc = loc;
            loc = loc->next;
        }
        if (loc != nullptr and loc->data != val)
        {
            loc = nullptr;
        }
    }
    void insertSorted( T val)
    {
        searchValue(val);
        if (loc == nullptr)
        {

            if (ploc == nullptr)
            {
                insertAtFront(val);
            }
            else
            {
                if (ploc == last)
                {
                    insertAtEnd(val);
                }
                else
                {
                    doublyNode *nn = new doublyNode();
                    nn->data = val;
                    nn->next = ploc->next;
                    nn->previous = ploc;
                    (ploc->next)->previous = nn;
                    ploc->next = nn;
                }
            }
        }
    }
    void deleteFront()
    {
        if (!isEmpty())
        {
            doublyNode *temp = start;
            start = start->next;
            start->previous = nullptr;
            delete temp;
        }
    }
    void deleteLast()
    {
        if (!isEmpty())
        {
            doublyNode *temp = last;
            last = last->previous;
            last->next = nullptr;
            delete temp;
        }
    }
    void deleteValue( T val)
    {
        if (isEmpty())
        {
            cout << "Invalid Command!" << endl;
        }
        else
        {
            searchValue(val);
            if (loc != nullptr)
            {
                if (ploc == nullptr)
                {
                    deleteFront();
                }
                else
                {
                    if (loc == last)
                    {
                        deleteLast();
                    }
                    else
                    {
                        ploc->next = loc->next;
                        (loc->next)->previous = ploc;
                        delete loc;
                    }
                }
            }
        }
    }
    void destroyList()
    {
        doublyNode *temp;
        while (start != nullptr)
        {
            temp = start;
            start = start->next;
            delete temp;
        }
    }
    void reverseList()
    {
        if (isEmpty())
        {
            cout << "INVALID OPERATION TRY AGAIN!" << endl;
        }
        else
        {
            ploc = nullptr;
            loc = start;
            last = start;
            while (loc != nullptr)
            {
                sloc = loc->next;
                loc->next = ploc;
                loc->previous = sloc;
                ploc = loc;
                loc = loc->next;
            }
            start = ploc;
        }
    }
};