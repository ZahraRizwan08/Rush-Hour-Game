//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include <fstream>

using namespace std;


void person1();			//to draw the first person
void person2();			//to draw the second person
void person3();			//to draw the third person

float timer = 0;		//accumlator
int score = 0;
/*void InitRandomizer() {
	srand((unsigned int)time(0)); // time(0) returns number of seconds elapsed since January 1, 1970.
}*/

/*long GetRandInRange(const long &rmin, const long &rmax) {
	long range = rmax - rmin; // find the range
	long value = (rand() % (long)range) + rmin; // translate the generated number ...
	//	cout << value << endl << flush;
	return value;
}*/

/*void passenger()
{

}*/


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 400, yI = 400;
void drawCar() {					//differnent carse senario created for red and yellow car
int car = 0;
switch (car){
case 1:
	DrawSquare(xI, yI, 20, colors[RED]);
	break;
case 0:
	DrawSquare(xI, yI, 20, colors[ORANGE]);
	break;
	}
	glutPostRedisplay();
		
}

int x2 = 500, y2 = 500;
void drawtaxi() {						// drawing the first taxi

	DrawSquare(x2, y2, 20, colors[DARK_SLATE_GRAY]);
	glutPostRedisplay();
		
}

int x3 = 800, y3 = 80;
void drawtaxi2() {					//drawing 2nd taxi in the second place 

	DrawSquare(x3, y3, 20, colors[TURQUOISE]);
	glutPostRedisplay();
		
}

