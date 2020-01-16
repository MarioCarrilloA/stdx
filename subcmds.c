#include "subcmds.h"

int preprocess_subcommand(char *args, struct subcmd *subcommands)
{
	struct subcmd *subcmds = subcommands;
	int subcmd_len;
	int args_len;

	args_len = strlen(args);
	while (subcmds->subcommand != NULL) {
		subcmd_len = strlen(subcmds->subcommand);
		if (args_len == subcmd_len &&
			strncmp(args, subcmds->subcommand,
			strlen(subcmds->subcommand)) == 0) {
			return 0;
		}
		subcmds++;
	}
	return 1;
}
