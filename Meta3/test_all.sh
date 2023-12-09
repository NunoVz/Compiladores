# before running this script, make sure you have a makefile and the you have run the isolate_folders.sh script
meta="meta3" # Change this to the meta folder you want to test
executable="./uccompiler" # Change this to your executable

for file in "./c/$meta/"*; do
    for file2 in $file/*c; do
        "$executable" -s < $file2 > $file/$(basename "${file}").result
        diff $file/$(basename "${file}").result $file/$(basename "${file}").out >   $file/$(basename "${file}").diff
        echo $file2
        diff $file/$(basename "${file}").result $file/$(basename "${file}").out
    done
done