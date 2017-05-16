#include <stdio.h>
#include <windows.h>
#include <string>

int testOpenKey(LONG _result, char *label)
{
	int _cont = 1;
	if(_result != ERROR_SUCCESS) 
	{
        if(_result  == ERROR_FILE_NOT_FOUND) {
			printf("Not Exists Key (%s) in Windows version.\n",label);
        } else {
			printf("Error: Opening Key (%s)\n");
        }
		_cont = 0;
	} else { }
	return _cont;
}
void testWriteKey(LONG _result, char *label)
{
    if(_result != ERROR_SUCCESS) {
		printf("Error: Writing Value in %s\n",label);
	} else { printf("%s done. \n",label ); }
}

void testCloseKey(LONG _result)
{
    if(_result != ERROR_SUCCESS) 
	{
		printf("Error: Closing Key\n");
	} else { }
}        




int main(void) {
    HKEY hkey;
	DWORD value1 = 0x00000000;
	DWORD value2 = 0x00000004;
	LONG result_open, result_write, result_close;
	printf(" _   _    __        __                       ____            \n");
	printf("| \\ | | __\\ \\      / /_ _ _ __  _ __   __ _ / ___|_ __ _   _ \n");
	printf("|  \\| |/ _ \\ \\ /\\ / / _` | '_ \\| '_ \\ / _` | |   | '__| | | |\n");
	printf("| |\\  | (_) \\ V  V / (_| | | | | | | | (_| | |___| |  | |_| |\n");
	printf("|_| \\_|\\___/ \\_/\\_/ \\__,_|_| |_|_| |_|\\__,_|\\____|_|   \\__, |\n");
	printf("                                                       |___/ \n");  
	printf("Autor Alessandro de Oliveira Faria (A.K.A. cabelo@opensuse.org) \n\n");
	printf("Donations: http://assuntonerd.com.br/nowannacry \n\n\n" );

	printf("Running...\n");
	//"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters"
    result_open = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters", 0, KEY_WRITE, &hkey);
    if(testOpenKey(result_open,"Parameters"))
	{
		result_write = RegSetValueEx(hkey, L"SMB1", 0, REG_DWORD, (const BYTE*)&value1, sizeof(value1));
		testWriteKey(result_write,"SMB1");

		result_close = RegCloseKey(hkey);
		testCloseKey(result_close);	
	}

	// "SYSTEM\\CurrentControlSet\\Services\\mrxsmb"
    result_open = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\mrxsmb", 0, KEY_WRITE, &hkey);
    if(testOpenKey(result_open,"mrxsmb"))
	{
		result_write = RegSetValueEx(hkey, L"Start", 0, REG_DWORD, (const BYTE*)&value2, sizeof(value2));
		testWriteKey(result_write,"mrxsmb");

		result_close = RegCloseKey(hkey);
		testCloseKey(result_close);
	}

	// "SYSTEM\\CurrentControlSet\\Services\\mrxsmb10"
    result_open = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\mrxsmb10", 0, KEY_WRITE, &hkey);
    if(testOpenKey(result_open,"mrxsmb10"))
	{
		result_write = RegSetValueEx(hkey, L"Start", 0, REG_DWORD, (const BYTE*)&value2, sizeof(value2));
		testWriteKey(result_write,"mrxsmb10");

		result_close = RegCloseKey(hkey);
		testCloseKey(result_close);
	}

	// "SYSTEM\\CurrentControlSet\\Services\\mrxsmb20"

    result_open = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\mrxsmb20", 0, KEY_WRITE, &hkey);
    if(testOpenKey(result_open,"mrxsmb20"))
	{

		result_write = RegSetValueEx(hkey, L"Start", 0, REG_DWORD, (const BYTE*)&value2, sizeof(value2));
		testWriteKey(result_write,"mrxsmb20");

		result_close = RegCloseKey(hkey);
		testCloseKey(result_close);
	}
	printf("Finish!\n");
	return 0;
}

