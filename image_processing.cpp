#include <bits/stdc++.h>
#include "bmplib.cpp"
#include <conio.h>

using namespace std;

void loadImage();
void saveImage();
void black_whiteImage();
void darken_lighten_Image();
void Enlargeimage1();
void Enlargeimage2();
void Enlargeimage3();
void Enlargeimage4();
void invertimage();
void rotate_image90();
void rotate_image180();
void rotate_image270();
void shuffle();

unsigned char image[256][256];

int main()
{

  while(true){
    loadImage();
    cout << "Select the filter you want to apply or 0 to exist. \n1-Black and White filter. \n2-Invert filter. \n3-Darken and Lighten Image. \n4-Rotate image. \n5-Enlarge image. \n6-Shuffle image" << endl;
    char mode;
    cin >> mode;
    switch(mode){
    case '1':
        black_whiteImage();
        saveImage();
        break;

    case '2':
        invertimage();
        saveImage();
        break;

    case '3':
        char operation;
        cout<<" choice 1 - if you want to darken "<<endl;
        cout<<" choice 2 - if you want to lighten "<<endl;
        cin>>operation;
        darken_lighten_Image();
        break;

    case '4':
        int rotateimage;
        cout<<"how do you want to rotate the image??\n1-rotate 90 degree.\n2-rotate 180 degree.\n3-rotate 270 degree."<<endl;
        cin>>rotateimage;
        if(rotateimage==1)
        {
            rotate_image90();
            saveImage();
        }
        else if (rotateimage==2)
        {
            rotate_image180();
            saveImage();
        }
        else if(rotateimage==3)
        {
            rotate_image270();
            saveImage();
        }

        break;

    case '5':
        int enlargeimage;
        cout<< "choose \n"<< "1-first quarter \n"<< "2-second\n"<< "3-third \n"<< "4-fourth \n";
        cin>> enlargeimage;
        if(enlargeimage==1)
        {
             Enlargeimage1();
             saveImage();
        }
        if(enlargeimage==2)
        {
          Enlargeimage2();
          saveImage();
        }
        if(enlargeimage==3)
        {
          Enlargeimage3();
          saveImage();
        }
        if(enlargeimage==4)
        {
          Enlargeimage4();
          saveImage();
        }

        //goto loop;
        break;
    case '6':
        shuffle();
        saveImage();
        //goto loop;
        break;


    case '0':
        return 0;
    }
    cout << "\nPress any key to continue... ";

    getch();
    system("cls");
}
}
//________________________________________________
void loadImage(){
   char imageFileName[100];
   cout << "Enter the name of the image: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
//_________________________________________________
void saveImage(){
   char imageFileName[100];
   cout << "Enter the new image name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
//__________________________________________________
void invertimage() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j< 256; j++) {

// Example code to invert the image

        image[i][j]=255-image[i][j];

// do something with the image
    }
  }
}
//__________________________________________________
void blackAndWhite(){
    int sum=0;
    for(int i=0 ; i<256 ; i++){
        for(int j=0 ; j<256 ; j++){
            sum += (int)image[i][j];
        }
    }
    int average = sum / (256*256);

    for(int x=0 ; x<256 ; x++){
        for(int y=0 ; y<256 ; y++){
            if((int)image[x][y] > average){
                image[x][y] = (char)(255);
            }else if((int)image[x][y] < average){
                image[x][y] = (char)(0);
            }
        }
    }
}
//__________________________________________________
void black_whiteImage() {

          for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                // do something with the image
                if (image[i][j]>=127)
                    image[i][j]=255;
                else
                   image[i][j]=0;
             }

          }


}
//__________________________________________________
void darken_lighten_Image() {

        int operation;
        for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                 if (operation==1)
                 {
                     image[i][j]=(image[i][j])/2;
                 }
                 if (operation==2)
                 {
                        if (image[i][j]<=127 )
                       {
                          image[i][j]=(image[i][j])+70;
                       }
                        else if (image[i][j]<=255)
                        {
                           image[i][j]=(image[i][j]);
                        }

                 }
             }
          }
}

