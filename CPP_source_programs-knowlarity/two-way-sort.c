#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MaxString = 16;
//16*32*2*1024*1024=1GB
//Two files merged require 2GB RAM
const int BufSize = 2048*1024*32;


typedef char StringType[MaxString];

typedef StringType BufType[BufSize];   // A buffer will hold 2048 strings, for a total of 64K bytes.

#define _MAX_PATH 30
typedef char PathType[_MAX_PATH];


void Error(const string & Msg);

void Error(const string & MsgA, const string & MsgB);

int SortBuffers(fstream & DataFile, PathType FileName);

bool LessThan(StringType First, StringType Second);

void QuickSort(BufType Buf, int Lower, int Upper);

void Swap(StringType First, StringType Second);

int Partition(BufType Buf, int Lower, int Upper);

void Merge(StringType InFileName1, StringType InFileName2, StringType OutFileName);

int PopulateBuffer(fstream & InFile, BufType Buffer, bool & HaveData, StringType NextWord);

void Copy(StringType Word, BufType Buffer, int & Index, fstream & OutFile);

void MergeFiles(int NumFiles, PathType FileName);

char* itoa(int i, char b[],int base);



int main(void)
   {
   PathType FileName;
   fstream DataFile;
   int NumRuns;

   cout << "Enter the name of the text file to be sorted: ";
   cin>>FileName;
   //strcpy(FileName,"str1.txt");
   cout<<" File is "<<FileName<<endl;

   DataFile.open(FileName, ios::in);
   if (DataFile.fail())
      Error("Could not open the file named ", FileName);
   else
      cout<<"File opened successfully"<<endl;

   //kanhaiya
   /*StringType Word, Extension;
   bool MoreData;
   DataFile.getline(Word, MaxString);
   cout<<"String is "<<Word<<endl;
   if (DataFile.fail())
   {
      cout<<"Could not read the file "<<Word<<endl;
      MoreData = false;
   }
   else
   {
      MoreData = true;
      cout<<"String is "<<Word<<endl;
   }
   */

   // Copy sections of the data file into sorted runs.
   //Cut file into smaller parts that can be easily sorted.
   cout<<"Calling SortBuffers"<<endl;
   NumRuns = SortBuffers(DataFile, FileName);
   DataFile.close();

   // Merge the sorted runs until all of the data is in one sorted file (under the original FileName).
   MergeFiles(NumRuns, FileName);

   #ifdef DEBUG
      // Pause so the user can read the debugging messages.
      cout << "Press ENTER: ";
      cin.get();
   #endif

   return 0;
   }


int SortBuffers(fstream & DataFile, PathType FileName)
   {
   cout<<"beginning SortBuffers"<<endl;
   fstream OutFile;
   StringType Word, Extension;
   PathType OutFileName;
   int NumWords, k, NumFiles = 0;
   BufType Buffer;
   //StringType *buf=new StringType[BufSize];//Buffer;
   //BufType &Buffer=*buf;
   bool MoreData;

   // Repeatedly fill one buffer and quicksort it, writing the buffer out to a temp file.
   MoreData=DataFile.getline(Word, MaxString);
   //char str[12];
   //DataFile.getline(Word, 12);
   //DataFile.getline(str, 12);
   MoreData=DataFile.getline(Word, MaxString);
   //if (DataFile.fail())
   if (!MoreData)
   {
      MoreData = false;
   }
   else
   {
      MoreData = true;
   }
   //return 0;
   while (MoreData)
   //while (count<10)
      {
      // Fill one buffer.
      NumWords = PopulateBuffer(DataFile, Buffer, MoreData, Word);
      QuickSort(Buffer, 0, NumWords - 1);
      /*int count=0;
      while(count<10)
      {
         cout<<"Buffer is :"<<Buffer[count]<<endl;
	 count++;
      }*/
      //return 0;
      

      // Construct the temp file name.
      strcpy(OutFileName, "MergTemp.");
      itoa(NumFiles, Extension, 10);   // Convert the int in NumFiles to a char array string.
      strcat(OutFileName, Extension);

      OutFile.open(OutFileName, ios::out);
      if (OutFile.fail())
         Error("Could not open the file named ", OutFileName);

      for (k = 0; k < NumWords; k++)
         OutFile << Buffer[k] << endl;

      OutFile.close();
      NumFiles++;
      }

   return NumFiles;
   }


