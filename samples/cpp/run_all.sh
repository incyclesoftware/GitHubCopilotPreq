options=("cmake" "gtest" "boost")
for dir in "${options[@]}"; do
    cd $dir && make run
    cd ..
    echo "============================="
    echo "Hit enter to continue"
    read
done
