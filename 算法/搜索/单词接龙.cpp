/*
我们规定若单词B可以连接在单词A的后面，当且仅当A单词的某个后缀与B单词的某个前缀相同，如apple的一个后缀le和letter的一个前缀le相同，所以letter可以接在apple后面；而ahhhh和qwq不存在某一相同的前缀和后缀，故qwq不能接在ahhhh后面。

  现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），我们规定在两个单词相连时，其最小重叠部分合为一部分，例如 beast和astonish，如果接成一条龙则变为beastonish，再例如atat和atatat，如果接成一条龙则变为atatatat；另外相邻的两部分不能存在包含关系，例如at 和 atide 间不能相连。

Input
  输入的第一行为一个单独的整数n (n≤10)表示单词数，以下n 行每行有一个单词，单词由大写字母和小写字母组成。输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在.且保证每个单词长度m满足(m≤10)

Output
  只需输出以此字母开头的最长的“龙”的长度。每一行结束后均有一个换行。
*/
// dfs

#include<cstdio>
#include<cstring>
struct le//定义结构体可以更方便
{
	char s[22];//单词
	int len;//单词长度
	int v;//单词访问次数
}c[22];//单词数量不超过20个，所以c[22]即可
int n;
int maxn;
void jl(int x,int len)//两个参数分别代表待连接单词的结构体下标和长度
{
	for(int i=1;i<=n;i++)
		if(c[i].v<2)//判断访问次数
			for(int j=0;j<c[x].len;j++)//查待连接单词的每一个字母
				if(c[x].s[j]==c[i].s[0])
				{
					int k=1;//将循环变量定义在外面，方便以后相减
					int t=1;//临时变量（其实bool就行）
					for(int l=j+1;l<c[x].len&&k<c[i].len;k++,l++)//l表示待连接单词下标，k是可连接单词下标，所以在循环条件中需满足它们小于（因为不能包含，所以不能等于）单词长度
						if(c[x].s[l]!=c[i].s[k])
						{
							t=0;
							break;
						}
					if(t)
					{
						c[i].v++;
						jl(i,len+c[i].len-k);//更新长度和下标后递归
						c[i].v--;//完成后一定记得--
					}
				}
	if(len>maxn)
		maxn=len;//不解释
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i].s);
		c[i].len=strlen(c[i].s);
	}
	scanf("%s",c[0].s);
	c[0].len=strlen(c[0].s);//直接将开头字母存在0号结构体
	jl(0,c[0].len);//开头字母当第一个单词处理
	printf("%d\n",maxn);
}