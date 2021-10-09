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

char a[101][101]={'\n'}; //초기값 설정; 

void fill(int x,int y) //주변에 같은게 있나 파악하는 함수; 
{
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if(a[x+i][y+j]!='*') //중간이 별인 상태로 주변에 별이 없으면 1더하기; 9개의 점; 
			{
				a[x+i][y+j]++;
			}	
		}
	}
}

int main()
{
	int row=0,col=0;
	int t=0; //field 출력용; 
	
	while(cin>>row>>col)
	{	
		if(row==0&&col==0)
		{
			break;
		}
		
		
		for(int i=1;i<=row;i++) //한번 쓰고나면 안에 값을 초기화; 
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
				c=getchar(); //하나씩 검사; 
				while(c=='\n') //중간에 줄 바뀜이 일어나면; 
				{
					c=getchar(); //다시 한번 검사하기; 
				}
				if(c=='*')
				{
					a[i][j]='*'; //맞으면 안에 별을 입력하고; 
					fill(i,j);	//별 주변의 상태 확인 함수로 보내기; 
				}	
			}
		}
		cout<<"Field # "<<++t<<":"<<endl;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				cout<<a[i][j]; //출력; 
			}
			cout<<endl;  
		}
		if(t>0) //0보다 크면 뛰기; 
		{
			cout<<endl;
		}
	}
return 0;
}

