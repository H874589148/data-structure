#include <windows.h>

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

/******************************************************************

Name:              qqzone.c
Auther:            Hawkeye
Date:             2018.10.16
Function:     贪吃蛇，含有windows.h的图形界面贪吃蛇程序
 
******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

char gamemap[20][40];//游戏地图大小 20*40
int score=0;//当前分数
//记录蛇的结点
int x[800];//每个结点的行编号
int y[800];//每个结点的列编号
int len = 0;//蛇的长度
//记录水果信息
 int fx=0;//食物的横坐标
 int fy=0;//食物的纵坐标
 int fcount=0;//食物的数目
 //主要函数操作
void createfood();//生成食物
void PrintgameMap(int x[],int y[]);//画游戏地图
void move(int x[],int y[]);//移动蛇
int main()
{
 srand(time(NULL));
 //初始化蛇头和身体的位置,默认刚开始蛇长为2
 x[len] = 9;
 y[len] = 9;
 len++;
 x[len] = 9;
 y[len] = 8;
 len++;
 createfood();
 PrintgameMap(x,y);
 move(x,y);
 return 0;
}
void createfood()
{
 if(0==fcount)
 {
 int tfx=rand()%18+1;
 int tfy=rand()%38+1;
 int i,j;
 int have=0;//为0表示食物不是食物的一部分
 for(i=0;i<len;i++)
 {
 for(j=0;j<len;j++)
 {
 if(x[i]==fx&&y[j]==fy)
 {
 have=1;
 break;
 }
 else
 {
 have=0;
 }
 }
 if(1==have)//若为蛇的一部分，执行下一次循环
 {
 continue;
 }
 else//否则生成新的水果
 {
 fcount++;
 fx=tfx;
 fy=tfy;
 break;
 }
 }
 }
}
//游戏地图
void PrintgameMap(int x[],int y[])
{
 int snake = 0,food=0;
 int i, j;
 //画游戏地图,并画出蛇的初始位置
 for (i = 0; i < 20; i++)
 {
 for (j = 0; j < 40; j++)
 {
 if (i == 0 && j >= 1 && j <= 38)
 {
 gamemap[i][j] = '=';
 }
 else if (i == 19 && j >= 1 && j <= 38)
 {
 gamemap[i][j] = '=';
 }
 else if (j == 0 || j == 39)
 {
 gamemap[i][j] = '#';
 }
 else
 {
 gamemap[i][j] = ' ';
 }
 //判断蛇是否在当前位置
 int k;
 for ( k = 0; k < len; k++)
 {
 if (i == x[k]&&j == y[k])
 {
 snake = 1;
 break;
 }
 else
 {
 snake = 0;
 }
 }
 {
 if(fcount&&fx==i&&fy==j)
 {
 food=1;
 }
 else
 {
 food=0;
 }
 }
 //若蛇在当前位置
 if (1==snake )
 {
 printf("*");
 }
 else if(1==food)
 {
 printf("f");
 }
 //若蛇不在当前位置并且当前位置没有水果
 else
 {
 printf("%c", gamemap[j]);
 }
 }
 printf("\n");
 }
 printf("score:%d",score);
}
//移动
void move(int x[],int y[])
{
 char s;
 s=getch();
 int move=0,beat=0;
 while (1)
 {
 int cx[800];
 int cy[800];
 memcpy(cx, x, sizeof(int)*len);
 memcpy(cy, y, sizeof(int)*len);
 //头
 if (s=='w')
 {
 x[0]--;
 move=1;
 if(x[0]<=0)
 {
 printf("Game over\n");
 break;
 }
 }
 else if (s=='s')
 {
 x[0]++;
 move=1;
 if(x[0]>=19)
 {
 printf("Game over\n");
 break;
 }
 }
 else if (s=='a')
 {
 y[0] --;
 move=1;
 if(y[0]<=0)
 {
 printf("Game over\n");
 break;
 }
 }
 else if (s=='d')
 {
 y[0]++;
 move=1;
 if(y[0]>=39)
 {
 printf("Game over\n");
 break;
 }
 }
 //身体
 int i;
 for ( i = 1; i < len; i++)
 {
 x = cx;
 y = cy;
 }
 for(i=1;i<len;i++)//要是咬到了自己
 {
 if(x[0] == x && y[0] == y)
 {
 beat=1;
 }
 else
 {
 beat=0;
 }
 }
 if(1==beat)
 {
 printf("Game over\n");
 break;
 }
 if(1==move)
 {
 if(fcount&&x[0]==fx&&y[0]==fy)//如果吃到了果子
 {
 //拷贝当前蛇头地址到第二个结点
 memcpy(x+1,cx,sizeof(int)*len);
 memcpy(y+1,cy,sizeof(int)*len);
 len++;
 fcount--;
 fx=0;
 fy=0;
 score++;
 createfood();
 }
 Sleep(70);
 system("cls");
 PrintgameMap( x, y);
 }
 else
 continue;
 if(kbhit())//判断是否按下按键
 {
 s=getch();
 }
 }
}
