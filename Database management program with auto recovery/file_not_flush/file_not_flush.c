#include <unistd.h>
#include <stdio.h>

main ()
{
	FILE *fp;
	char buf[1000];

	fp = fopen ("test.txt", "w");
	setbuffer (fp, buf, 1000);

	fprintf (fp, "Hello!\n");
	_exit (0);

	return 0;
}//main ()



















