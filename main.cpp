#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool DEBUG = false;

int main2(int argc, char **argv) {
    char buffer[50];
    sprintf(buffer, "ciao");
    printf("%s\n", buffer);
    sprintf(buffer, "jacopo");
    printf("%s\n", buffer);
    return 0;
}


int main(int argc, char **argv) {
    if (DEBUG)cout << "You have entered " << argc << " arguments:" << "\n";

    if (strcmp(argv[1], "-h") == 0) {
        printf("     __.__  __   \n"
               "    |__|__|/  |_ \n"
               "    |  |  \\   __\\\n"
               "    |  |  ||  |  \n"
               "/\\__|  |__||__|  \n"
               "\\______|         ");
        printf("\n---git extension by Jacopo---\n\n");
        printf("jit add-commit [message]\t\tadd all and commit\n");
        printf("jit add-commit-push [message]\t\tadd all, commit and push in tracked remote branch\n");
        printf("jit merge-into [local-branch-name]\tmerge current branch into specified local branch\n");
        return 0;
    }
    if (strcmp(argv[1], "add-commit") == 0) {
        if (DEBUG)
            printf("addcommit\n");
        system("git add -A");
        char buffer[50];
        sprintf(buffer, "git commit -m\"%s\"", argv[2]);
        system(buffer);
        return 0;
    }
    if (strcmp(argv[1], "add-commit-push") == 0) {
        if (DEBUG) printf("addcommit\n");
        system("git add -A");
        char buffer[50];
        sprintf(buffer, "git commit -m\"%s\"", argv[2]);
        system(buffer);
        sprintf(buffer, "git push %s",argv[3]);
        system(buffer);
        return 0;
    }
    if (strcmp(argv[1], "merge-into") == 0) {
        if (DEBUG) printf("merge-into\n");
        char buffer[100];
        FILE *outputfile = _popen("git rev-parse --abbrev-ref HEAD", "r");
        char psBuffer[128];
        fgets(psBuffer, sizeof(psBuffer), outputfile);
        sprintf(buffer, "git checkout %s", argv[2]);
        system(buffer);
        sprintf(buffer, "git merge %s", psBuffer);
        system(buffer);
        return 0;
    }

    char command[1024];
    strcpy(command, "git");
    for (int i = 0; i < argc; ++i) {
        if (DEBUG) cout << argv[i] << "\n";
        if (i > 0)
            strcat(command, argv[i]);
        strcat(command, " ");
    }
    if (DEBUG) cout << command << "\n";
    int i = system(command);
    return 0;
}

