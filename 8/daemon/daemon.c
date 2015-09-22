#include<stdio.h>
#include<time.h>

void init_daemon(void);

int main()
{
	FILE * fp;
	time_t t;
	
	init_daemon();//init the daemon
	
	while(1){
		sleep(60);
		if((fp=fopen("/tmp/deamon_test.log","a")) >= 0){
			t= time(0);
			fprintf(fp,"\33[31mIm here\33[0m  \33[33mat %s\33[0m \n",asctime(localtime(&t)));
			fclose(fp);
		}
		
		
	}
	return 0;
	
}