# echo "-----File and Directory Manager-----"
# echo "Choose an option:"
# echo "1. Create a directory"
# echo "2. Create a file"
# echo "3. List contents of a directory"
# echo "4. Delete a file"
# echo "5. Delete a directory"
# echo "Enter your choice (1-5):"
# 
# read choice
# 
# case $choice in
#   1)
#     echo "Enter directory name:"
#     read dirname
#     mkdir -p "$dirname"
#     echo "Directory '$dirname' created."
#     ;;
#   2)
#     echo "Enter file name:"
#     read filename
#     touch "$filename"
#     echo "File '$filename' created."
#     ;;
#   3)
#     echo "Enter directory name to list:"
#     read dirname
#     ls -l "$dirname"
#     ;;
#   4)
#     echo "Enter file name to delete:"
#     read filename
#     rm -i "$filename"
#     ;;
#   5)
#     echo "Enter directory name to delete:"
#     read dirname
#     rm -r -i "$dirname"
#     ;;
#   *)
#     echo "Invalid option!"
#     ;;
# esac

mkdir -p mydir/subdir
echo "Directory 'mydir' and subdirectory 'subdir' created."

echo "Enter some text for the file:"
cat > mydir/sample.txt
echo "File 'sample.txt' created inside 'mydir'."

cp mydir/sample.txt mydir/sample_copy.txt
echo "File copied and renamed to 'sample_copy.txt'."

chmod 744 mydir/sample.txt
chmod 744 mydir/sample_copy.txt
echo "Permissions set: rwx for owner, r-- for group and others."

echo "Listing files with permissions:"
ls -l mydir
#ls -d mydir
