#include <iostream>
using namespace std;

template <class T>
class singlyNode
{
public:
    T data;
    singlyNode<T> *next;
    explicit singlyNode(T val)
    {
        data = val;
        next = nullptr;
    }
};
template <class T>
class linkedList
{
public:
    singlyNode<T> *head;
    singlyNode<T> *tail;
    singlyNode<T> *ploc;
    singlyNode<T> *loc;

    linkedList()
    {
        head = nullptr;
        tail = nullptr;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isempty() const
    {
        return head == nullptr;
    }

    T length() const
    {
        singlyNode<T> *temp = head;
        T n = 0;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }

    void insetAtHead(T val)
    {
        singlyNode<T> *newnode<T> = new singlyNode(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtTail(T val)
    {
        singlyNode<T> *newnode<T> = new singlyNode(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtPos(T val, T idx)
    {
        if (idx == 0)
        {
            insetAtHead(val);
        }
        else if (idx == length() - 1)
        {
            insertAtTail(val);
        }
        else
        {
            singlyNode<T> *newnode<T> = new singlyNode(val);
            singlyNode<T> *temp = head;
            for (T i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            singlyNode<T> *n = temp->next;
            temp->next = newnode;
            newnode->next = n;
        }
    }

    void printll() const
    {
        singlyNode<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    T search(T val) const
    {
        singlyNode<T> *temp = head;
        T idx = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void delidx(T idx)
    {
        if (idx == 0)
        {
            singlyNode<T> *k = head;
            head = head->next;
            delete k;
            return;
        }
        else if (idx == length() - 1)
        {
            singlyNode<T> *temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            singlyNode<T> *todel = temp->next;
            tail = temp;
            tail->next = nullptr;
            delete todel;
            return;
        }
        singlyNode<T> *temp = head;
        for (T i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        singlyNode<T> *n = temp->next;
        temp->next = temp->next->next;
        delete n;
    }

    void delval(T val)
    {
        T didx = search(val);
        if (didx == -1)
        {
            return;
        }
        delidx(didx);
    }

    void destroy()
    {
        T i = 0;
        while (i < length())
        {
            delidx(i);
        }
        head = nullptr;
        tail = nullptr;
    }

    void insertSorted(T val)
    {
        singlyNode<T> *temp = head;
        T n = 0;
        while (temp->data < val)
        {
            if (temp->next == nullptr)
            {
                insertAtTail(val);
                return;
            }
            temp = temp->next;
            n++;
        }
        insertAtPos(val, n);
    }
};