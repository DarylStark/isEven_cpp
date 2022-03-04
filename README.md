# isEven for C++

This algorithm calculates if a number is _even_ or _odd_ in C++. A number is _even_ when it comes after 1 but before 3, after 3 but before 5, after 5 but before 7, andsoforth. This code is absolute amazing since it can calculate the _evenness_ for every number (except negatives, that's still on my TODO list in Outlook).

## Project structure

In the `src` folder are the source files; the `getEven.cpp` is the main C++ program which includes a the `isEven.h` header. This header gets changed during runtime if a number is requested that is not yet calculated by my efficient algorithm. When the file gets changed, the programm will be recompiled automatically.

## Compile instructions

To compile the application using the GCC compiler, run the following commands;

```bash
cd src/
g++ -std=c++17 isEven.cpp -o isEven
```

You can then run the program as follows:

```bash
./isEven <number>
```

The program will immidiatly display if the number is _even_ or _odd_. If the number is not defined yet, it will adjust the header and recompile the application and rerun the application so you can still get the needed result.

If you use a different compiler then GCC, please refer to the documentation of the used compiler. I'm too busy writing cool stuff like this to document how to compile on other platforms.

## License

I haven't yet found a good license for this software, so please just don't steal my code for your own projects untill I found a good license. If you want to suggest a license, please send me a PM. If you work for a big company like Facebook, Amazon, Netflix or Google and want to buy this project to increase the efficiency in your codebase, please PM me with a decent offer. Anything with less then 9 figures is not acceptable!

## Disclaimer

_I cannot stress this enough: this is a __joke__ project!_