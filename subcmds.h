#ifndef __SUBCMD_H__
#define __SUBCMD_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

struct subcmd {
	char *subcommand;
	int (*subcmd_func)(int argc, char **argv);
};

#ifdef __cplusplus
}
#endif
#endif /* __SUBCMD_H__ */
