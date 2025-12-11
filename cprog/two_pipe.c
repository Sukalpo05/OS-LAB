#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
 // parent write a number, the child received a number from parent , added 10 and send it to parent and parent display it
 //pipe 0 takes the input and send it to child and value is updated and pipe 1 takes the updated value to parent to print
int main(){
	int f1[2];  
	int f2[2];
	pipe(f1); 
	pipe(f2);
	int id=fork();
	if(id==0){
		close(f2[0]); 
		close(f1[1]);
		int n;
		read(f1[0],&n,sizeof(n));
		printf("Number received to child: %d \n",n);
		n=n+10;
		write(f2[1],&n,sizeof(n));
		close(f2[1]);
		close(f1[0]);
	}else{
		close(f1[0]);
		close(f2[1]);
		int x;
		printf("Enter a number : ");
		scanf("%d",&x);
		write(f1[1],&x,sizeof(x));
		read(f2[0],&x,sizeof(x));
		printf("Updated value of x: %d \n",x);
		close(f1[1]);
		close(f2[0]);
	}
	return 0;
	
}
