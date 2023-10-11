#include "dll.h"

int main()
{
    DoubleLL dll;
    
    for (int i = 0; i <= 10; i++) {
        dll.insert_end(i);
    }

    dll.insert_position(4, 55);
    dll.delete_position(5);
    dll.display();
    return 0;
}
