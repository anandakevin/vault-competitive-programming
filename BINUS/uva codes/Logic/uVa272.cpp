#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char c;
	int index = 0;

	while(scanf("%c", &c) != EOF){
		if(c == '"' && index%2==1){
			printf("%c%c", '\'', '\'');
			index++;
		}else if(c == '"' && index%2 == 0){
			printf("%c%c", '`', '`');
			index++;
		}else{
			printf("%c", c);
		}
	}
		
	
	getchar();
	return 0;
}