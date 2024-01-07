#include <iostream>
#include <windows.h>
using namespace std;

int towerA[3] = {3, 2, 1}, towerB[3] = {}, towerC[3]  = {};
int maks = 3, topA = 2, topB = -1, topC = -1;
bool boolA = true, boolB = true, boolC = false;
int data_temp = 0;

void pushArr(int *top, int tower_destination[]);
int stackTop(int *top, int tower[]);
void popArr(int *top, int tower[]);
void printTower();

int main()
{
	printTower();
	bool go_to_towerC = false, end = false, main_loop = true;
	while(main_loop)
	{
		while(boolA)
		{
//		cout << "A" << topA << topB << topC <<endl;
		data_temp = stackTop(&topA, towerA);
		if(topB == -1 || stackTop(&topB, towerB) > stackTop(&topA, towerA) && stackTop(&topA, towerA) != 0)
		{
			popArr(&topA, towerA);
			pushArr(&topB, towerB);
		}
		
		else if(topC == -1 || stackTop(&topC, towerC) > stackTop(&topC, towerC) && stackTop(&topA, towerA) != 0)
		{
			popArr(&topA, towerA);
			pushArr(&topC, towerC);
		}
		
		else if(topA == -1 || stackTop(&topB, towerB) < stackTop(&topA, towerA) && stackTop(&topC, towerC) < stackTop(&topA, towerA))
		{
			boolA = false;
			if(go_to_towerC)
			{
				boolC = true;
			}
			else if(end)
			{
				main_loop = false;
			}
		}
		cout << "A" << topA << topB << topC <<endl;
		printTower();
		Sleep(1000);
		}
		
		while(boolB)
		{
			data_temp = stackTop(&topB, towerB);
//			cout << "B1" << topA << topB << topC << " " << data_temp <<endl;
			if(topC == -1 || stackTop(&topC, towerC) > stackTop(&topB, towerB) && stackTop(&topB, towerB) != 0)
			{
				popArr(&topB, towerB);
				pushArr(&topC, towerC);
				
			}
			
			else if(topA == -1 || stackTop(&topA, towerA) > stackTop(&topB, towerB) && stackTop(&topB, towerB) != 0)
			{
				popArr(&topB, towerB);
				pushArr(&topA, towerA);
			}
			
			if(topB == -1 || stackTop(&topC, towerC) < stackTop(&topB, towerB) || stackTop(&topA, towerA) < stackTop(&topB, towerB))
			{
				boolA = true;
				boolB = false;
				go_to_towerC = true;
			}
			
			cout << "B" << topA << topB << topC <<endl;
			printTower();
			
			Sleep(1000);
		}
		
		
		while(boolC)
		{
		data_temp = stackTop(&topC, towerC);
		if(topA == -1 || stackTop(&topA, towerA) > stackTop(&topC, towerC) && stackTop(&topC, towerC) != 0)
		{
			popArr(&topC, towerC);
			pushArr(&topA, towerA);
		}
		
		else if(topB == -1 || stackTop(&topB, towerB) > stackTop(&topC, towerC) && stackTop(&topC, towerC) != 0)
		{
			popArr(&topC, towerC);
			pushArr(&topB, towerB);
		}
		
		else if(topC =-1 || stackTop(&topA, towerA) < stackTop(&topC, towerC) && stackTop(&topB, towerB) < stackTop(&topC, towerC))
		{
			
			boolA = true;
			boolB = false;
			boolC = false;
			end = true;
			go_to_towerC = false;
		}
		cout << "C" << topA << topB << topC <<endl;
		printTower();
		Sleep(1000);
		}
	}
	return 0;
}

void printTower()
{
	int i = 0;
	cout << "TowerA : ";
	for(i = 0; i < 3; i++)
	{
		cout << towerA[i] << " ";
	}
	
	cout << "\nTowerB : ";
	for(i = 0; i < 3; i++)
	{
		cout << towerB[i] << " ";
	}
	
	cout << "\nTowerC : ";
	for(i = 0; i < 3; i++)
	{
		cout << towerC[i] << " ";
	} 	
	cout << "\n\n";
}

void pushArr(int *top, int tower_destination[])
{
	//push dilakukan jika stack belum penuh
	if(*top < maks)
	{
		//lakukan push data
		*top = *top + 1; //menambah indek array
		tower_destination[*top] = data_temp;
		
	}
	else
	{
		return;
	}
}

int stackTop(int *top, int tower[])
{
	//data hanya bisa dilihat jika stack tidak kosong
	if(*top != -1)
	{
		return tower[*top];
	}
	else
	{
		return 0;
	}
}

void popArr(int *top, int tower[])
{
	//pop hanya dilakukan jika stack tidak kosong
	if(*top > -1)
	{
		data_temp = tower[*top];
		tower[*top] = 0;
		*top = *top - 1; //*top -= 1;
		
	}
	else
	{
		return;
	}
}
