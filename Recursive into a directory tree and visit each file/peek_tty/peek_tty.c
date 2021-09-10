/*******************************************************************************
 *
 * sample program to print string to other terminals
 *
 ******************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

main()
{
	int fd;
	int i;
	char *str = "Hello!\n";

	fd = open ("/dev/pts/2", O_WRONLY);
	write (fd, str, strlen(str)+1);

	return 0;
}//main()

















