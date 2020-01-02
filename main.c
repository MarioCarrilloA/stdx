#include <getopt.h>
#include <stdio.h>

static struct option long_cmd_opts[] = {
	{"help",	no_argument,	0, 'h'},
	{"verbose",	no_argument,	0, 'v'},
	{0, 0, 0, 0}
};

static const char help[] =
	"Usage: stdx [-h] [--help] [-v] [--verbose]\n"
	"Description:\n"
	"  -h, --help           help page\n"
	"  -v, --verbose        enable verbose\n\n";

int main(int argc, char **argv)
{
	int cmd;
	int opt_index = 0;
	int verbose_enable = 0;

	while ((cmd = getopt_long(argc, argv, "hv",
		long_cmd_opts, &opt_index)) != -1) {

		switch (cmd) {
		case 'h':
			printf("%s", help);
			return 0;
		case 'v':
			verbose_enable = 1;
			break;
		default:
			printf("Unsupported option: -%c. "
				"See option -h for help.\n", optopt);
			return 1;
		}
	}

	return 0;
}
