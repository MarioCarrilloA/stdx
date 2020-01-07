#include "subcmds.h"

int preprocess_subcommand(char *args, struct subcmd *subcommands)
{
	struct subcmd *subcmds = subcommands;

	while (subcmds->subcommand != NULL) {
		if (strcmp(args, subcmds->subcommand) == 0) {
			printf("Valid subcommand %s  %s\n", args, subcmds->subcommand);
			return 0;
		}
		subcmds++;
	}
}
