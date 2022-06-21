//Tenzin Wangyal
//assignment 8
//program will store infromation in classes and all those class info
//will be stored in another class.The program is gonna read in info given in a file
//and print them.the program will also search for two infos.
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

ifstream fin("input8.txt");
ofstream fout("output8.txt");

class artistInfo{
  public:
        string first;
        string last;
        };

class genreInfo{
  public:
        string genre;
        };
class labelInfo{
  public:
        string company;
        string year;
        };

class CDcollection{
  public:
        string title;
        artistInfo artist;
        genreInfo type;
        labelInfo label;

        };

void readata(CDcollection [],int&);
void printall(CDcollection [],int& );
//void sorts(CDcollection  [],int& );
int findartist(CDcollection [],int&,string);


int main()
{
      CDcollection CDs[100];
      int n,num,pos;
      string singer;

      readata(CDs,n);
      printall(CDs,n);
      fin>>singer;
      pos=findartist(CDs,n,singer);
      if(pos!=-1)
           fout<<singer<<" found in position "<<pos<<endl;
      else
           fout<<singer<<" not found"<<endl;
      fin>>singer;
      pos=findartist(CDs,n,singer);
      if(pos!=-1)
           fout<<singer<<" found in position "<<pos<<endl;
      else
           fout<<singer<<" not found"<<endl;

      fin.close();
      fout.close();

      return 0;
}


//void readata will read info from an input file
void readata(CDcollection CDs [],int& n)
{
      fin>>n;
      for(int i=0;i<n;i++)
      {
            fin>>CDs[i].title;
            fin>>CDs[i].artist.first;
            fin>>CDs[i].artist.last;
            fin>>CDs[i].type.genre;
            fin>>CDs[i].label.company;
            fin>>CDs[i].label.year;
      }
      return;
}

//void printall will print all the info send to the main from readata fucntion
void printall(CDcollection CDs [],int&n )
{
      for(int i=0;i<n;i++)
      {
            fout<<"The title of the album is: "<<CDs[i].title<<endl;
            fout<<"The first name of the artist is: "<<CDs[i].artist.first<<endl;
            fout<<"The last name of the artist is: "<<CDs[i].artist.last<<endl;
            fout<<"The genre of the song is: "<<CDs[i].type.genre<<endl;
            fout<<"The record label is: "<<CDs[i].label.company<<endl;
            fout<<"The year the song relased is: "<<CDs[i].label.year<<endl<<endl;
      }
      return;
}


/*
//void sorts will sort the last name in alphabetical order
void sorts(CDcollection CDs [],int& n)
{

      CDcollection temp;

      for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                  if(CDs[i].artist.last>CDs[j].artist.last)
                  {
                        temp=CDs[i].artist.last;
                        CDs[i].artist.last=CDs[j].artist.last;
                        CDs[i].artist.first=temp;


                        temp=CDs[i].artist.first;
                        CDs[i].artist.first=CDs[j].artist.first;
                        CDs[i].artist.first=temp;
                  }

}
*/

//findartist will find the info that is being search and return it to the main
int findartist(CDcollection CDs [],int & n,string singer)
{
      for(int i=0;i<=n;i++)
            if(singer==CDs[i].artist.last)
                  return i;

            return -1;

}

