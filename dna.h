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
   void fold(int index);

   // 00 01 10 11
   static inline bool isSame(int a, int b) {return a!=b && a^b;} // same is 1 and 4 , 2 and 3
   static inline bool isDominant(int a) {return a&2 == 0;} //dominant 1 and 2
   static inline bool isRivalry(int a, int b){return a&2 == b&2;}



};

#endif // DNA_H
