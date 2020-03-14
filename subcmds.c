#include "subcmds.h"

int preprocess_subcommand(char *args, struct subcmd *subcommands)
{
	struct subcmd *subcmds = subcommands;
	int subcmd_len;
	int args_len;

	args_len = strlen(args);
	while (subcmds->subcommand_name != NULL) {
		subcmd_len = strlen(subcmds->subcommand_name);
		if (args_len == subcmd_len &&
			strncmp(args, subcmds->subcommand_name,
			strlen(subcmds->subcommand_name)) == 0) {
			return 0;
		}
		subcmds++;
	}
	return 1;
}
