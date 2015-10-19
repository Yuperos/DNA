#include "dna.h"

DNA::DNA()
   {
   qsrand(QTime::currentTime().msec());
   int i=0;
   setupList();
   }

void DNA::setupList()
   {
   //if(!dna.isEmpty()) dna.clear();

   QDebug debug(QtDebugMsg);
   debug.nospace();
   int nextInt=0;
   int n = rand()%35+35;
   int* tempArr = new int[n];
   for(int i=0; i<n; i++ ){
      if (nextInt==0) nextInt=rand();
      tempArr[i] = nextInt%4;
      nextInt/=4;
      debug << tempArr[i];
      }
   debug.~QDebug();
   dna.append(tempArr);
   //qDebug() << *dna.at(0) << _msize(dna.at(0))/sizeof(dna.at(0)[0]);
   fold(0);
   }

void DNA::fold(int index)
   {
   int *src,*dst;
   src = dna.at(index);
   int arrSize = _msize(dna.at(index))/sizeof(dna.at(index)[0]);
   dst = new int[arrSize*2];

   int i=0;
   int i1=arrSize/2-1;
   int i2=arrSize/2;
   if(i==arrSize) return;
   while(i1>=0 && i2<arrSize){
      if (*(src+i1) == *(src+i2) && (i1>0 && i2<arrSize)){
         //collect function needed here
         int usedEqualMetod = 0;
         switch(usedEqualMetod){
            case 0: {
               dst[i++] = *(src+i2);
               dst[i++] = ~*(src+i2) & 3;
               i1--;
               i2++;
               } break;
            case 1: {
               } break;
            }
         continue;
         }
      if (isSame(*(src+i1),*(src+i2))) {
         dst[i++] = *(src+i1);
         i1--;
         i2++;
      }else{
         //swap priority needed here
         if (isRivalry(*(src+i1),*(src+i2)) && *(src+i1) != *(src+i2)){
            dst[i++] = *(src+i1);
            i1--;
         }else{
            if (isDominant(*(src+i1))){
               dst[i++] = *(src+i1);
               i1--;
            }else{
               dst[i++] = *(src+i2);
               i2++;
               }
            }
         }


      }
   while(i1>0 || i2<arrSize){
      if (i1>0)
         dst[i++] = *(src+i1--);
      if (i2<arrSize)
         dst[i++] = ~*(src+i2++) & 3;
      }
   int *newDst = new int[i];
   QDebug debug(QtDebugMsg);
   //debug.nospace();
   for(int j=0; j<i; j++){
      *(newDst+j)=*(dst+j);
      debug << *(dst+j);
      }
   delete[] dst;
   debug.~QDebug();
   dna.append(newDst);
   if (i>6) fold(dna.size()-1);
   }


