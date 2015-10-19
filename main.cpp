#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
   {
   QApplication a(argc, argv);
   MainWindow w;
   w.show();
   DNA* MyDNA;
   int i=30;
   while(i-- > 0){
      MyDNA = new DNA;
      delete MyDNA;
      }

   return a.exec();
   }
