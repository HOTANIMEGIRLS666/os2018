#include<unistd.h>
#include<stdio.h>

int main(){
	printf("Main before fork() \n");
	int pid1 = fork();
	if(pid1 == 0){
		printf("Running the cmd ps -ef \n");
		char *args[]={"/bin/ps","-ef",NULL};
		execvp("/bin/ps",args);
	}else{
		printf("ps is:%d",pid1);
	}
	int pid2 = fork();
	if(pid2 == 0){
		printf("Running the cmd free -h \n");
		char *args[]={"free","-h",NULL};
		execvp("free",args);
	}else{
		printf("free is:%d",pid2);
	}
	return 0;
} 
