#include <bits/stdc++.h>
using namespace std;
string ans[6]={"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};
const int posx[]={1,2,3,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4,1,2,4};
const int posy[]={1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		ans[posx[i]][posy[i]*2-1]='O';
	for(int i=0;i<6;i++)
		cout<<ans[i]<<endl;
	return 0;
}