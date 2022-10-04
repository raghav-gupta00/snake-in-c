//Snake game for windows terminal
//Doesn't work in linux terminal due to issues with conio.h library

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

int i,j,height=25,width=25,gameover,score;
int x,y,foodx,foody,flag;

void draw(){

	//Draws the box 

	for(i=0;i<height;i++){

		for(j=0;j<width;j++){

			if(i==0 || i==(width-1) || j==0 || j==(height-1)) {
				printf("$");
			}

			else {
				 printf(" ");
			}
		}
		printf("\n");
	}
}


void setup(){

	//Sets up the food

	gameover=0;

	x=height/2;
	y=width/2;

label1:
	foodx=rand()%25;
	if (foodx==0)
		goto label1;

label2: 
	foody=rand()%25;
	if (foody==0)
		goto label2;

	score=0;

}

void input()
{

		//Takes input from keyboard

	if(kbhit()){

		switch(getch())

		{
			case'a':
				flag=1;
				break;

			case's':
				flag=2;
				break;

			case'd': 
				flag=3;
				break;

			case'w':
				flag=4;
				break;

			case'x':
				gameover=1;
				break;
		}
	}
}
					

void logic(){


	sleep(0.01);
	switch(flag)
	{

	case 1:
		y--;
		break;
	

	case 2:
		x++;
		break;

	case 3:
		y++;
		break;
	
	case 4: 
		x--;
		break;

	default:
		break;

	}


	if(x<0 || x>height || y<0 || y>width)
		gameover=1;

	if(x==foodx && y==foody)
	{

	label3:
		foodx=rand()%25;

		if(foodx==0)
			goto label3;
	label4:

		foody=rand()%25;

		if(foody==0)
			goto label4;
		score+=10;


	}


}

int main(){

	int m,n;
	sleep();

	while(!gameover)
	{
	draw();
	input();

	logic();


	}
	

}

