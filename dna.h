#ifndef DNA_H
#define DNA_H

#include <QList>
#include <QVector>
#include <QStringList>
#include <QTime>
#include <QtGlobal>
#include <QDebug>

class DNA
{
public:
   QList<int*> dna;

   DNA();

   void setupList();
   void fold(QString str);

   static bool equal(int a , int b);
   static bool equal(QChar a , QChar b);
};

#endif // DNA_H
