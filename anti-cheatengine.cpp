#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <algorithm>
#include <vector>


bool LoopProcess() {
	PROCESSENTRY32 pe32;
	std::vector<std::string> pids;


	HANDLE Csnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Csnapshot == INVALID_HANDLE_VALUE) {
		std::cout << "Csnapshot was invalid! -> loopProcess\n";
		Sleep(3000);
		exit(1);
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(Csnapshot, &pe32)) {
		std::cout << "Process32First was not successful!\n";
		CloseHandle(Csnapshot);
		Sleep(3000);
		exit(1);
	}

	//loop proccess
	do
	{
		pids.push_back(pe32.szExeFile); //put all the processes into a array
		std::sort(std::begin(pids), std::end(pids)); //not necessary but i put sort them in a-z
	} while (Process32Next(Csnapshot, &pe32));

	//loop through the processes
	for (auto i = pids.begin(); i < pids.end(); ++i) {

		if (*i == "cheatengine-x86_64-SSE4-AVX2.exe") //deref the i cause its just a array and getting the process names
		{
			std::cout << "Cheat engine detected, Closing program!" << std::endl;
			Sleep(2000);
			exit(1); 
			return 1;
		}
	}

	CloseHandle(Csnapshot);

	return 0;
}


int main()
{
	//AntiCheatEngine coded by jud(qerj)
	//The tool basically loops through the processes in search of 
	//cheat engine. If it finds cheat engine it will print out a 
	//message to the console so we know that cheat engine is opened.
	//with this, developers can succesfully not have their game hacked
	//word of advise, cheat engine is not just for offline games.

	while (1)
	{
		LoopProcess(); //will be called everytime until the function finally finds something fishy

		Sleep(1000); //there is literally no need to CONSTANTLY make sure a user is not cheating.
	}
}
