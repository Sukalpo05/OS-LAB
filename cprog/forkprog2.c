// to enable sequential execution in child and parent using fork and wait
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>  //for wait()
int main(){
	int n;
	int id=fork();
	if(id==0){
		n=0;
	}else{
		n=11;
	}
	
	if(id!=0){ //if id is from parent then wait for child to execute first
		wait(NULL);  //Child NEVER waits for parent.Parent waiting for child = correct synchronization.

	}
	for(int i=n;i<=n+10;i++){
		if(id==0){
			printf("Child process prints: %d \n",i);
			usleep(200); // task is soo small that it is automatically becoming sequential, so we sleep 
		}else{
			printf("Parent Process prints: %d \n",i);
			usleep(200); // task is soo small that it is automatically becoming sequential, so we sleep
			
		}
		
	}
	return 0;
}
