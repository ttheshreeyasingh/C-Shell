target:
	gcc -g main.c ./source/display.c ./source/execute.c ./source/input.c ./source/builtin-commands/echo.c ./source/builtin-commands/pwd.c -o cshell
clean:
	rm cshell