void MergeFiles(int NumFiles, PathType FileName)
   {
   StringType Extension;
   PathType OutFileName, InFileName1, InFileName2;
   int k, NumPairs, Count;
   bool Odd;

   cout<<"Merging Files"<<endl;
   if (NumFiles == 0)   // No data is present, so there is no work to do.
      return;
   else if (NumFiles == 1)
      {
      remove(FileName);
      rename("MergTemp.0", FileName);

      #ifdef DEBUG
         cout << "Renaming MergTemp.0 as " << FileName << endl;
      #endif

      return;   // The sort is finished.
      }
   else if (NumFiles == 2)
      {
      // Merge the 2 sorted temp files into original file.
      Merge("MergTemp.0", "MergTemp.1", FileName);
      remove("MergTemp.0");
      remove("MergTemp.1");
      return;   // The sort is finished.
      }
   else   // We have 3 or more files.
      {
      // Merge temp files, 2 at a time, until only 2 remain, then proceed as in last case.
      while (NumFiles > 2)
         {
         // Merge MergTemp.0 and MergTemp.1 into MergTempA.0,
         // merge MergTemp.2 and MergTemp.3 into MergTempA.1, etc.
         NumPairs = NumFiles / 2;
         for (k = 0, Count = 0; k < NumPairs; k++)
            {
            strcpy(InFileName1 , "MergTemp.");
            itoa(Count++, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(InFileName2 , "MergTemp.");
            itoa(Count++, Extension, 10);
            strcat(InFileName2, Extension);
            strcpy(OutFileName , "MergTempA.");
            itoa(k, Extension, 10);
            strcat(OutFileName, Extension);
            Merge(InFileName1, InFileName2, OutFileName);
            }
         // If the number of files is odd, just rename the last one.
         if (2 * NumPairs < NumFiles)
            {
            Odd = true;
            strcpy(InFileName1 , "MergTemp.");
            itoa(Count, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(OutFileName , "MergTempA.");
            itoa(NumPairs, Extension, 10);
            strcat(OutFileName, Extension);
            rename(InFileName1, OutFileName);

            #ifdef DEBUG
               cout << "Renaming " << InFileName1 << " as " << OutFileName << endl;
            #endif
            }
         else
            Odd = false;

         // Remove the temp files from before the merge.
         for (k = 0; k < NumFiles; k++)
            {
            strcpy(InFileName1 , "MergTemp.");
            itoa(k, Extension, 10);
            strcat(InFileName1, Extension);
            remove(InFileName1);
            }

         // Get the new number of sorted files.
         NumFiles = NumPairs;
         if (Odd)
            NumFiles++;

         // If number of MergTempA files is now 2, merge them with output to original file and return.
         if (NumFiles == 2)
            {
            Merge("MergTempA.0", "MergTempA.1", FileName);
            remove("MergTempA.0");
            remove("MergTempA.1");
            return;   
            }

         NumPairs = NumFiles / 2;
         for (k = 0, Count = NumFiles - 1; k < NumPairs; k++)
            {
            strcpy(InFileName1 , "MergTempA.");
            itoa(Count--, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(InFileName2 , "MergTempA.");
            itoa(Count--, Extension, 10);
            strcat(InFileName2, Extension);
            strcpy(OutFileName , "MergTemp.");
            itoa(k, Extension, 10);
            strcat(OutFileName, Extension);
            Merge(InFileName1, InFileName2, OutFileName);
            }
         if (2 * NumPairs < NumFiles)
            {
            Odd = true;
            strcpy(InFileName1 , "MergTempA.");
            itoa(0, Extension, 10);
            strcat(InFileName1, Extension);
            strcpy(OutFileName , "MergTemp.");
            itoa(NumPairs, Extension, 10);
            strcat(OutFileName, Extension);
            rename(InFileName1, OutFileName);

            #ifdef DEBUG
               cout << "Renaming " << InFileName1 << " as " << OutFileName << endl;
            #endif
            }
         else
            Odd = false;

         for (k = 0; k < NumFiles; k++)
            {
            strcpy(InFileName1 , "MergTempA.");
            itoa(k, Extension, 10);
            strcat(InFileName1, Extension);
            remove(InFileName1);
            }

         // Get the new number of sorted files.
         NumFiles = NumPairs;
         if (Odd)
            NumFiles++;

         // If number of MergTemp files is now 2, merge them with output to original file and return.
         if (NumFiles == 2)
            {
            Merge("MergTemp.0", "MergTemp.1", FileName);
            remove("MergTemp.0");
            remove("MergTemp.1");
            return;   // The sort is finished.
            }
         }
      }
   }


int PopulateBuffer(fstream & InFile, BufType Buffer, bool & MoreData, StringType NextWord)
   {
   int k = 0;

   while (MoreData && (k < BufSize))
   //while (MoreData && (k < 10))
      {
      strcpy(Buffer[k], NextWord);
      InFile.getline(NextWord, MaxString);
      //cout<<"Buffer[]="<<Buffer[k]<<" and Nextword="<<NextWord<<endl;
      if (InFile.fail())
         MoreData = false;
      else
         MoreData = true;
      
      k++;
      }

   return k;
   }


void Merge(StringType InFileName1, StringType InFileName2, StringType OutFileName)
   {
   fstream InFile1, InFile2, OutFile;
   BufType Buffer1, Buffer2, Buffer3;
   bool HaveData1, HaveData2, MoreData1, MoreData2;
   StringType NextWord1, NextWord2;
   int k, Result, NumWords1, NumWords2, Index1, Index2, Index3 = 0;

   InFile1.open(InFileName1, ios::in);
   if (InFile1.fail())
      Error("Could not open the file named ", InFileName1);

   InFile2.open(InFileName2, ios::in);
   if (InFile2.fail())
      Error("Could not open the file named ", InFileName2);

   OutFile.open(OutFileName, ios::out);
   if (OutFile.fail())
      Error("Could not open the file named ", OutFileName);

   #ifdef DEBUG
      cout << "Merging " << InFileName1 << " and " << InFileName2 << " to " << OutFileName << endl;
   #endif

   InFile1.getline(NextWord1, MaxString);
   if (InFile1.fail())
      MoreData1 = false;
   else
      {
      MoreData1 = true;
      NumWords1 = PopulateBuffer(InFile1, Buffer1, MoreData1, NextWord1);
      }

   InFile2.getline(NextWord2, MaxString);
   if (InFile2.fail())
      MoreData2 = false;
   else
      {
      MoreData2 = true;
      NumWords2 = PopulateBuffer(InFile2, Buffer2, MoreData2, NextWord2);
      }

   Index1 = 0;
   Index2 = 0;
   HaveData1 = MoreData1 || (Index1 < NumWords1);
   HaveData2 = MoreData2 || (Index2 < NumWords2);

   while (HaveData1 && HaveData2)
      {
      if (Index1 == NumWords1)
         {
         NumWords1 = PopulateBuffer(InFile1, Buffer1, MoreData1, NextWord1);
         if (NumWords1 == 0)
            break;   
         else
            Index1 = 0;
         }
      if (Index2 == NumWords2)
         {
         NumWords2 = PopulateBuffer(InFile2, Buffer2, MoreData2, NextWord2);
         if (NumWords2 == 0)
            break;   
         else
            Index2 = 0;
         }

      Result = strcmp(Buffer1[Index1], Buffer2[Index2]);   // case insensitive compare

      if (Result == 0)   // Copy both data items.
         {
         Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
         Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
         Index1++;
         Index2++;
         }
      else if (Result < 0)   // Copy the first data item.
         {
         Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
         Index1++;
         }
      else   // Result > 0, so copy the second data item.
         {
         Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
         Index2++;
         }

      HaveData1 = MoreData1 || (Index1 < NumWords1);
      HaveData2 = MoreData2 || (Index2 < NumWords2);
      }
   
   while (HaveData1)
      {
      if (Index1 == NumWords1)
         {
         NumWords1 = PopulateBuffer(InFile1, Buffer1, MoreData1, NextWord1);
         if (NumWords1 == 0)
            break;   
         else
            Index1 = 0;
         }

      Copy(Buffer1[Index1], Buffer3, Index3, OutFile);
      Index1++;
      HaveData1 = MoreData1 || (Index1 < NumWords1);
      }

   while (HaveData2)
      {
      if (Index2 == NumWords2)
         {
         NumWords2 = PopulateBuffer(InFile2, Buffer2, MoreData2, NextWord2);
         if (NumWords2 == 0)
            break;   
         else
            Index2 = 0;
         }

      Copy(Buffer2[Index2], Buffer3, Index3, OutFile);
      Index2++;
      HaveData2 = MoreData2 || (Index2 < NumWords2);
      }

   // Flush any remaining data from the output buffer.
   for (k = 0; k < Index3; k++)
      OutFile << Buffer3[k] << endl;

   InFile1.close();
   InFile2.close();
   OutFile.close();
   }


void Copy(StringType Word, BufType Buffer, int & Index, fstream & OutFile)
   {
   int k;

   if (Index == BufSize)   // There is no room in Buffer, so first write the Buffer data to OutFile.
      {
      for (k = 0; k < BufSize; k++)
         OutFile << Buffer[k] << endl;
      Index = 0;
      }

   strcpy(Buffer[Index], Word);
   Index++;
   }


inline void Swap(StringType First, StringType Second)
   {
   StringType Temp;

   strcpy(Temp, First);
   strcpy(First, Second);
   strcpy(Second, Temp);
   }


void QuickSort(BufType Buf, int Lower, int Upper)
   {
   int PivotIndex;

   if (Lower < Upper)
      {
      PivotIndex = Partition(Buf, Lower, Upper);
      QuickSort(Buf, Lower, PivotIndex - 1);   // sort left side
      QuickSort(Buf, PivotIndex + 1, Upper);   // sort right side
      }
   }


int Partition(BufType Buf, int Lower, int Upper)
   {
   int Left, Right;
   StringType Pivot;

   strcpy(Pivot, Buf[Lower]);
   Left = Lower;
   Right = Upper;

   while (Left < Right)
      {
      while ((strcmp(Buf[Left], Pivot) <= 0) && (Left < Upper))
         Left++;
      while (strcmp(Buf[Right], Pivot) > 0)
         Right--;
      if (Left < Right)
         Swap(Buf[Left], Buf[Right]);
      }

   strcpy(Buf[Lower], Buf[Right]);
   strcpy(Buf[Right], Pivot);
   return Right;  // return the pivot index
   }



void Error(const string & MsgA, const string & MsgB)
   {
   cout << "Error: " << MsgA << MsgB << endl;
   exit(1);
   }

char* itoa(int i, char b[],int base=10){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ 
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ 
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

