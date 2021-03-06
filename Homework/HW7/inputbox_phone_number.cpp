#include "inputbox_phone_number.h"
#include <QDebug>
InputBox_phone_number::InputBox_phone_number()
{

}

static int __validate_length(QString n)
{
    return (8 <= n.length() && n.length() <= 13) ? 0:-1;
}

static int __validate_beging_char(QString n)
{
    if (n.at(0) == QString("+") || n[0].isDigit())
        return 0;
    return -1;
}

static int __validate_char(QString n)
{
    for(int i = 1; i< n.length(); i++)
    {
        if (!n[i].isDigit())
            return -1;
    }
    return 0;
}

int InputBox_phone_number::__validate_phone_number(QString n)
{
    int rev;

    if ((rev = __validate_length(n)) == -1) return rev;
    if ((rev = __validate_beging_char(n)) == -1) return rev;
    return __validate_char(n);
}
