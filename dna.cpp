#include "dna.h"

DNA::DNA()
   {
   qsrand(QTime::currentTime().msec());
   setupList();
   }

void DNA::setupList()
   {
   halfLen=0;
   if(!dna.isEmpty()) dna.clear();

   QDebug debug(QtDebugMsg);
   debug.nospace();
   int nextInt=0;
   int n = rand()%35+100;
   dna.append(QList<int>());
   for(int i=0; i<n; i++ ){
      if (nextInt==0) nextInt=rand();
      dna[0].append(nextInt%4);
      //if (i<n/2) dna[0].append(0); //nextInt%4
      //if (i>=n/2) dna[0].append(2);
      nextInt/=4;
      debug << dna.at(0).at(i);
      }
   debug << ' ' << dna.at(0).size();
   debug.~QDebug();
   //qDebug() << *dna.at(0) << _msize(dna.at(0))/sizeof(dna.at(0)[0]);
   fold(0);
   }

void DNA::fold(int index)
   {
   int arrSize = dna.at(index).size();

   int i2,i1;
   int foldPoint = arrSize/2+(arrSize%2);

   i2 = foldPoint;
   i1 = foldPoint - 1;
   dna.append(QList<int>());
   QList<int> *dst = &dna[index+1];
   QList<int> *src = &dna[index];

   if(arrSize==0) return;
   int inc=0;
   while(i1>=0 && i2<arrSize){
      dst->append(combine((*src).at(i1),(*src).at(i2),inc));
      i1-=inc&1;
      i2+=inc>>1&1;
      }
   while(i1>0 || i2<arrSize){
      if (i1>0)
         dst->append((*src).at(i1--));
      if (i2<arrSize)
         dst->append(opposite(src->at(i2++)));
      }


   QDebug debug(QtDebugMsg);
   debug.nospace();
   halfLen += foldPoint;
   for(int t=0; t<halfLen; t++)
      debug << ' ';
   for(int j=0; j<dst->size(); j++){
      debug << dst->at(j);
      }
   debug << ' ' << dna.at(index+1).size();
   debug.~QDebug();
   if (dst->size()>6) fold(dna.size()-1);
   }

int DNA::combine(int a, int b, int &inc)
   {
   int op=3;

   inc=0;
   if (isSame(a,b)){
      inc=3;
      return a;
      }

   if (a==b){
      inc=3;
      return opposite(b);
      }
   op &= isRivalry(a,b) || isDominant(a)<<1;

   switch(op){
      case 0:{inc=2;} return b;
      case 1:{inc=1;} return a;
      case 2:{inc=2;} return b;
      case 3:{inc=1;} return a;
      default: {inc=-1;} return -1;
      }
   }


