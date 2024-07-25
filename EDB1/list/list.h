#ifndef LIST_H
#define LIST_H

#include<algorithm>
#include<iostream>

template<typename Object>

class List{
    private:
        struct Node{
            Object data;
            Node* next;
            Node* prev;
           // Node(const Object& d = Object{}, Node* n = nullptr, Node* p = nullptr): data{d}, next{n}, prev{p}{}
            //Node(Object&& d, Node* n = nullptr, Node* p = nullptr): data{std::move(d)}, next{n}, prev{p}{}
            //or ths
            Node(const Object& d = Object{}, Node* p = nullptr, Node* n = nullptr) :
                data{d}, prev{p}, next{n} { }

        };

    public:
    class const_iterator{
        public:
            const_iterator() : current{nullptr}{}

            const Object& operator*() const{
                return retrieve();
            }

            const_iterator& operator++(){
                current = current->next;
                return *this; //sobrescirbing the operator ++ to return the current object
            }
            const_iterator operator++(int){
                const_iterator old = *this;
                ++(*this);
                return old;
            }

            bool operator==(const const_iterator& rhs) const{
                return current == rhs.current;
            }

            bool operator!=(const const_iterator& rhs) const{
                return !(*this == rhs);
            }
        
        protected:
            Node* current;

            Object& retrieve() const{
                return current->data;
            }

            const_iterator(Node* p) : current{p}{}

            friend class List<Object>;

    };

    class iterator : public const_iterator{
        public:
            iterator(){}

            Object& operator*(){
                return const_iterator::retrieve();
            }

            const Object& operator*() const{
                return const_iterator::operator*();
            }

            iterator& operator++(){
                this->current = this->current->next;
                return *this;
            }

            iterator operator++(int){
                iterator old = *this;
                ++(*this);
                return old;
            }

        protected:
            iterator(Node* p) : const_iterator{p}{}

            friend class List<Object>;
    };

    public:
        List();
        List(const List& rhs);
        List& operator=(const List& rhs);
        ~List();

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        int size() const;
        bool empty() const;
        void clear();

        Object& front();
        Object& back();
        const Object& front() const;
        const Object& back() const;

        void push_front(const Object& x);
        void push_front(Object&& x);

        void push_back(const Object& x);
        void push_back(Object&& x);

        void printList() const;

        void pop_front();
        void pop_back();

    private:
        int theSize;
        Node* head;
        Node* tail;

        void init();
        void insert(iterator itr , const Object& x);
        void insert(iterator itr, Object&& x); //Why &&??
        void remove(iterator itr);

        
};

#include "list.cpp"
#endif