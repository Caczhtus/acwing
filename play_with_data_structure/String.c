//T为非空串，若主串S中第pos个字符之后存在与T相等的子串，则返回这样的第一个子串在S中的位置，否则返回0；
int Index(String S, String T, int pos)
{
    int n=StrLength(S);
    int m=StrLength(T);
    String sub;
    while(pos++<=n-m+1)
    {
        SubString(sub, S, i, m);
        if(StrCompare(sub, T)==0) return pos;
    }
    return 0;
}


//朴素的模式匹配算法
//返回子串T在主串S中第pos个字符之后的位置，若不存在，则函数返回值为0;
//其中T非空，1<= ps <= StrLength(S)
//注意我们假设S和T的长度保存在S[0]和T[0]中
int Index(String S, String T, int pos)
{
    while(pos<=S[0] && int i<=T[0])
    {
        if(S[pos++]==T[i++]);
        else pos=pos-i+2, i=1;
    }
    if(i>T[0]) return pos-T[0];
    else return 0;
}

//KMP算法


//通过计算返回子串的next数组，next数组存放对于子串字符冲突后，需要移动j的位置;
//next数组的定义，next[i]为1～i-1的子串的使得前k-1个字符等于后k-1个字符的的最大的K
void get_next(String T, int* next)
{
    next[1]=0;
    int i=1,k=0;
    while(i<T[0])
    {
        if(k==0 || T[i]==T[k]) i++,k++,next[i]=k;
        else k=next[k];
    }
}

//接下来是KMP算法主体
//返回子串T在主串S中的第pos个字符之后的位置，若不存在，则函数返回0
//T非空，1<= pos <=StrLength(S)
int Index_KMP(String S, String T, int pos)
{
    int next[255];
    int i=pos, j=1;
    while(i<=S[0] && j<=T[0])
    {
        if(j==0 || S[i]=T[j]) i++,j++;
        else j=next[j];
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}


//KMP算法还有改进空间，即对于next函数的改进
void get_nextval(String T, int* nextval)
{
    nextval[1]=0;
    int i=1,k=0;
    while(i<T[0])
    {
        if(k==0 || T[i]=T[k])
        {
            i++;
            k++;
            if(T[i]!=T[k]) nextval[i]=k;
            else nextval[i]=nextval[k];
        }
        else k=nextval[k];
    }
}