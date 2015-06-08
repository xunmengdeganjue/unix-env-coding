
#include <errno.h>	
#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <string.h>		/* for convenience */


int main(int argc,char **argv)
{
	fprintf(stderr, "EACCESS: %s\n" ,strerror(EACCES));
	errno  = ENOENT;
	perror(argv[0]);
	exit(0);
}