bool flag = true;
void moveCar() {				//this function will move the car1 to the desired destination
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

bool flag1 = true;				//this function will move the car1 to the desired destination
void movetaxi() {
	
	if (x2 >10 && flag1) {
		x2 -= 10;
		cout << "going left";
		if(x2 < 190)
			
			flag1 = false;

	}
	else if (x2 < 900 && !flag1) {
		cout << "go right";
		x2 += 10;
		if (x2 > 500)
			flag1 = true;
	}
}

bool flag2 = true;
void movetaxi2() {			//this function will move the car2 to the desired destination
	
	if (x3 >10 && flag1) {
		x3 -= 10;
		cout << "going left";
		if(x3 < 190)
			
			flag2 = false;

	}
	else if (x3 < 900 && !flag2) {
		cout << "go right";
		x3 += 10;
		if (x3 > 500)
			flag2 = true;
	}
}


/*
 * Main Canvas drawing function.
 * */
int cer =0;
int x = 175, y = 360;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//MISTYWHITE Square(x , y , thickness)
	//this is for the buildings
	
	drawtaxi();
	drawtaxi2();
	
	DrawString( 900, 20, "x = "+to_string(xI), colors[WHITE]);
	DrawString( 800, 20, "y = "+to_string(yI), colors[WHITE]);

	DrawSquare( 700 , 200 ,20,colors[MISTY_ROSE]); 
				
	
	DrawSquare( 910 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 880 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 850 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 820 , 650 ,20,colors[MISTY_ROSE]);
	DrawSquare( 780 , 650 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 740 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 700 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 660 , 650 ,20,colors[MISTY_ROSE]);

 
	DrawSquare( 281 , 650 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 240 , 650 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 200 , 650 ,20,colors[MISTY_ROSE]);
	
	
	DrawSquare( 400 , 450 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 400 , 401 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 400 , 352 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 400 , 304 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 352 , 304 ,20,colors[MISTY_ROSE]);   //line
	DrawSquare( 304 , 304 ,20,colors[MISTY_ROSE]);
	DrawSquare( 256 , 304 ,20,colors[MISTY_ROSE]);    
	DrawSquare( 210 , 304 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 162 , 304 ,20,colors[MISTY_ROSE]);  
	
	DrawSquare( 90 , 130 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 130, 130 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 170 , 130 ,20,colors[MISTY_ROSE]);
	DrawSquare( 210 , 130 ,20,colors[MISTY_ROSE]);    
	DrawSquare( 250 , 130 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 290, 130 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 320 , 130 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 350 , 130 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 390 , 130 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 420 , 130 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 470 , 130 ,20,colors[MISTY_ROSE]); 
	  
	DrawSquare( 520, 620, 20,colors[MISTY_ROSE]);  
	DrawSquare( 520 , 590 ,20,colors[MISTY_ROSE]);
	DrawSquare( 520 , 560 ,20,colors[MISTY_ROSE]);    
	DrawSquare( 520 , 530 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 520, 500 ,20,colors[MISTY_ROSE]);  
 
	DrawSquare( 580, 320 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 580 , 290 ,20,colors[MISTY_ROSE]);
	DrawSquare( 580 , 260 ,20,colors[MISTY_ROSE]);    
	DrawSquare( 580 , 230 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 580, 200 ,20,colors[MISTY_ROSE]); 
	
	DrawSquare( 900 , 45 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 850 , 45 ,20,colors[MISTY_ROSE]);
	DrawSquare( 820 , 45 ,20,colors[MISTY_ROSE]);  
	
	DrawSquare( 90 , 500 ,20,colors[MISTY_ROSE]);
	DrawSquare( 130 , 500 ,20,colors[MISTY_ROSE]);  
	DrawSquare( 170 , 500 ,20,colors[MISTY_ROSE]); 
	
	DrawSquare( 880 , 500 ,20,colors[MISTY_ROSE]); 
	DrawSquare( 840 , 500 ,20,colors[MISTY_ROSE]);
	DrawSquare( 800 , 500 ,20,colors[MISTY_ROSE]);  
	
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	DrawString( 50, 800, " Time =", colors[MISTY_ROSE]);
	
	DrawString( 130, 800, to_string((int)timer), colors[MISTY_ROSE]);
	
	DrawString( 200, 800, " Score =", colors[MISTY_ROSE]);
	
	DrawString( 280, 800, to_string((int)score), colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	/*DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[AQUA] ); */
	
	/*cer++;
	cout << cer<< endl;*/


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 930 , 790 ,  930 , 40 , 10 , colors[MISTY_ROSE] );	
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 90 , 790 ,  90 , 40 , 10 , colors[MISTY_ROSE] );	
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 87 , 790 ,  932 , 790 , 10 , colors[MISTY_ROSE] );	
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 87 , 46 ,  932 , 46 , 10 , colors[MISTY_ROSE] );	
	
	//foR printing lines inside the square
	DrawLine( 140 , 790 ,  140 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 180 , 790 ,  180 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 220 , 790 ,  220 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 260 , 790 ,  260 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 300 , 790 ,  300 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 340 , 790 ,  340 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 380 , 790 ,  380 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 420 , 790 ,  420 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 460 , 790 ,  460 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 500 , 790 ,  500 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 540 , 790 ,  540 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 580 , 790 ,  580 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 620 , 790 ,  620 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 660 , 790 ,  660 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 700 , 790 ,  700 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 740 , 790 ,  740 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 780 , 790 ,  780 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 820 , 790 ,  820 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 860 , 790 ,  860 , 40 , 1 , colors[MISTY_ROSE] );
	DrawLine( 900 , 790 ,  900 , 40 , 1 , colors[MISTY_ROSE] );
	
	//drawing trees
	DrawCircle(250,690,13,colors[LIME_GREEN]);
	DrawSquare(242, 670, 15, colors[SADDLE_BROWN]);
	DrawCircle(900,695,13,colors[LIME_GREEN]);
	DrawSquare(890, 673, 15, colors[SADDLE_BROWN]);
	DrawCircle(118,576,13,colors[LIME_GREEN]);
	DrawSquare(112, 550, 15, colors[SADDLE_BROWN]);
	DrawCircle(368,377,13,colors[LIME_GREEN]);
	DrawSquare(360,352, 15, colors[SADDLE_BROWN]);
	DrawCircle(158,215,13,colors[LIME_GREEN]);
	DrawSquare(152, 190, 15, colors[SADDLE_BROWN]);
	DrawCircle(910,120,13,colors[LIME_GREEN]);
	DrawSquare(902, 95, 15, colors[SADDLE_BROWN]);
	DrawCircle(710,355,13,colors[LIME_GREEN]);
	DrawSquare(702, 330, 15, colors[SADDLE_BROWN]);
	
	//drawing obstelcles
	DrawRoundRect(550,150,10,20,colors[SIENNA],30);
	DrawRoundRect(800,60,10,20,colors[SIENNA],30);
	DrawRoundRect(155,660,10,20,colors[SIENNA],30);
	DrawRoundRect(900,560,10,20,colors[SIENNA],30);
	DrawRoundRect(500,600,10,20,colors[SIENNA],30);
	DrawRoundRect(110,450,10,20,colors[SIENNA],30);
	DrawRoundRect(900,300,10,20,colors[SIENNA],30);
	DrawRoundRect(110,60,10,20,colors[SIENNA],30);
	
	
	
	
	//DrawCircle(280,185,10,colors[AQUA]);
	//DrawRoundRect(275,160,4,12,colors[YELLOW],20);
	//DrawCircle(780,695,10,colors[AQUA]);
