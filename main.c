#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
#include <dirent.h>


int main(){
#ifdef WIN32
    char path[50]=".\\";
    char fileName[50] = "\\Server";
#else
    char path[50]="./";
    char fileName[50] = "/Server";
#endif
    char servFile[50] = "mkdir ";
    strcat(servFile, path);
    strcat(servFile, fileName);
    system(servFile);
    printf("File management program \n");
    char command[50]="";
    int next = 2;
    do{
        if (next == 2){
            printf("Enter your command (help for the command list) \n");
            scanf("%s", command);
            next = 1;
        }
        int compHelp = strcmp(command, "help");
        int compCd = strcmp(command, "cd");
        int compGet = strcmp(command, "get");
        int compLs = strcmp(command, "ls");
        int compDelete = strcmp(command, "delete");
        int compMkdir = strcmp(command, "mkdir");
        int compPut = strcmp(command, "put");
        int compTest = strcmp(command, "test");
        int compQuit = strcmp(command, "quit");
        if (compHelp == 0){
            printf("- help: list all available commands\n");
            printf("- cd: change the current directory\n");
            printf("- get: download a file from Server folder\n");
            printf("- ls: list files and directories\n");
            printf("- delete: delete a file or a directory\n");
            printf("- mkdir: create a directory\n");
            printf("- put: send a file to Server folder\n");
            printf("- quit: logout the client\n");
            next = 2;
        }
        else if (compCd == 0){
            printf("Enter path : \n");
            scanf("%s", path);
            while(opendir(path) == NULL){
                printf("This path doesn't exist! \n");
                printf("Enter path : \n");
                scanf("%s", path);
            }
            next = 2;
        }
        else if (compGet == 0){
            printf("Name of the file to copy : ");
            char cpFile[50] = "";
            char point[2] = ".";
#ifdef WIN32
            char slash[2] = "\\";
            char commandLine[50] = "copy ";
#else
            char slash[2] = "//";
            char commandLine[50] = "cp ";
#endif
            char space[2] = " ";
            scanf("%s", cpFile);
            strcat(commandLine, point);
            strcat(commandLine, fileName);
            strcat(commandLine, slash);
            strcat(commandLine, cpFile);
            strcat(commandLine, space);
            strcat(commandLine, path);
            strcat(commandLine, slash);
            strcat(commandLine, cpFile);
            system(commandLine);
            printf("%s", commandLine);
            next = 2;
        }
        else if (compLs == 0){
#ifdef WIN32
            char dir[50] = "dir ";
            strcat(dir, path);
#else
            char dir[50] = "ls ";
            strcat(dir, path);
#endif
            system(dir);
            next = 2;
        }
        else if (compDelete == 0){
            char delFile[50] = "";
            printf("Name of the file to delete : \n");
            scanf("%s", delFile);
#ifdef WIN32
            char slash[2] = "\\";
            char dFile[50] = "rmdir /s ";
#else
            char slash[2] = "/";
            char dFile[50] = "rm -r ";
#endif
            strcat(slash,delFile);
            strcat(dFile, path);
            strcat(dFile, slash);
            next = 2;
            system(dFile);
        }
        else if (compMkdir == 0){
            printf("mkdir\n");
            char mkdir[50] = "mkdir ";
            char nextmk[50] = "";
            char temp[50] = "";
#ifdef WIN32
            char slash[2] = "\\";
#else
            char slash[2] = "/";
#endif

            strcat(temp, path);
            printf("Name of the file to create : ");
            scanf("%s", nextmk);
            strcat(temp, slash);
            strcat(temp, nextmk);
            strcat(mkdir, temp);
            system(mkdir);
            next = 2;
        }
        else if (compPut == 0){
            printf("Name of the file to copy : ");
            char cpFile[50] = "";
            char point[2] = ".";
#ifdef WIN32
            char slash[2] = "\\";
            char commandLine[50] = "copy ";
#else
            char slash[2] = "/";
            char commandLine[50] = "cp ";
#endif
            char space[2] = " ";
            scanf("%s", cpFile);

            strcat(commandLine, path);
            strcat(commandLine, slash);
            strcat(commandLine, cpFile);

            strcat(commandLine, space);

            strcat(commandLine, point);
            strcat(commandLine, fileName);
            strcat(commandLine, slash);
            strcat(commandLine, cpFile);

            system(commandLine);
            printf("%s", commandLine);
            next = 2;
            next = 2;
        }
        else if (compTest == 0){
            printf("%s\n", path);
            next = 2;
        }
        else if (compQuit == 0){
            next = 0;
        }
        else {
            printf("This command doesn't exist\n");
            next = 2;
        }
    }while (next == 1 || next == 2);
}