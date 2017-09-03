#include "floor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	char enter;
	Lei dilei;
	dilei.Set_Lei();
	dilei.Draw_Floor();
	dilei.Lei_Travel();
	dilei.Draw_Num();
	cin >> enter;
	return 0;
}