//	DrawRoundRect(775,670,4,12,colors[YELLOW],20);
		glutPostRedisplay();
	
	
	/*DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);*/
	
	DrawSquare(280, 670, 20, colors[YELLOW]);
	DrawSquare(900, 760, 20, colors[RED]);
	DrawSquare(170, 520, 20, colors[AQUA]);
	
	drawCar();
	person1();
	 person2();
	 person3();
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)				//all the collisions are taking place here
 {
 
cout << x << " " << y << endl;


	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if((xI-20)==700){
			if(yI==200){
				}
			else{
				xI -= 10;
				}
		}
		else if((xI - 20)==80){
						
		xI += 10;
		score -=2;
		
		}
		
		else if((xI - 20) == 580 && yI <= 320 && yI >= 200 ){
		
								
		xI += 10;
		score -=2;
		}
		
		else if((xI - 20) == 470 && yI == 130 ){
							
		xI += 10;
		score -=2;
		}
		
		else if((xI - 20) == 470 && yI == 130 ){
							
		xI += 10;
		score -=2;
		}
		
		else if((xI - 20) == 400 && yI <= 450 && yI >= 304 ){
		
								
		xI += 10;
		score -=2;
		}
		
		else if((xI - 20) == 520 && yI <= 620 && yI >= 500 ){
		
								
		xI += 10;
		score -=2;
		}
		
	/*	else if((xI - 20) == 281 && yI == 650){
		
								
		xI += 10;
		
		}*/

		else
		{
			xI -= 10;
			
		}
		
	} 
	else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if((xI+20)==700){
			if(yI==200){
				}
			else{
				xI += 10;
				}
		}
		else if((xI + 20)==930){
						
		xI -= 10;
		score -=2;
		}
		
		
		else if((xI + 20) == 580 && yI <= 320 && yI >= 200 ){
		
								
		xI -= 10;
		score -=2;
		}
		
		/*else if((xI + 20) == 400 && yI <= 450 && yI >= 304 ){
		
								
		xI -= 10;
		
		}*/
		
		else if((xI + 20) == 520 && yI <= 560 && yI >= 500 ){
		
								
		xI -= 10;
		score -=2;
		}
		
		
														//for range greater than less than 
		else{
			xI += 10;
			
		}
	}
	else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			if(xI==700){
				if((yI + 20)==200){
				}
			else{
				yI += 10;
				}
		}
		else if((yI + 20)==780){
						
		yI -= 10;
		score -=2;
		}
		
		else if((yI + 20) == 200 && xI == 580 ){
								
		yI -= 10;
		score -=2;
		}
		
		else if((yI + 20) == 130 && xI <= 470 && xI >= 90  ){
		
								
		yI -= 10;
		score -=2;
		}
		
		/*else if((yI + 20) == 304 && xI <= 352 && xI >= 162  ){
		
								
		yI -= 10;
		
		}*/
		
		else if((yI + 20) == 650 && xI <= 910 && xI >= 660 ){
		
								
		yI -= 10;
		score -=2;
		}
		
		else if((yI + 20) == 650 && xI <= 281 && xI >= 200 ){
		
								
		yI -= 10;
		score -=2;
		}
		
													//for range greater than less than 
		else{
			yI += 10;
		}
	}


	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
						if(xI==700){
				if((yI - 20)==200){
				}
				else{
				yI -= 10;
				}
		}
		
		else if((yI - 20) == 40){			
		yI += 10;
		score -=2;
		}
		else if((yI - 20) == 320 && xI == 580 ){
								
		yI += 10;
		score -=2;
		}
		
		else if((yI - 20) == 130 && xI <= 470 && xI >= 90  ){
		
								
		yI += 10;
		score -=2;
		}
		
		/*else if((yI - 20) == 304 && xI <= 350 && xI >= 160  ){
		
								
		yI += 10;
		
		}*/
		
		else if((yI - 20) == 650 && xI <= 910 && xI >= 660 ){
		
								
		yI += 10;
		score -=2;
		}
		
													 
		else{
			yI -= 10;
		}
	}



	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();


}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 
 
 int px = 175, py = 360;
 int px1=320,py1=150;
 int px2 = 800, py2 = 520;								//draws all the people on the board
 void person1()
 	{
 	DrawCircle(px+5,py+25,10,colors[RED]);
	DrawRoundRect(px,py,4,12,colors[YELLOW],20);
	glutPostRedisplay();
	}
	
