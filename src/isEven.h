#ifndef __ISEVEN_H__
#define __ISEVEN_H__

bool _isEven(int value)
{
    if (value == 0) return true;
    if (value == 1) return false;
    if (value == 2) return true;

    throw 1;
}

#endif /* __ISEVEN_H__ */