#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain( VOID )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    LPTSTR szCmdline=_tcsdup(TEXT("MyChildProcess"));

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    unsigned long number;

    printf("rentrer le nombre sur lequel s'applique la conjecture\n");
    if (scanf("%ld", &number) != 0)   // converting from char array to int, !=0 means scanf is sucessful
    {
        if (number >= 1){
            char nombre[20];
            sprintf(nombre, "%ld", number);
            char chaine[500]= "C:\\Users\\Simil Gralda\\Documents\\c pr\\collatzconjecture\\bin\\Debug\\collatzconjecture.exe ";
            strcat(chaine, nombre);
            // Commmencer le child process.
            if( !CreateProcess(NULL,   // No module name (use command line)
                               chaine,      // Command line
                               NULL,           // Process handle not inheritable
                               NULL,           // Thread handle not inheritable
                               FALSE,          // Set handle inheritance to FALSE
                               0,              // No creation flags
                               NULL,           // Use parent's environment block
                               NULL,           // Use parent's starting directory
                               &si,            // Pointer to STARTUPINFO structure
                               &pi )           // Pointer to PROCESS_INFORMATION structure
              )
            {
                printf( "CreateProcess failed (%d)./n", GetLastError() );
                return;
            }
        }
        else
        {
            printf("Please enter a valid positive integer; program terminated abnormally!\n");
            return 1;
        }
    }
    // Attendre jusqu'a ce que le child process s'arrete.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
