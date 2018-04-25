// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
void loadImage();
void saveImage();
void invertimage();
void flipimage();
void rotateimage();
void enlarge();
void savepic();
void Black_White();
unsigned char image [256][256][3];
unsigned char newImage [256][256][3];
unsigned char photo [256][256][3];
unsigned char c;




void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}



void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}


void savepic () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, photo);
}
void Black_White()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for (int k = 0; k< RGB; k++)
            {
                if (((image[i][j][0]+image[i][j][1]+image[i][j][2])/3)<127)
                    photo[i][j][k]=0;
                else
                    photo[i][j][k]=255;
            }

        }
    }
}



void invertimage () {
    for (int x=0;x<256;x++){
        for (int y=0;y<256;y++){
            for (int z=0;z<3;z++){
                image[x][y][z]=255-image[x][y][z];
            }
        }
    }
}





void flipimage(){
       for (int x=0;x<256/2;x++){
        for (int y=0;y<256;y++){
            for (int z=0;z<3;z++){
                    c=image[x][y][z];
                    image[x][y][z]=image[256-1-x][y][z];
                    image[256-1-x][y][z]=c;
            }}}}
void flipimage2(){
       for (int x=0;x<256;x++){
        for (int y=0;y<256/2;y++){
            for (int z=0;z<3;z++){
                    c=image[x][y][z];
                    image[x][y][z]=image[x][256-1-y][z];
                    image[x][256-1-y][z]=c;
            }}}}



void rotateimage(){
    int O=256-1;
       for (int x=0;x<256;x++){
        for (int y=0;y<256;y++){
            for (int z=0;z<3;z++){
            newImage[x][y][z]=image[x][y][z];
        }
    }}
      for (int x=0;x<256;x++){
        for (int y=0;y<256;y++){
          for (int z=0;z<3;z++){
            image[x][y][z]=newImage[y][O][z];
        }
}
O=O-1;
}}



void enlarge (){
    int g;
    cout<<"Please , enter number of the part you want to save \n [1 for the left part upward] \n [2 for right part upward] \n [3 for the left part downward] \n [4 for the right part downward]"<<endl;
    cin>>g;
    int col=0;
    int row=0;
   //int thick=0;
     if (g==1){
   //for (int z=0;z<3;z++){
     for ( int x=0; x < 256; x+=2 ){
            col = 0;
        for ( int y=0; y < 256; y+=2){
           // for (int z=0 ; z < 3; z++){

                photo[ x ][ y ][ 0 ]  = image[row][col][0];
                photo[ x ][y+1][ 0 ]  = image[row][col][0];
                photo[x+1][ y ][ 0 ]  = image[row][col][0];
                photo[x+1][y+1][ 0 ]  = image[row][col][0];
                photo[ x ][ y ][ 1 ]  = image[row][col][1];
                photo[ x ][y+1][ 1 ]  = image[row][col][1];
                photo[x+1][ y ][ 1 ]  = image[row][col][1];
                photo[x+1][y+1][ 1 ]  = image[row][col][1];
                photo[ x ][ y ][ 2 ]  = image[row][col][2];
                photo[ x ][y+1][ 2 ]  = image[row][col][2];
                photo[x+1][ y ][ 2 ]  = image[row][col][2];
                photo[x+1][y+1][ 2 ]  = image[row][col][2];
                col++;

            }
            row++;

        }

        }



       else if (g==4){
        int col=0;
        int row = 256 / 2;
        for ( int x = 0; x < SIZE; x += 2 ){
            col = 256 / 2;
            for ( int y = 0; y < SIZE; y += 2){
                photo[ x ][ y ][ 0 ]  = image[row][col][0];
                photo[ x ][y+1][ 0 ]  = image[row][col][0];
                photo[x+1][ y ][ 0 ]  = image[row][col][0];
                photo[x+1][y+1][ 0 ]  = image[row][col][0];
                photo[ x ][ y ][ 1 ]  = image[row][col][1];
                photo[ x ][y+1][ 1 ]  = image[row][col][1];
                photo[x+1][ y ][ 1 ]  = image[row][col][1];
                photo[x+1][y+1][ 1 ]  = image[row][col][1];
                photo[ x ][ y ][ 2 ]  = image[row][col][2];
                photo[ x ][y+1][ 2 ]  = image[row][col][2];
                photo[x+1][ y ][ 2 ]  = image[row][col][2];
                photo[x+1][y+1][ 2 ]  = image[row][col][2];
                col++;

            }
            row++;
        }
     }
     else if (g==2){
       for ( int x = 0; x < SIZE ; x += 2 ){
            col = SIZE / 2 ;

            for ( int y = 0; y < SIZE ; y += 2){

                photo[ x ][ y ][ 0 ]  = image[row][col][0];
                photo[ x ][y+1][ 0 ]  = image[row][col][0];
                photo[x+1][ y ][ 0 ]  = image[row][col][0];
                photo[x+1][y+1][ 0 ]  = image[row][col][0];
                photo[ x ][ y ][ 1 ]  = image[row][col][1];
                photo[ x ][y+1][ 1 ]  = image[row][col][1];
                photo[x+1][ y ][ 1 ]  = image[row][col][1];
                photo[x+1][y+1][ 1 ]  = image[row][col][1];
                photo[ x ][ y ][ 2 ]  = image[row][col][2];
                photo[ x ][y+1][ 2 ]  = image[row][col][2];
                photo[x+1][ y ][ 2 ]  = image[row][col][2];
                photo[x+1][y+1][ 2 ]  = image[row][col][2];
                col++;

            }
            row++;
        }

     }
     else if (g==3){
      int row = SIZE / 2;
      int col=0;
        for ( int x = 0; x < SIZE; x += 2 ){
            col = 0;
            for ( int y = 0; y < SIZE; y += 2){

                photo[ x ][ y ][ 0 ]  = image[row][col][0];
                photo[ x ][y+1][ 0 ]  = image[row][col][0];
                photo[x+1][ y ][ 0 ]  = image[row][col][0];
                photo[x+1][y+1][ 0 ]  = image[row][col][0];
                photo[ x ][ y ][ 1 ]  = image[row][col][1];
                photo[ x ][y+1][ 1 ]  = image[row][col][1];
                photo[x+1][ y ][ 1 ]  = image[row][col][1];
                photo[x+1][y+1][ 1 ]  = image[row][col][1];
                photo[ x ][ y ][ 2 ]  = image[row][col][2];
                photo[ x ][y+1][ 2 ]  = image[row][col][2];
                photo[x+1][ y ][ 2 ]  = image[row][col][2];
                photo[x+1][y+1][ 2 ]  = image[row][col][2];
                col++;

            }
            row++;
        }}}
