

#include "stdio.h"
#include "iostream.h"
#include "stdlib.h"
#include "math.h"

// ª½®| is 723 ¶ê©P is¡@2271.37148855 
#define PI 3.14159265
#define Size 723 // diameter is 723
#define InputH 723
#define H 361
#define W 2272 
 
using namespace std;

int main( int argc, char *argv[])
{
	FILE *file;
	unsigned char Imagedata[Size][Size];
	
						/************************************************/
						/******                                	 ******/
						/****** Read "input.raw" into Imagedata[][]******/
						/******                                	 ******/
						/************************************************/							
	if (!(file=fopen("sample2.raw","rb"))){
		cout<<"Cannot open file!"<<endl;
		exit(1);
	}
	fread(Imagedata, sizeof(unsigned char), Size*Size, file);
	fclose(file);


	/**********************************	do some image processing task... ***/
	unsigned char output[Size][Size];
	unsigned char pano[361][2272];
	int i = 0, j = 0;
	float theta = 0.0;
	float temp = 0.0;
	int r = 0;
	int temp1 = 0;
	int temp2 = 0;
	int u, v = 0;
	float uu, vv = 0;
						/********************************************/
						/******                                ******/
						/******       ******/
						/******                                ******/
						/********************************************/	
	

	for( i = 1; i < 360; i++ ){
		printf("\n");
		for( j = 1; j < 2200; j++ ){
			
			temp = ( 2 * PI ) / W;
			theta = ( 2 * PI ) - j * temp; 
			//theta = theta * PI / 180;
			r = 361 - i;
			temp1 = (int) ( r * cos( theta ) );
			temp2 = (int) ( r * sin( theta ) );
			//printf("   %d", r );
			u = temp1 + 361;
			v = 732 - ( temp2 + 361 );
			
			pano[i][j] = static_cast<unsigned char>(Imagedata[u][v]);
			
		}
		
	}	//		End-1-for
	
	
	/******************************************************    M   *
	
	for( i =0; i < H; i++ ){
		for( j = 0; j < 361; j++ ){
			
			output[i][j] = static_cast<unsigned char>(Imagedata[i][j]);
		}
		
	}	//		End-1-for
	/*******************************************************/

theta = 360 - 99* ( 360 / W );
printf("\n\n%f", cos(theta) );


		

						/********************************************/
						/******                                ******/
						/******    write image to "ouput.raw"  ******/
						/******                                ******/
						/********************************************/		
	if (  !(file=fopen("panorama.raw","wb"))  ){
		cout<<"Cannot open file!"<<endl;
		exit(1);
	}
	else{
		fwrite(pano, sizeof(unsigned char), 361*2272, file);
		fclose(file);
	}



	system("PAUSE");
	exit(0);
}

