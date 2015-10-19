#include "dna.h"

DNA::DNA()
   {
   qsrand(QTime::currentTime().msec());
   setupList();
   }

void DNA::setupList()
   {
   QDebug debug(QtDebugMsg);
   debug.nospace();
   int nextInt=0;
   int n = rand()%15+25;
   int* tempArr = new int[n];

   for(int i=0; i<n; i++){
      if (nextInt==0) nextInt=rand();
      tempArr[i] = nextInt%4;
      nextInt/=4;
      debug << tempArr[i];
      }
   debug.~QDebug();
   dna.append(tempArr);
   qDebug() << *dna.at(0) << _msize(dna.at(0))/sizeof(dna.at(0)[0]);
   }

void DNA::fold(QString str)
   {

   }

bool DNA::equal(int a, int b)
   {
   if (a<4 && b<4) return a^b;
   return -1;
   }
