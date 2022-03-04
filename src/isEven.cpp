#include <iostream>
#include <fstream>
#include "isEven.h"

//
// Super efficient example code to determine if a number is even or odd
// Author: Daryl Stark
//         2022-03-04
//

void createHeader(int max_value)
{
    // Method to create the header file with the `_isEven` function
    std::cout << "Creating new 'isEven.h' header file. Computer goes brrrrrr" << std::endl;

    std::ofstream f("isEven.h");

    f << "#ifndef __ISEVEN_H__" << std::endl;
    f << "#define __ISEVEN_H__" << std::endl;
    f << "" << std::endl;
    f << "bool _isEven(int value)" << std::endl;
    f << "{" << std::endl;

    // Magicccccc

    bool current_result = true; // 0 = always a even number!

    for (int i = 0; i <= max_value; i++)
    {
        f << "    if (value == " << i << ") return " << (current_result ? "true" : "false") << ";" << std::endl;
        current_result = !current_result;
    }

    // End magic, just boring static stuff now

    f << "" << std::endl;
    f << "    throw 1;" << std::endl;
    f << "}" << std::endl;
    f << "" << std::endl;
    f << "#endif /* __ISEVEN_H__ */" << std::endl;

    f.close();

    // We're done!
    std::cout << "Done! Please compile, link and run the app again!" << std::endl;
}

template <class T>
bool isEven(T value)
{
    bool even;
    try
    {
        even = _isEven(static_cast<int>(value));
    }
    catch (int &err)
    {
        if (err == 1)
        {
            std::cerr << "Number " << value << " not calculated yet. Header needs to be recreated" << std::endl;
            createHeader(static_cast<int>(value));
        }
    }
    return even;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << isEven(200122) << std::endl;

    return 0;
}
