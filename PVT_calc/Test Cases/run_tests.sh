
for dir in test*; do
	if [[ -d $dir ]]; then 
        	echo "Running fluidity executable contained in ../Source in $dir ";
		#change to test dir 
		pushd $dir > /dev/null; 
		#run fluidity 
		../../Source/fluidity *.in > output_"$dir"
		#compare results to standard
		diff output_"$dir" output_standard > diff_results_"$dir" 
		#check return 
		if [ $? != 0 ]; then
	   		echo "  Differences found in $dir ... " 
		else 
			echo "  Test in $dir passed! " 
		fi
		#back out of directory 
		popd > /dev/null;

		
	fi 
done 
