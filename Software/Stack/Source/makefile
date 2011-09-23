####################################################################################################
#										Make configurations										   #
####################################################################################################

src_files = main.c\
			MCM/mcm.c\
			MDM/mdm.c\
			Abstraction_Layers/HAL/hal.c
			
header_files_path = Common

output_executable = egyRev.exe

compiler_name = gcc

####################################################################################################
#											Make targets										   #
####################################################################################################

help:
	@echo This is the help of egyRev project makefile, enter one of the following targets
	@echo all	: To build/link egyRev project
	@echo run	: To run the resulted executable from the build process
	@echo clean	: To remove the generated files

all:
	$(compiler_name) $(src_files) -I $(header_files_path) -o $(output_executable)

run:
	#./$(output_executable)

clean:
	#rm -f $(output_executable)
