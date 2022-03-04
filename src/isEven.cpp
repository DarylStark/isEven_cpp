#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
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

    // Header is created, recompile app
    std::cout << "Done creating the header file! Compiling for you now!" << std::endl;

    // Define the name for the app
    std::stringstream app_name;
    app_name << "isEven_1." << max_value;

    // Compile
    std::stringstream s;
    s << "g++ -Wall -std=c++17 isEven.cpp -o " << app_name.str();
    std::system(s.str().c_str());
    std::cout << "Compiling is done! Rerunning the command :)" << std::endl;

    // Rerun the program
    std::stringstream run;
    run << "./" << app_name.str() << " " << max_value;
    std::system(run.str().c_str());
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
            throw 2;
        }
    }
    return even;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: isEvent <number>" << std::endl;
        return 1;
    }

    // Get the input parameter
    std::stringstream s;
    int nr;

    // Convert it to a integer
    s << argv[1];
    s >> nr;

    // Check if the number is even and give the results
    try
    {
        bool even = isEven(nr);
        if (even)
        {
            std::cout << "The number " << nr << " is even!" << std::endl;
            return 0;
        }

        std::cout << "The number " << nr << " is odd!" << std::endl;
    }
    catch (int &err)
    {
        return err;
    }

    return 0;
}