void Detect_Image_Edges()
{
    Black_White();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; ) {
                for (int k=0; k<RGB; k++){
            if (image[i][j][k]==image[i+1][j+1][k])
            {
                while(true&&j<SIZE)
                {
                    if((image[i][j][0]+image[i][j][1]+image[i][j][2])/3!=(image[i][j+1][0]+image[i][j+1][1]+image[i][j+1][2])/3||(image[i+1][j][0]+image[i+1][j][1]+image[i+1][j][2])/3!=(image[i][j][0]+image[i][j][1]+image[i][j][2])/3)
                        ///if(cimage[i][j][k]!=cimage[i][j+1][k]||cimage[i+1][j][k]!=cimage[i][j][k])
                    {
                        image[i][j][0]=0;
                        image[i][j][1]=0;
                        image[i][j][2]=0;
                    }

                    else
                    {
                        image[i][j][0]=255;
                        image[i][j][1]=255;
                        image[i][j][2]=255;
                    }
                    j++;
                }
            }
            else
            {
                image[i][j][0]=255;
                image[i][j][1]=255;
                image[i][j][2]=255;
                j++;
            }
        }
      }
    }
}

int main (){
cout<<"Ahlan ya user ya habibi \n"
<<"Please enter file name of the image to process :\n"
<<"Please select a filter to apply \n"
<<"1-invert image \n"
<<"2-flip image \n"
<<"3-rotate image\n"
<<"4-Enlarge image \n"
<<"5-black and white\n"
<<"6-detact image \n";
int choice;
cin>>choice;
if (choice==1){
    loadImage();
    invertimage();
    saveImage();
}
else if (choice==2){
    loadImage();
    int x;
    cout<<"1-horizontal , 2- vertical ";
    cin>>x;
    if (x==1)
    {
        flipimage();
    }
    if (x==2)
    {
        flipimage2();
    }

    saveImage();
}
else if (choice==5)
{
    loadImage();
    Black_White();
    savepic();
}
else if (choice==3){
cout<<"rotate image : \n1-90 degree\n2-180 degree\n3-270 degree\n";
int degree;
cin>>degree;
if (degree==1){
    loadImage();
    rotateimage();
    saveImage();
}
else if (degree==2){
    loadImage();
    rotateimage();
    rotateimage();
    saveImage();
}
else if (degree==3){
    loadImage();
    rotateimage();
    rotateimage();
    rotateimage();
    saveImage();
}
}
else if (choice==4){
    loadImage();
    enlarge();
    savepic();
}
else if (choice==6)
{
    loadImage();
    Detect_Image_Edges();
    saveImage();
}



}
