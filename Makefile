STDX_BIN = stdx
all:
	gcc main.c add_set.c subcmds.c -o $(STDX_BIN)

clean:
	@rm -f $(STDX_BIN)
