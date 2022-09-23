
#include "MyException.h"

#include "string"

void CheckNumber (int number)
{
    int counter = 0;

        if ((number < 0))
        {
            throw WrongNumberData();
        }

}
void CheckString (QString str1)
{
    int counter = 0;
    QByteArray ba = str1.toLocal8Bit();
    const char *cstr = ba.data();
    for(int i = 0; i <ba.size(); i++)
    {
        if(!((cstr[i]>='a')&&(cstr[i]<='z')||((cstr[i]>='A')&&(cstr[i]<='Z'))||(cstr[i]=='-')))
 {
            cout<<cstr[i]<<" ";
            throw WrongStringData();
        }
        }}
void CheckSymbol (QString str1)
{
    int counter = 0;
    QByteArray ba = str1.toLocal8Bit();
    const char *cstr = ba.data();
    for(int i = 0; i <ba.size(); i++)
    {
        if(!((cstr[i]=='+')||(cstr[i]=='-')))
 {
            cout<<cstr[i]<<" ";
            throw WrongSymbolData();
        }
        }
}
