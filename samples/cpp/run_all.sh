options=("cmake" "gtest" "boost")
for dir in "${options[@]}"; do
    cd $dir && make run
    cd ..
done
