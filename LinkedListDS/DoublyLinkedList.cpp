#include<iostream>
#include<memory>
#include<string>

using namespace std;

template<typename T>
class Node
{
public:
    T data;
    shared_ptr<Node<T>> next;
    weak_ptr<Node<T>> prev;

    Node(const T& val): data(val), next(nullptr), prev() {}
};

template<typename T>
class linkedList
{
private:
    shared_ptr<Node<T>> head;

public:

    void push_front(const T& val)
    {
        auto new_node = make_shared<Node<T>>(val);
        if(!head)
        {
            head = new_node;
            head->next = head;
            head->prev = head;
        }
        else{
            auto curr_node = head->prev.lock();
            new_node->next = head;
            head->prev = new_node;
            new_node->prev = curr_node;
            curr_node->next = new_node;
            head = new_node;
            
        }
    }

    void push_back(const T& val)
    {
        auto new_node = make_shared<Node<T>>(val);
        if(!head)
        {
            head = new_node;
            head->next = head;
            head->prev = head;
        }
        else{
            auto last_node = head->prev.lock();
            last_node->next = new_node;
            new_node->next = head;
            new_node->prev = last_node;
            head->prev = new_node;
        }
    }

    size_t size()
    {
        if(!head) return 0;
        else{
            int count = 0;
            auto curr_node = head;
            do
            {
                ++count;
                curr_node = curr_node->next;
            } while (curr_node != head);
            return count;
        }
    }

    void pop_front()
    {
        if(!head) return;
        else if(head->next == head) head.reset();
        else
        {
            auto last_node = head->prev.lock();
            head = head->next;
            last_node->next = head;
            head->prev = last_node;
        }
    }

    void pop_back()
    {
        if(!head) return;
        else if(head->next == head) head.reset();
        else
        {
            auto last_node = head->prev.lock();
            auto second_last_node = last_node->prev.lock();
            second_last_node->next = head;
            head->prev = second_last_node;
        }
    }

    bool find(const T& val)
    {
        if(!head) return false;
        auto curr_node = head;
        do
        {
            if(curr_node->data == val)
            {
                return true;
            }
            curr_node = curr_node->next;
        } while (curr_node != head);
        
        return false;
    }

    void erase(const T& val)
    {
        if(!head) cout << "\nThe list is empty\n";
        auto curr_node = head;

        do
        {
            if(curr_node->data == val)
            {
                auto prev_node = curr_node->prev.lock();
                auto next_node = curr_node->next;

                prev_node->next = next_node;
                next_node->prev = prev_node;

                if(curr_node == head)
                {
                    if(head->next = head)
                    {
                        head.reset();
                    }
                    else
                    {
                        head = head->next;
                    }
                }
            return;
            }
            curr_node = curr_node->next;
        } while (curr_node != head);
        
    }

    void print_list()
    {
        if(!head) return;
        auto curr_node = head;
        do
        {
            cout << curr_node->data << " ";
            curr_node = curr_node->next;
        } while (curr_node != head);
        
    }

    void print_backward()
    {
        if(!head) return;
        auto curr_node = head->prev.lock();
        auto last_node = head->prev.lock();
        do
        {
            cout << curr_node->data << " ";
            curr_node = curr_node->prev.lock();
        } while (curr_node != last_node);
    }

};


int main()
{

    linkedList<string> l1;

    l1.push_front("Farrukh");
    l1.push_front("Naveed");
    l1.push_back("Arfa");

    l1.print_list();
    cout << "\n";
    l1.print_backward();

    l1.pop_front();

    cout << "\n";
    l1.print_list();



    return 0;
}