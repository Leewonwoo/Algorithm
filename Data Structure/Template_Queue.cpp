#include <vector>
#include <queue>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

namespace templateQexmaple {
    
    template<class T>
    class mNode {
        
    private:
        
        mNode* Next;
        T data;
        
    public:
        
        mNode();
        ~mNode();
        
        void setData(T data);
        T getData();
        void setNext(mNode<T>*);
        mNode* getNext();
        
    };
    
    template<class T>
    mNode<T>::mNode()
    {
        this->data = 0;
        this->Next = nullptr;
    }
    
    template<class T>
    mNode<T>::~mNode<T>(){}
    
    template<typename T>
    T mNode<T>::getData()
    {
        return this->data;
    }
    
    template<typename T>
    mNode<T>* mNode<T>::getNext()
    {
        return this->Next;
    }
    
    template<typename T>
    void mNode<T>::setNext(mNode<T> *_n)
    {
        
        this->Next = _n;
        
    }
    
    template<class T>
    void mNode<T>::setData(T data)
    {
        this->data = data;
    }
    
    template<typename T>
    class mqueue{
        
    private:
        
        T* Head;
        T* Tail;
        int size;
        
    public:
        
        mqueue();
        ~mqueue();
        
        void push(T*);
        T* front();
        T* back();
        void pop();
        int getSize();
        bool isEmpty();
        
    };
    
    template<typename T>
    mqueue<T>::mqueue()
    {
        this->Head = nullptr;
        this->Tail = nullptr;
    }
    
    template<typename T>
    mqueue<T>::~mqueue<T>(){ }
    
    template<typename T>
    T* mqueue<T>::front()
    {
        return this->Head;
    }
    
    template<typename T>
    T* mqueue<T>::back()
    {
        return this->Tail;
    }
    
    template<typename T>
    bool mqueue<T>::isEmpty()
    {
        
        if(this->Head == nullptr)
        {
            return true;
        }
        
        return false;
        
    }
    
    template<typename T>
    void mqueue<T>::push(T* _n)
    {
        
        if(this->Tail == nullptr && this->Head == nullptr)
        {
            this->Tail = _n;
            this->Head = _n;
        }
        else
        {
            this->Tail->setNext(_n);
            this->Tail = this->Tail->getNext();
            this->size++;
        }
    }
    
    template<typename T>
    void mqueue<T>::pop()
    {
        T* del = this->Head;
        this->Head = this->Head->getNext();
        delete del;
        this->size--;
    }
    
}

using namespace templateQexmaple;

int main(void)
{
    
    mqueue<mNode<int>> myQ;
    
    mNode<int>* newData = new mNode<int>();
    
    newData->setData(1);
    newData->setNext(nullptr);
    myQ.push(newData);
    
    newData = new mNode<int>();
    newData->setData(2);
    newData->setNext(nullptr);
    
    myQ.push(newData);
    
    mNode<int>* n = myQ.front();
    
    cout << n->getData()<< endl;
    
    myQ.pop();
    
    n = myQ.front();
    
    cout << n->getData() << endl;
    
    cout << myQ.back()->getData() << endl;
    
    return 0;
    
}



