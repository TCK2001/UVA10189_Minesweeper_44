/*
Sample Input
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
Sample Output
Field #1:
*100
2210
1*10
1110
Field #2:
**100
33200
1*100
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

char a[101][101]={'\n'}; //�ʱⰪ ����; 

void fill(int x,int y) //�ֺ��� ������ �ֳ� �ľ��ϴ� �Լ�; 
{
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if(a[x+i][y+j]!='*') //�߰��� ���� ���·� �ֺ��� ���� ������ 1���ϱ�; 9���� ��; 
			{
				a[x+i][y+j]++;
			}	
		}
	}
}


int main()
{
	int row=0,col=0;
	int t=0; //field ��¿�; 
	
	while(cin>>row>>col)
	{	
		if(row==0&&col==0)
		{
			break;
		}
		
		
		for(int i=1;i<=row;i++) //�ѹ� ������ �ȿ� ���� �ʱ�ȭ; 
		{
			for(int j=1;j<=col;j++)
			{
				a[i][j]='0';	
			}
		}
		
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				char c;
				c=getchar(); //�ϳ��� �˻�; 
				while(c=='\n') //�߰��� �� �ٲ��� �Ͼ��; 
				{
					c=getchar(); //�ٽ� �ѹ� �˻��ϱ�; 
				}
				if(c=='*')
				{
					a[i][j]='*'; //������ �ȿ� ���� �Է��ϰ�; 
					fill(i,j);	//�� �ֺ��� ���� Ȯ�� �Լ��� ������; 
				}	
			}
		}
		cout<<"Field # "<<++t<<":"<<endl;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				cout<<a[i][j]; //���; 
			}
			cout<<endl;  
		}
		if(t>0) //0���� ũ�� �ٱ�; 
		{
			cout<<endl;
		}
	}
return 0;
}

