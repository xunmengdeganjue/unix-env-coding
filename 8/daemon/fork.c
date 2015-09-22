#include<stdio.h>



int main(){
	
	
	int ret = 0;
	if((ret = fork())==0){
		printf("I'm the sun,My pid is %d!\n",getpid());
		printf("the parent's pid is %d\n\n",getppid());
	}else if(ret > 0){
		printf("I'm the father My pid is %d!\n\n",getpid());
		printf("the parent's pid is %d\n\n",getppid());
		
	}else{
		printf("error in fork!");   
	}
	
	
	
}