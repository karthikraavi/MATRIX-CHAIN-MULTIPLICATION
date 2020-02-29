# include <stdio.h>
# include <stdlib.h>

int chain(int a[],int n,int p,int q,int b[5][5]);

int main()
{
	int n=6;
	int a[]={0,10,20,30,40,30};//We are defining zero as initial value inorder to start indexing from 1.
	int b[n-1][n-1];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			b[i][j]=-1;    //We are defining -1 as initial value inorder to start indexing from 1
		}
	}

	printf("%d",chain(a,n-2,1,n-2,b));
}


int chain(int a[],int n,int p,int q,int b[5][5])
{
int	m=32700,k,z;
if(b[p][q]!=-1){return b[p][q];}
if(p==q){b[p][q]=0;return 0;}
if(p==(q-1)){b[p][q]=a[p]*a[p+1]*a[p+2];return a[p]*a[p+1]*a[p+2];}
for(int i=p;i<q;i++){
	k=chain(a,n,p,i,b)+chain(a,n,i+1,q,b)+(a[p]*a[i+1]*a[q+1]);
	if(m>k){m=k;z=i;}
}
//printf("[%d  %d=%d]\n",p,q,z );

b[p][q]=m;
return b[p][q];
}