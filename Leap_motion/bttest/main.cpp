#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>

void connectToNXT(void) {
	//opret forbindelse
	if (!Open()) {
		printf("\nConnection failed\n");
		exit(1);
	}

	//hvis ingen forbindelse
	printf("\nConnection open\n");
}

int main() {
	return 0;
}