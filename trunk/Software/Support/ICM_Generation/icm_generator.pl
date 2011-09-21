use XML::Simple;
use Data::Dumper;

$inputFileName = "icm_descriptor.xml";

$outputMacrosFile = "icm_macros.h";
$outputStructsFile = "icm_structs.h";

$lineWidth = 100;

@icm_macros_names = "";
%icms_info = "";

$icm_macros_file_contents = "";
$icm_structs_file_contents = "";

parseInputFile($inputFileName);

composeOutputFilesContents();

dumpFilesContents();
 
sub parseInputFile
{	
	# Extract the function argument
	my $fileName = $_[0];
	
	# Create object for the XML reading module
	$xml = new XML::Simple;

	# Read XML file
	$data = $xml->XMLin($fileName);
	
	@icm_macros_names = "";
	
	foreach $icm (@{$data->{ICM}})
	{
		
		push(@icm_macros_names, $icm->{content});
		
		@icm_args = "";
 
		foreach $arg (@{$icm->{arg}})
		{
			$arg =~ /(.*) (.*)/;
			
			$argElem = {'argType' => $1,
						'argName' => $2};
						
			push(@icm_args, $argElem);
		}
		shift(@icm_args);
		$icms_info{$icm->{content}} = [@icm_args];
	}
	
	shift(@icm_macros_names);
}

sub composeOutputFilesContents
{
	my $line;
	
	foreach $icm (@icm_macros_names)
	{
		$icm =~ /ICM_(.*)_(.*)_(.*)/;
		
		$msgName = fromCapsSeparated2SmallConcat($3);
		
		$structName = 'ICM_Struct_'.$1.'_'.$2.'_'.$msgName;

		$msgType = $1;
		$compName = $2;
		
		$handler = $compName."_ICM_".$msgType."_".$msgName."(&msgInfo)";
		
		for($counter = 0; $counter < scalar(@{$icms_info{$icm}}); $counter++)
		{
			if($icms_info{$icm}[$counter]{argType} =~ /ICM_Info/)
			{
				$icms_info{$icm}[$counter]{argName} =~ /(.*)__(.*)/;
				my $srcComponents = $1;
				my $dstComponents = $2;
				splice(@{$icms_info{$icm}}, $counter, 1);
			}
		}

		# Insert structure definition
		
		$icm_structs_file_contents .= "typedef $structName\n";
		$icm_structs_file_contents .= "{\n";
		for($counter = 0; $counter < scalar(@{$icms_info{$icm}}); $counter++)
		{
			$icm_structs_file_contents .= "    $icms_info{$icm}[$counter]{argType}                                $icms_info{$icm}[$counter]{argName};\n";
		}
		$icm_structs_file_contents .= "} $structName;\n\n\n";
		
		# Inser the macro definition
		
		$line = "#define $icm(";
		for($counter = 0; $counter < scalar(@{$icms_info{$icm}}); $counter++)
		{
			if($icms_info{$icm}[$counter]{argName} =~ /(.*)\[(.*)\]/)
			{
				$argName = $1."_Array_ptr"; 
			}
			else
			{
				$argName = "$icms_info{$icm}[$counter]{argName}";
			}
			$line .= "a_".$argName;
			if($counter < (scalar(@{$icms_info{$icm}}) - 1))
			{
				$line .= ", ";
			}
		}
		$line .= ")"." "x($lineWidth - length($line) - 2)."\\\n";
		$icm_macros_file_contents .= $line;
		
		$icm_macros_file_contents .= "{"." "x($lineWidth - 2)."\\\n";
		
		$line = "    $structName msgInfo;";
		$line .= " "x($lineWidth - length($line) - 1)."\\\n";
		$icm_macros_file_contents .= $line;
		
		$icm_macros_file_contents .= " "x($lineWidth - 1)."\\\n";
		
		for($counter = 0; $counter < scalar(@{$icms_info{$icm}}); $counter++)
		{
			$icm_macros_file_contents .= "    msg.$icms_info{$icm}[$counter]{argName} = "." "x($lineWidth - length("a_$icms_info{$icm}[$counter]{argName};\\") - length("    msg.$icms_info{$icm}[$counter]{argName} = "))."a_$icms_info{$icm}[$counter]{argName};\\\n";
		}
		$icm_macros_file_contents .= " "x($lineWidth - 1)."\\\n";
		$icm_macros_file_contents .= "    $handler;"." "x($lineWidth - length("    $handler;") - 1)."\\\n";
		$icm_macros_file_contents .= "}\n\n\n";
	}
}

sub dumpFilesContents
{
	open (OUTPUT_MACROS_FILE, ">$outputMacrosFile");
	print OUTPUT_MACROS_FILE $icm_macros_file_contents;
	close (OUTPUT_MACROS_FILE);
	
	open (OUTPUT_STRUCTURES_FILE, ">$outputStructsFile");
	print OUTPUT_STRUCTURES_FILE $icm_structs_file_contents;
	close (OUTPUT_STRUCTURES_FILE);
}

sub fromCapsSeparated2SmallConcat
{
	my $capsString = $_[0];
	
	$capsString =~ tr/A-Z/a-z/;
	
	$concatSmallString = "";
	
	if($CapsString =~ /_/)
	{
		my @words = split(/_/, $CapsString);
		
		foreach $word (@words)
		{	
			$word = firstLetterCapital($word);
			
			$concatSmallString = $concatSmallString.$word;
		}
	}
	else
	{
		$concatSmallString = firstLetterCapital($capsString);
	}
	
	return $concatSmallString;
}

sub firstLetterCapital
{
	my $smallLettersWord = $_[0];
	
	my $firstLetter = substr($smallLettersWord, 0, 1);
	
	$firstLetter =~ tr/[a-z]/[A-Z]/;
	
	my $nextLetters = substr($smallLettersWord, 1);
	
	my $concatSmallString = $firstLetter . $nextLetters;
	
	return $concatSmallString;
}
