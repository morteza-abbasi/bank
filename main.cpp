#include "view_bank.h"
#include <QApplication>
#include<bank.h>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    string address="C:/Users/red   pc/Documents/HM4/EXM.txt";//enter address txt file for information
    bank.load_information_as_file(address);
    QApplication a(argc, argv);
    view_bank w;

    w.show();

    return a.exec();
}

