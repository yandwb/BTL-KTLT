#include "HeaderCpp.h"
#include "KhaiCpp.h"
#include "DuongCpp.h" 
int main(){
	int check=1;
	while (check!=0)
		if (MatKhauAdmin()) {
			menuAdmin();
			check = 0;
		}
}
