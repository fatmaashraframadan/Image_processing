// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <conio.h>

using namespace std;

unsigned char colored[256][256][3];
unsigned char temp[256][256][3];

char imageFileName[100];

void loadImage();
void saveImage();
void invertimage ();
void rotateimage();
void Enlargeimage();
void darken_lighten_Image();
void black_whiteImage();
int main()
{
    while(true){
    loadImage();
    cout << "Select the filter you want to apply or 0 to exist. \n1-Black and White filter. \n2-Invert filter. \n3-Darken and Lighten Image. \n4-Rotate image. \n5-Enlarge image." << endl;
    char mode;
    cin >> mode;
    switch(mode){
    case '1':
        black_whiteImage();
        saveImage();
        break;

    case '2':
        invertimage ();
        saveImage();
        break;

    case '3':
        darken_lighten_Image();
        break;

    case '4':
        rotateimage();
        break;

    case '5':
       Enlargeimage();
       break;

    case '0':
        return 0;
    }
    cout << "\nPress any key to continue... ";

    getch();
    system("cls");
  return 0;
}
}


//_______________________________________________________
void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, colored);

}

//________________________________________________________
void saveImage () {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeRGBBMP( imageFileName,colored);

}

//_______________________________________________________
void invertimage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            for(int x=0 ; x<3 ;x++)
            {
              colored[i][j][x]=255-colored[i][j][x];
            }
        }
  }writeRGBBMP( "test.bmp",colored);

}
void rotateimage ()
{
    int m , mode ;
    cout<<"how do you want to rotate the image??\n1-rotate 90 degree.\n2-rotate 180 degree.\n3-rotate 270 degree."<<endl;
    cin>>mode;
    if(mode==1){
        for (int i = 0; i < (SIZE); i++){
            for (int j =i+1; j< (SIZE); j++) {
                    for(int x=0 ;x<3 ;x++)
                    {
                         swap(colored[i][j][x],colored[j][i][x]);
                    }

            }
        }
        for (int i = 0; i < SIZE; i++ ){
            for (int j = 0; j < SIZE/2; j += 1){
                    for(int x=0 ; x<3 ;x++)
                    {
                        swap(colored[j][i][x], colored[SIZE-j-1][i][x]);
                    }
            }
        }saveImage();
    }
    if(mode==2)
    {
        for(int i=0 ;i<SIZE/2 ;i++)
        {
            for(int j=0 ;j<SIZE ;j++)
            {
                for(int x=0; x<3 ;x++)
                {
                    m=colored[i][j][x];
                    colored[i][j][x]=colored[SIZE-1-i][SIZE-1-j][x];
                    colored[SIZE-1-i][SIZE-1-j][x]=m;
                }

            }
        }saveImage();
    }
    if(mode==3)
    {
        for (int i = 0; i < (SIZE); i++){
            for (int j =i+1; j< (SIZE); j++) {
                    for(int x=0 ;x<3 ;x++)
                    {
                        swap(colored[i][j][x],colored[j][i][x]);
                    }

            }
        }
        for (int i = 0; i < SIZE; i++ ){
            for (int j = 0; j < SIZE/2; j += 1){
                    for(int x=0 ;x<3 ;x++)
                    {
                         swap(colored[j][i][x], colored[SIZE-j-1][i][x]);
                    }

            }
        }
        for(int i=0 ;i<SIZE/2 ;i++)
        {
            for(int j=0 ;j<SIZE ;j++)
            {
                for(int x=0 ; x<3 ;x++)
                {
                     m=colored[i][j][x];
                    colored[i][j][x]=colored[SIZE-1-i][SIZE-1-j][x];
                    colored[SIZE-1-i][SIZE-1-j][x]=m;
                }

            }
        }


    }saveImage();
}
//____________________________________________________________________
void Enlargeimage()
{
    int choose;
    cout<< "choose \n"<< "1-first quarter \n"<< "2-second\n"<< "3-third \n"<< "4-fourth \n";
    cin>> choose;
    if (choose==1){

    for(int i=0 ,k=0 ; i<SIZE/2 ; i++ , k+=2)
    {
        for(int j=0,n=0 ;j<SIZE/2 ; j++ ,n+=2)
        {
            for(int x=0; x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];

            }

        }saveImage();
    }
    writeRGBBMP("test1.bmp", temp);
    }
    if (choose==2)
    {
        for(int i=0 ,k=0 ; i<SIZE/2 ; i++ , k+=2)
    {
        for(int j=SIZE/2,n=0;j<SIZE ; j++ ,n+=2)
        {
            for(int x=0;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];
            }

        }
    }
    writeRGBBMP("test2.bmp", temp);
    saveImage();

    }

if (choose==3){
        for(int i=SIZE/2 ,k=0 ; i<SIZE ; i++ , k+=2)
    {
        for(int j=0,n=0;j<SIZE/2 ; j++ ,n+=2)
        {
            for(int x=0 ;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][256-j][x];
                temp[k+1][n][x]=colored[i][256-j][x];
                temp[k][n+1][x]=colored[i][256-j][x];
                temp[k+1][n+1][x]=colored[i][256-j][x];
            }

        }
    }
    writeRGBBMP("test3.bmp", temp);
    saveImage();
}

if (choose==4){
        for(int i=SIZE/2 ,k=0 ; i<SIZE ; i++ , k+=2)
    {
        for(int j=SIZE/2,n=0;j<SIZE ; j++ ,n+=2)
        {
            for(int x=0 ;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];
            }

        }
    }
    writeRGBBMP("test4.bmp", temp);
    saveImage();
}
}
//_______________________________________________________________________
void darken_lighten_Image() {

        int operation;
        for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                 for(int k=0; k<3 ;k++)
                 {
                     if (operation==1)
                 {
                     colored[i][j][k]=(colored[i][j][k])/2;
                 }
                 if (operation==2)
                 {
                        if (colored[i][j][k]<=127 )
                       {
                          colored[i][j][k]=(colored[i][j][k])+70;
                       }
                        else if (colored[i][j][k]<=255)
                        {
                           colored[i][j][k]=(colored[i][j][k]);
                        }

                 }
                 }

             }
          }
}
//_________________________________________________________________________
void black_whiteImage() {

    for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                for(int k=0 ;k<3 ; k++)
                {
                    if (colored[i][j][k]>=127)
                        colored[i][j][k]=255;
                    else
                        colored[i][j][k]=0;
                }

             }

          }


}