void person2()
	{
 	DrawCircle(px1+5,py1+25,10,colors[YELLOW]);
	DrawRoundRect(px1,py1,4,12,colors[YELLOW],20);
	glutPostRedisplay();
	}
	
void person3()
	{
 	DrawCircle(px2+5,py2+25,10,colors[AQUA]);
	DrawRoundRect(px2,py2,4,12,colors[YELLOW],20);
	glutPostRedisplay();
	}
	
	
void PrintableKeys(unsigned char key, int x, int y)
	 {					//picking and dropping passengers 
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	//picking
	if(key == 32 /*space bar pressed*/)
		if(xI == 170){
			if(yI == 380){
				px=2000;
				py=2000;
			}
			}
		//dropping	
			if(key == 32 /*space bar pressed*/)
		if(xI == 900){
			if(yI == 760){
				px=xI;
				py=yI;
			}
			score += 10;
			//int v= score; 
			}
		//picking	
		if(key == 32 /*space bar pressed*/)
		if(xI == 320){
			if(yI == 170){
				px1=2000;
				py1=2000;
			}
			}
		//dropping	
			if(key == 32 /*space bar pressed*/)
		if(xI == 280){
			if(yI == 670){
				px1=xI;
				py1=yI;
			}
			score += 10;
			//int u = score;
			}
			//picking
				if(key == 32 /*space bar pressed*/)
		if(xI == 800){
			if(yI == 540){
				px2=2000;
				py2=2000;

			}
			}
		//dropping	
			if(key == 32 /*space bar pressed*/)
		if(xI == 170){
			if(yI == 520){
				px2=xI;
				py2=yI;
				
			}
			score += 10;
			//int z = score;
			}


	if (key == 'o' || key == 'O') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "o pressed" << endl;
			glutDisplayFunc(GameDisplay);

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	//moveCar();
	movetaxi();
	movetaxi2();
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
	timer = timer + 0.2;

int minutes = 180;

while(timer == minutes){
	break;
	}
	
	
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
 
 void menu(){																	//displaying the menu
 		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 400, 800, " Welcome to rush hour", colors[MISTY_ROSE]);
	DrawString( 400, 700, " press o for game", colors[MISTY_ROSE]);
	DrawString( 400, 600, "select the taxi(red or yellow)", colors[MISTY_ROSE]);
	DrawString( 400, 500, "BY : Zahra Rizwan", colors[MISTY_ROSE]);
	DrawString( 400, 400, " press Esc for exit", colors[MISTY_ROSE]);
	
	
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
 }
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	const int size = 10;															//concept of file handing
	int highscores[size];

for(int i =0; i < size; i++)
cin >> highscores[size];

fstream file;
file.open("highscore.txt",ios::out);
	
	if (!file)
	{
		cout << "ERROR!" ;
	}
	else
	{
		cout << "leaderboard" << endl;
		
		for(int i = 0; i < size; i++)
		file << "player" << (i + 1) << "\t\t\t" << highscores[i] ;
		
	}
	
file.close();
file.open("highscore.txt",ios::in);
	
	
	if (!file)
	{
		cout << "ERROR!" ;
	}
	
	else
	{
	 
		string ch;
		while(!(file.eof()))
		{
		file >> ch;
		cout << ch << " " << "\t" << endl;

		}
	}


file.close();


	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Zahra Rizwan"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(menu); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(50.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse


	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */


/*void getpassanger()
{}*/ 
















