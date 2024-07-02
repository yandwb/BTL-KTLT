#include "HeaderC.h"
#include "KietC.h"
#include "BaoC.h"
int main(){
	int check=1;
	while (check!=0)
		if (MatKhauAdmin()) {
			Menu();
			check = 0;
		}
}