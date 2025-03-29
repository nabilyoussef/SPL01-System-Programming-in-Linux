#include "utilities.h"
//#include <limits.h>


void echo (char ** args){
	for(int i =1 ; args[i]!=NULL; i++){
		printf("%s",args[i]);	
	}
	printf("\n");

}

void pwd(void){
	char cwd[PATH_MAX];
	if(getcwd(cwd, sizeof(cwd)) != NULL) printf("%s\n",cwd);
	else printf("PWD Error\n");
}
void change_directory(const char* path){

	if(chdir(path) !=0)printf("cd failed\n");
	else{
	
		char cwd[PATH_MAX];
		if(getcwd(cwd, sizeof(cwd)) != NULL)printf("current directory: %s \n",cwd);
		else printf("getcwd failed\n");
	}

}

void execute_command(char ** args){
	pid_t pid = fork();

	if(pid == -1)printf("fork failed\n");
	else if (pid ==0){
		if(execvp(args[0],args)== -1) printf("Invalid Command\n");
		exit(EXIT_FAILURE);
	}
	else {
		int status;
		waitpid(pid, &status,0);
	}
	}
