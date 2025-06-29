void PrintVMFMeta(const char *filename)
{	FILE *f = fopen(filename, "r");
	if (!f)
	{	printf("Failed to open file: %s\n", filename);
		return;
	}

	char line[1024];
	int inVersionInfo = 0;
	int inWorld = 0;
	printf("== VMF Meta Info ==\n");

	while (fgets(line, sizeof(line), f))
	{	// Trim whitespace
		char *start = line;
		while (isspace(*start)) start++;

		// Start of versioninfo block
		if (strstr(start, "versioninfo"))
		{	inVersionInfo = 1;
			printf("[versioninfo]\n");
			continue;
		}
		if (inVersionInfo) {
			if (strchr(start, '}'))
			{	inVersionInfo = 0;
			} else
			{	char key[64], val[256];
				if (sscanf(start, "\"%63[^\"]\" \"%255[^\"]\"", key, val) == 2)
				{	printf("\t%s: %s\n", key, val);
				}
			}
			continue;
		}

		// Start of world block (basic metadata)
		if (strstr(start, "world"))
		{	inWorld = 1;
			printf("\n[world]\n");
			continue;
		}
		if (inWorld)
		{	if (strchr(start, '}'))
			{	inWorld = 0;
			} else
			{	char key[64], val[256];
				if (sscanf(start, "\"%63[^\"]\" \"%255[^\"]\"", key, val) == 2)
				{	printf("\t%s: %s\n", key, val);
				}
			}
			continue;
		}
	}

	fclose(f);
}
