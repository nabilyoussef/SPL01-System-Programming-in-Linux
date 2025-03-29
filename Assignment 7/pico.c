
#include "utilities.h"

#define MAX_CMD 100

int main(){

	char str[MAX_CMD];


	while(1){

		printf("PICO_SHELL:~$ ");
		fgets(str, MAX_CMD, stdin);


		// Remove newline Char
		str[strcspn(str,"\n")] = '\0';
		if(strlen(str) ==0) continue ;
		// Extract Command, cut after the first space
		char *args[MAX_CMD / 2+1];
		char *token = strtok(str," ");
		int i =0;
		while(token != NULL){
			args[i++] = token;
			token = strtok(NULL, " ");}
		args[i] = NULL;
		if(args[0] == NULL) continue;
		char * cmd = args[0];
		// check if command exists

		if(strcmp(cmd, "exit") == 0 ) break;
		else if(strcmp(cmd, "echo") ==0)echo(args);
		else if(strcmp(cmd, "pwd" ) ==0) pwd();
		else if(strcmp(cmd, "cd"  ) ==0) change_directory(args[1]);
		else execute_command(args) ;

	}

	printf("Good Bye \n");
	return 0;


}
