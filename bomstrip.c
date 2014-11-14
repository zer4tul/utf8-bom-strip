#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void
usage(char *prog)
{
	fprintf(stderr, "usage: %s\n", prog);
	exit(1);
}

int
main(int argc, char *argv[])
{
	size_t nread;
	char buf[65536];
	char *utf8bom = "\xef\xbb\xbf";

	if (argc > 1)
		usage(argv[0]);

	nread = fread(buf, 1, strlen(utf8bom), stdin);
	if (nread == 0)
		return 0;
	if (strcmp(buf, utf8bom) != 0)
		fwrite(buf, 1, nread, stdout);
	for (;;) {
		nread = fread(buf, 1, sizeof buf, stdin);
		if (nread < 0)
			exit(1);
		if (nread == 0)
			return 0;
		fwrite(buf, 1, nread, stdout);
	}
	return 0;
}
