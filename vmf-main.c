#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vmf-metadata.c"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <map.vmf>\n", argv[0]);
		return 1;
	}

	PrintVMFMeta(argv[1]);
	return 0;
}
