src_files = main.c\
			MCM/mcm.c\
			MDM/mdm.c

output_executable = egyRev.exe

compiler_name = gcc

help:
	@echo This is the help of egyRev project makefile, enter one of the following targets
	@echo all	: To build/link egyRev project
	@echo run	: To run the resulted executable from the build process
	@echo clean	: To remove the generated files

all:
	$(compiler_name) $(src_files) -o $(output_executable)

run:
	./$(output_executable)

clean:
	rm -f $(output_executable)
