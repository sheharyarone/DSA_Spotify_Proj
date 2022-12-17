#include <iostream>
#include <string>
using namespace std;
template <class T>
class circluarNode
{
public:
    T data;
    circluarNode *next;
};
template <class T>
class CLL
{
    circluarNode *list;
    circluarNode *loc;
    circluarNode *ploc;
    CLL()
    {
        list = NULL;
        ploc = NULL;
        loc = NULL;
    }
    bool isEmpty()
    {
        return list == NULL;
    }
    void insertAtFront(T data)
    {
        circluarNode *newnode = new circluarNode();
        newnode->data = data;
        // NOT EMPTY CASE
        if (!isEmpty())
        {
            newnode->next = list->next;
            list->next = newnode;
        }
        // EMPTY CASE
        else
        {
            list = newnode;
            list->next = newnode;
        }
    }
    void insertAtTail(T data)
    {
        circluarNode *newnode = new circluarNode();
        newnode->data = data;
        // NOT EMPTY CASE
        if (!isEmpty())
        {
            newnode->next = list->next;
            list->next = newnode;
            list = newnode;
        }
        // EMPTY CASE
        else
        {
            list = newnode;
            list->next = newnode;
        }
    }
    void pr TList()
    {
        // NOT EMPTY CASE
        circluarNode *p = list->next;
        if (!isEmpty())
        {
            while (p != list->next)
            {
                cout << p->data << endl;
                p = p->next;
            }
        }
        else
        {
            cout << 'LIST IS EMPTY' << endl;
        }
    }
    void Search(T value)
    {

        loc, ploc = NULL;
        if (isEmpty())
            return;

        ploc = list;
        loc = ploc->next;
        while (loc->data < value && loc != list)
        {
            ploc = loc;
            loc = loc->next;
        }
        if (loc == list && loc->data < value)
        {
            ploc = list;
            loc = NULL;
            return;
        }
        if (loc->data != value)
        {
            loc = NULL;
        }
    }
    void insertedSorted(T data)
    {
        Search(data);
        if (loc != NULL)
        {
            cout << "VALUE EXIST" << endl;
        }
        else
        {
            circluarNode *newnode = new circluarNode();
            newnode->data = data;
            if (isEmpty())
            {

                list = newnode;
                list->next = list;
            }
            else
            {
                newnode->next = ploc->next;
                ploc->next = newnode;
                if (ploc == list)
                {
                    list = newnode;
                }
            }
        }
    }
    void Delete(T data)
    {
        Search(data);
        if (loc != NULL)
        {
            cout << "DELETING THE VALUE :" << endl;

            if (list != list->next)
            {
                ploc->next = loc->next;
                if (loc == list)
                {
                    list = ploc;
                }
                delete loc;
            }
            else
            {
                circluarNode *temp = list;
                delete temp;
                list = NULL;
            }
        }
        else
        {
            cout << "VALUE DOESN'T EXIST" << endl;
        }
    }
    void DestroyList()
    {

        if (!isEmpty())
        {
            circluarNode *temp;
            while (list != list->next)
            {
                temp = list->next;
                list->next = temp->next;
                delete temp;
            }
            delete list;
            list = NULL;
        }
    }
};