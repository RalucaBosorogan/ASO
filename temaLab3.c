/*
TEMĂ OBLIGATORIE ❗ 
Să se citească toate subcheile unei chei (la alegere) din Registry și să se afișeze la ieșirea standard.
*/

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define MAX 255

void AfisareSubchei(HKEY hKeyRoot, LPCTSTR subKeyPath)
{
    HKEY hKey;
    DWORD index = 0;
    DWORD size;

    TCHAR subKeyName[MAX];

    LSTATUS lResult = RegOpenKeyEx(hKeyRoot, subKeyPath, 0, KEY_READ, &hKey);

    if (lResult != ERROR_SUCCESS)
    {
        if (lResult == ERROR_FILE_NOT_FOUND)
        {
            printf("Key not found.\n");
            return;
        }
        else
        {
            printf("Error opening key.\n");
            return;
        }
    }

    _tprintf(TEXT("Subcheile din: %s\n\n"), subKeyPath);

    while (1)
    {
        size = MAX;

        lResult = RegEnumKeyEx(
            hKey,
            index,
            subKeyName,
            &size,
            NULL,
            NULL,
            NULL,
            NULL
        );

        if (lResult == ERROR_SUCCESS)
        {
            _tprintf(TEXT("Subcheia: %s [%lu]\n"), subKeyName, index);
            index++;
        }
        else if (lResult == ERROR_NO_MORE_ITEMS)
        {
            _tprintf(TEXT("\nAm gasit %lu subchei.\n"), index);
            break;
        }
        else
        {
            printf("Eroare la enumerare.\n");
            break;
        }
    }

    RegCloseKey(hKey);
}

int main(void)
{
    AfisareSubchei(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft"));
    return 0;
}
