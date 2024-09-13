#include<stdio.h>
#include<string.h>
int main()
{
    char c[300]={'\0'},t[20];
    int i,j,k=1,l,e,n=0,w=0,x,y,z;
    gets(c);
    for(i=0;c[i]!='\0';i++)
    {
        if(c[i]==' ')w=0;
        else if(w==0)
        {
            w=1;
            n++;
        }
    }
    char d[n+1][20],f[n+1],r[n+1];
    for(x=1,y=0,i=0;c[i]!='\0';i++)
    {
        if(c[i]!=' ')
        {
            d[x][y]=c[i];
            y++;
        }
        if(c[i]==' '&&c[i-1]!=' ')
        {
            d[x][y]='\0';
            x++;
            y=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(z=0,j=1;j<=k;j++)
        {
            if(i==r[j])
            {
                f[i]=0;
                z=1;
            }
        }
        if(z!=1)
        {
            for(f[i]=1,j=i+1;j<=n;j++)
            {
                if(strcmp(d[i],d[j])==0)
                {
                    f[i]++;
                    r[k]=j;
                    k++;
                }
            }
        }
    }
    for(i=1;i<n;i++)
    {
        e=i;
        for(j=i+1;j<=n;j++)
            if(f[j]>f[e])e=j;
        l=f[i];
        f[i]=f[e];
        f[e]=l;
        strcpy(t,d[i]);
        strcpy(d[i],d[e]);
        strcpy(d[e],t);
    }
    for(i=1;i<n;i++)
    {
        e=i;
        if(f[e]!=0)
        for(j=i+1;j<=n;j++)
            if(f[j]==f[e])
            {
                if(d[e][0]<=90)
                    if(d[j][0]>90)e=j;
            }
        l=f[i];
        f[i]=f[e];
        f[e]=l;
        strcpy(t,d[i]);
        strcpy(d[i],d[e]);
        strcpy(d[e],t);
    }
    for(i=1;i<n;i++)
    {
        e=i;
        if(f[e]!=0)
        for(j=i+1;j<=n;j++)
            if(f[j]==f[e])
            {
                if(d[j][0]>90)
                {
                    if(d[j][0]<d[e][0])e=j;
                    else if(d[j][0]==d[e][0])
                    {
                        if(d[j][1]<d[e][1])e=j;
                        else if(d[j][1]==d[e][1])
                        {
                            if(d[j][2]<d[e][2])e=j;
                            else if(d[j][2]==d[e][2])
                            {
                                if(d[j][3]<d[e][3])e=j;
                                else if(d[j][3]==d[e][3])
                                {
                                    if(d[j][4]<d[e][4])e=j;
                                    else if(d[j][4]==d[e][4])
                                    {
                                        if(d[j][5]<d[e][5])e=j;
                                        else if(d[j][5]==d[e][5])
                                            if(d[j][6]<d[e][6])e=j;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        l=f[i];
        f[i]=f[e];
        f[e]=l;
        strcpy(t,d[i]);
        strcpy(d[i],d[e]);
        strcpy(d[e],t);
    }
   /* for(i=1;i<=n;i++)
    printf("%s:%d\n",d[i],f[i]);*/
    for(i=1;i<11;i++)
        printf("%s:%d\n",d[i],f[i]);
    return 0;
}
