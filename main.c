#include <getopt.h>
#include <stdio.h>

#include "add_set.h"
#include "subcmds.h"

static struct option long_cmd_opts[] = {
	{"help",	no_argument,	0, 'h'},
	{"verbose",	no_argument,	0, 'v'},
	{0, 0, 0, 0}
};

static const char version[] = "1.0.0";

static const char help[] =
	"Usage: stdx [-h] [--help] [-v] [--verbose]\n"
	"Description:\n"
	"  -h, --help           help page\n"
	"  -v, --verbose        enable verbose\n\n";

static const char info[] =
	"Tool designed to get primary statistics from data sets.\n\n"
	"Mario Alfredo Carrillo Arevalo - mario.carrillo.arevalo@gmail.com\n"
	"January 2020\n";

void show_info()
{
	printf("%s", info);
	printf("%s\n", version);
}


static struct subcmd subcommands[] = {
	{"add-set", &add_set},
	{"show-info", &show_info}
};

int main(int argc, char **argv)
{
	int cmd;
	int opt_index = 0;
	int verbose_enable = 0;

	while ((cmd = getopt_long(argc, argv, "-hv",
		long_cmd_opts, &opt_index)) != -1) {
		switch (cmd) {
		case 'h':
			printf("%s", help);
			return 0;
		case 'v':
			verbose_enable = 1;
			break;
		case '\01':
			printf("Entering\n");
			preprocess_subcommand(optarg, subcommands);
			break;
		case '?':
			printf("Error\n");
		default:
			printf("Unsupported option: -%c. "
				"See option -h for help.\n", optopt);
			return 1;
		}
	}

	return 0;
}
