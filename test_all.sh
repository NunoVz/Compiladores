# before running this script, make sure you have a makefile and the you have run the isolate_folders.sh script
meta="meta1" # Change this to the meta folder you want to test
executable="./lexer" # Change this to your executable

make
for file in "./c/$meta/"*; do
    for file2 in $file/*c; do
        "$executable" -l < $file2 > $file/$(basename "${file}").result
        diff $file/$(basename "${file}").result $file/$(basename "${file}").out >   $file/$(basename "${file}").diff
        echo $file2
        diff $file/$(basename "${file}").result $file/$(basename "${file}").out
    done
done