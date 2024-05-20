#include <iostream>
using namespace std;

template<class T>
class List
{
public:

    List();
    ~List();

    void clear();
    void pop_front();
    void pop_back();
    void pushBack(T data);
    void pushFront(T data);
    void insert (T data, int index);
    void removeAt(int idex);
    int getSize(){return Size;}
    T& operator[](const int index) &;

private:

    template<class T1>
    class Node
    {
    public:

        Node* pNext;
        T1 data;

        Node(T1 data = T1(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;
};

template<class T>
List<T>::List()
{
    Size =0;
    head = nullptr;
}

template<class T>
List<T>::~List()
{
    clear();
}

template<class T>
void List<T>::pushBack(T data)
{
    if(head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size ++;
}

template<class T>
void List<T>::pushFront(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<class T>
void List<T>::pop_back()
{
    removeAt(Size -1);
}

template<class T>
void List<T>::insert(T data, int index)
{
    if(index == 0)
    {
        pushFront(data);
    }
    else
    {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
}

template <class T>
T& List<T>::operator[](const int index) &
{
    int counter = 0;
    Node<T> *current = this->head;

    while(current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    throw std::out_of_range("out of range");
}

template <class T>
void List<T>::pop_front()
{
    Node<T> *temp = head;

    head = head->pNext;

    delete temp;

    Size --;
}

template <class T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

template<class T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node<T> *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }

}

int main()
{
    List<int> lst;
    lst.pushBack(1);
    lst.pushBack(9);
    lst.pushBack(101);

    for (int i = 0; i < lst.getSize(); ++i)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "Elements count: " << lst.getSize() << "\tWork remove." << endl;

    lst.removeAt(0);

    for (int i = 0; i < lst.getSize(); ++i)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "Elements count: " << lst.getSize() << endl;

    return 0;
}