//___________________________________________________
void rotate_image90 ()
{
    int x ;
    for (int i = 0; i < 256; i++){
            for (int j =i+1; j< 256; j++) {
                swap(image[i][j],image[j][i]);
            }
        }
    for (int i = 0; i < 256; i++ ){
            for (int j = 0; j < 256/2; j += 1){
                swap(image[j][i], image[256-j-1][i]);
            }
        }
}
//________________________________________________
void rotate_image180 ()
{
    int x;
    for(int i=0 ;i<256/2 ;i++)
        {
            for(int j=0 ;j<256 ;j++)
            {
                x=image[i][j];
                image[i][j]=image[256-1-i][256-1-j];
                image[256-1-i][256-1-j]=x;
            }
        }
}
//________________________________________________
void rotate_image270()
{
    int x;
    for (int i = 0; i < (256); i++){
            for (int j =i+1; j< (256); j++) {
                swap(image[i][j],image[j][i]);
            }
        }
    for (int i = 0; i < 256; i++ ){
            for (int j = 0; j < 256/2; j += 1){
                swap(image[j][i], image[256-j-1][i]);
            }
        }
    for(int i=0 ;i<256/2 ;i++)
        {
            for(int j=0 ;j<256 ;j++)
            {
                x=image[i][j];
                image[i][j]=image[256-1-i][256-1-j];
                image[256-1-i][256-1-j]=x;
            }
        }

}
//_______________________________________________
void Enlargeimage1()
{
    unsigned char temp[256][256];
    for(int i=0 ,k=0 ; i<256/2 ; i++ , k+=2)
    {
        for(int j=0,n=0;j<256/2 ; j++ ,n+=2)
        {
            temp[k][n]=image[i][j];
            temp[k+1][n]=image[i][j];
            temp[k][n+1]=image[i][j];
            temp[k+1][n+1]=image[i][j];
        }
    }
}
//_______________________________________________
void Enlargeimage2()
{
     unsigned char temp[256][256];

     for(int i=0 ,k=0 ; i<256/2 ; i++ , k+=2)
        {
        for(int j=256/2,n=0;j<256 ; j++ ,n+=2)
            {
            temp[k][n]=image[i][j];
            temp[k+1][n]=image[i][j];
            temp[k][n+1]=image[i][j];
            temp[k+1][n+1]=image[i][j];
            }
        }
}
//_______________________________________________
void Enlargeimage3()
{
    unsigned char temp[256][256];
    for(int i=256/2 ,k=0 ; i<256 ; i++ , k+=2)
    {
        for(int j=0,n=0;j<256/2 ; j++ ,n+=2)
        {
            temp[k][n]=image[i][j];
            temp[k+1][n]=image[i][j];
            temp[k][n+1]=image[i][j];
            temp[k+1][n+1]=image[i][j];
        }
    }
}
//_________________________________________________
void Enlargeimage4()
{
    unsigned char temp[256][256];

    for(int i=256/2 ,k=0 ; i<256 ; i++ , k+=2)
    {
        for(int j=256/2,n=0;j<256 ; j++ ,n+=2)
        {
            temp[k][n]=image[i][j];
            temp[k+1][n]=image[i][j];
            temp[k][n+1]=image[i][j];
            temp[k+1][n+1]=image[i][j];
        }
    }

    for(int i=0 ; i<256 ; i++){
        for(int j=0 ; j<256 ; j++){
            image[i][j] = temp[i][j];
        }
    }
}
//__________________________________________
void shuffle(){
    loop:
    int x1, x2, x3, x4;
    cout << "Enter the order of the shuffle that you want" << endl;
    cin >> x1 >> x2 >> x3 >> x4;
    unsigned char temp[256][256];
    if(x1 == 1){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j] = image[i][j];
            }
        }
    }else if(x1 == 2){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j] = image[i][j+128];
            }
        }
    }else if(x1 == 3){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j] = image[i+128][j];
            }
        }
    }else if(x1 == 4){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j] = image[i+128][j+128];
            }
        }
    }else{
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if(x2 == 1){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j+128] = image[i][j];
            }
        }
    }else if(x2 == 2){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j+128] = image[i][j+128];
            }
        }
    }else if(x2 == 3){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][j+128] = image[i+128][j];
            }
        }
    }else if(x2 == 4){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i][128] = image[i+128][j+128];
            }
        }
    }else{
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if(x3 == 1){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j] = image[i][j];
            }
        }
    }else if(x3 == 2){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j] = image[i][j+128];
            }
        }
    }else if(x3 == 3){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j] = image[i+128][j];
            }
        }
    }else if(x3 == 4){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[+128][j] = image[i+128][j+128];
            }
        }
    }else{
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if(x4 == 1){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j+128] = image[i][j];
            }
        }
    }else if(x4 == 2){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j+128] = image[i][j+128];
            }
        }
    }else if(x4 == 3){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j+128] = image[i+128][j];
            }
        }
    }else if(x4 == 4){
        for(int i=0 ; i<128 ; i++){
            for(int j=0 ; j<128 ; j++){
                temp[i+128][j+128] = image[i+128][j+128];
            }
        }
    }else{
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    for(int i=0 ; i<256 ; i++){
        for(int j=0 ; j<256 ; j++){
            image[i][j] = temp[i][j];
        }
    }
}
