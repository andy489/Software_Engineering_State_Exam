#include <unistd.h> 
#include <stdio.h>

int main(){
	int a = 1000;
	
	if(fork()){
		a /= 2;
		printf("\nValue of a = %d", a);
	} else {
		if(fork()){
			a *= 2;
			printf("\nValue of a = %d", a);
			
			if(execlp("ls","ls","-l",0) == -1){
				a = a + 2;
				printf("\nValue of a = %d", a);
			}
		} else {
			a += 2;
			printf("\nValue of a = %d", a);
		}
	}		

	a++;
	printf("\nValue of a = %d", a);
}
