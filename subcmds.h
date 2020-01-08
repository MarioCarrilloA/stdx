#ifndef __SUBCMD_H__
#define __SUBCMD_H__

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct subcmd {
	char *subcommand;
	int (*subcmd_func)(int argc, char **argv);
};

int preprocess_subcommand(char *args, struct subcmd subcommands[]);

#ifdef __cplusplus
}
#endif
#endif /* __SUBCMD_H__ */
