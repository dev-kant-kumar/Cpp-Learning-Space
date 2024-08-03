#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout << "\n\033[1;43m This c++ program helps to works with git \033[0m\n\n";
    const char *option = "\033[34m[1]- \033[36mCheck git status  \033[0m\n"
                         "\033[34m[2]- \033[36mAdd all files     \033[0m\n";
    //  "\033[34m[3]- \033[36mAdd specific file \033[0m\n"
    //  "\033[34m[4]- \033[36mCommit changes    \033[0m\n"
    //  "\033[34m[5]- \033[36mPush changes to main \033[0m\n\n";

    cout << option << endl;
    int choice;
    char fileName[100], commitMessage[500], confirmation[2], git_add[120] = "git add ", git_commit[550] = "git commit -m ' ";
c:
    cout << "\033[1mEnter your choice {like 1 or 2} : \033[0m";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("git status");
        break;

    case 2:
        system("git add .");
        break;

    // case 3:
    //     cout << "\033[1mEnter the file name you want to add : \033[0m";
    //     cin >> fileName;
    //     strcat(git_add, fileName);
    //     system(git_add);
    //     break;

    // case 4:
    //     cout << "\033[1mEnter your commit message :\033[0m";
    //     cin >> commitMessage;
    //     strcat(git_commit, commitMessage);
    //     strcat(git_commit, "'");
    //     system(git_commit);
    //     break;

    // case 5:
    //     cout << "You have selected to push changes to main \n";
    // d:
    //     cout << "\033[1mPress Y to confirm or N to Cancel : \033[0m";
    //     cin >> confirmation;

    //     if (strcmp(confirmation, "Y") == 0)
    //     {
    //         system("git push origin main");
    //     }
    //     else if (strcmp(confirmation, "N") == 0)
    //     {
    //         cout << "Cancelled \n";
    //         break;
    //     }
    //     else
    //     {
    //         cout << choice << "\033[4;31mThis is invalid input! Please enter Y or N only \033[0m\n";
    //         goto d;
    //     }
    //     break;
    default:
        cout << choice << "\033[1;31m This is invalid choice select and enter from 1 to 2 only \033[0m\n\n";
        goto c;
        break;
    }
    return 0;
}