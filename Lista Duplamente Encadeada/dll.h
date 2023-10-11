#include <iostream>
#include "node.h"

using std::make_shared;

class DoubleLL
{
private:
    shared_ptr<Node> start;
    shared_ptr<Node> end;
    shared_ptr<Node> trav;
    int size;

    // is_empty
    bool is_empty()
    {
        return start == nullptr || end == nullptr;
    }

    bool is_full()
    {
        return false;
    }

    /* Trav Methods */

    // forward_trav
    void forward_trav(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (trav->get_next() == nullptr)
                return;
            trav = trav->get_next();
        }
    }

    // backward_trav
    void backward_trav(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (trav->get_prev() == nullptr)
                return;
            trav = trav->get_prev();
        }
    }

    // go_to_start_trav
    void go_to_start_trav()
    {
        trav = start;
    }

    // go_to_end_trav
    void go_to_end_trav()
    {
        trav = end;
    }

public:
    DoubleLL() : start(nullptr), end(nullptr), trav(nullptr), size(0) {}

    /* insert Methods */
    void insert_start(int val)
    {
        shared_ptr<Node> newNode = make_shared<Node>(val);

        newNode->set_next(start);
        newNode->set_prev(nullptr);

        if (start != nullptr)
            start->set_prev(newNode);

        start = newNode;

        if (is_empty())
            end = newNode;
        
        trav = newNode;
    }

    // insert_end
    void insert_end(int val)
    {
        shared_ptr<Node> newNode = make_shared<Node>(val);

        newNode->set_next(nullptr);
        newNode->set_prev(end);

        if (!is_empty())
        {
            end->set_next(newNode);
            newNode->set_prev(end);
            end = trav = newNode;
            
        }
        else
        {
            start = end = trav = newNode;
        }
    }

    // insert_after_trav
    void insert_after_trav(int val)
    {

        if (trav == nullptr)
        {
            this->insert_start(val);
            return;
        }

        if (trav->get_next() == nullptr)
        {
            this->insert_end(val);
            return;
        }

        if (trav->get_prev() == nullptr)
        {
            this->insert_start(val);
            return;
        }

        shared_ptr<Node> newNode = make_shared<Node>(val);

        newNode->set_next(trav->get_next());
        newNode->set_prev(trav);
        trav->get_next()->set_prev(newNode);
        trav->set_next(newNode);
        trav = newNode;
    }

    // insert_before_trav
    void insert_before_trav(int val)
    {
        if (trav == nullptr)
        {
            this->insert_start(val);
            return;
        }

        if (trav->get_next() == nullptr)
        {
            this->insert_end(val);
            return;
        }

        if (trav->get_prev() == nullptr)
        {
            this->insert_start(val);
            return;
        }

        shared_ptr<Node> newNode = make_shared<Node>(val);

        newNode->set_next(trav);
        newNode->set_prev(trav->get_prev());
        trav->get_prev()->set_next(newNode);
        trav->set_prev(newNode);
        trav = newNode;
    }

    // insert_position
    void insert_position(int position, int val)
    {
        this->go_to_start_trav();

        int contador = 0;
        while (trav != nullptr && contador < position)
        {
            trav= trav->get_next();
            contador++;
        }

        shared_ptr<Node> newNode = make_shared<Node>(val);

        if (trav != nullptr)
        {
            trav->get_prev()->set_next(newNode);
            newNode->set_prev(trav->get_prev());
            trav->set_prev(newNode);
            newNode->set_next(trav);
            trav = newNode;
        }
    }

    /* delete Methods */
    
    void delete_start()
    {
        start = start->get_next();
        start->set_prev(nullptr);
    }

    void delete_end()
    {
        end = end->get_prev();
        end->set_next(nullptr);
    }

    void delete_trav()
    {
        if (trav == nullptr)
            return;
        if (trav == start)
        {
            delete_start();
            return;
        }
        if (trav == end)
        {
            delete_end();
            return;
        }
        
        trav->get_prev()->set_next(trav->get_next());
        trav->get_next()->set_prev(trav->get_prev());
        trav = trav->get_next();
    }

    void delete_value(int k)
    { // otimizar

        this->go_to_start_trav();

        while (trav->get_value() != k && trav != nullptr)
        {
            this->forward_trav(1);
        }

        if (trav == nullptr)
            return;

        if (trav == start)
        {
            delete_start();
            return;
        }

        if (trav == end)
        {
            delete_end();
            return;
        }

        trav->get_prev()->set_next(trav->get_next());
    }

    void delete_position(int k)
    {
        this->go_to_start_trav();

        for (int i = 0; i < k; i++)
        {
            if (trav == nullptr)
                return;
            trav = trav->get_next();
        }

        if (trav == nullptr)
            return;

        if (trav == start)
        {
            delete_start();
            return;
        }

        if (trav == end)
        {
            delete_end();
            return;
        }

        trav->get_next()->set_prev(trav->get_prev());
        trav->get_prev()->set_next(trav->get_next());
    }

    /* Acess Methods */
    
    int get_trav()
    {
        return trav->get_value();
    }

    /* Support Methods*/
    int position_of_key(int key)
    {
        this->go_to_start_trav();
        
        int i = 1;
        while (trav != nullptr && trav->get_value() != key)
        {
            this->forward_trav(1);
            i++;
        }
        if (trav == nullptr)
            return -1;
    
        return i;
    }

    bool find(int key)
    {
        this->go_to_start_trav();
        while (trav != nullptr && trav->get_value() != key)
        {
            this->forward_trav(1);
        }
        if (trav == nullptr)
            return false;
        return true;
    }
    

    // display
    void display()
    {
        this->go_to_start_trav();
        std::cout << '[';

        while (true)
        {
            std::cout << trav->get_value();
            if (trav->get_next() != nullptr)
            {
                std::cout << ", ";
                this->forward_trav(1);
            }
            else
            {
                std::cout << ']' << '\n';
                break;
            }
        }
    }
};