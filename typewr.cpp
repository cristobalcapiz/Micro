#include <stdio.h>
#include <cstdlib>

int main()
{
	char c;
	puts("Enter text '.' to exit");
	do {
		system("/bin/stty raw");
		c=getchar();
		putchar(c);
		system("/bin/stty -raw");
	}while (c!= '.');
	return 0;
}	
