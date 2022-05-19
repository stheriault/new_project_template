#include "component-1/component-1.hpp"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    //         me
    //        /  \
    //   mother   father
    //      / \
    //   m'm   m'f

    BinaryTree<string> family {
        new Node<string>{"me",
            new Node<string>{"mother",
                new Node<string>{"mother's mother"},
                new Node<string>{"mother's father"}
            },
            new Node<string>{"father"}
        }
    };

    for_each(begin(family), end(family), // Works with STL algo
    [](auto&& n) {
        cout << n.m_value << endl;
    });

    for (const auto& it: family) // Works with range-based for loop as well
        cout << it.m_value << endl;

    return EXIT_SUCCESS;
}
/*  
mother's mother
mother
mother's father
me
father
mother's mother
mother
mother's father
me
father
*/
