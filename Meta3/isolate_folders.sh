meta="meta3"

for file in "./c/$meta"/*c; do
    file_name=$(basename "${file%.*}")
    echo "Testing ${file%.*}"
    echo "filaname $file_name"
    mkdir ./c/$meta/$file_name
    mv "${file%.*}".* ./c/$meta/$file_name/
done