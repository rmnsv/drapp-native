echo "------ Build started (Android) ------"
echo ""

echo "Preparing working files and directories"

#Create directories and copy library files to working directory
{
    find . -name "bin/Android" -type d -exec rm -rf "{}" \;
    find . -name "tmp/Android" -type d -exec rm -rf "{}" \;
    mkdir bin
    mkdir bin/Android
    mkdir tmp    
    mkdir tmp/sourceFiles
    mkdir tmp/Android

    find ./src -name "*.cpp" -exec cp {} tmp/sourceFiles \;
    find ./src -name "*.h" -exec cp {} tmp/sourceFiles \;
} &> /dev/null

declare -a AndroidArchitectures=("x86" "x86_64" "arm" "arm64")

LibraryName="drapp-native"
Android_NDK_Host_Tag="windows-x86_64"
Android_Minimum_Api_Version="21"

echo ""
echo "=== BUILD TARGET Android ==="
echo ""

cd tmp
LibPath=${PWD}/sourceFiles

if [ -z "${ANDROID_NDK_HOME}" ]
then
    export ANDROID_NDK_HOME="C:\Users\samea\AppData\Local\Android\Sdk\ndk\22.0.7026061"
fi

for i in "${AndroidArchitectures[@]}"
do
    echo "Build for $i:"

    ABI_Folder_Name=$i

    if [ $i == "arm" ]
    then
        ABI_Folder_Name="armeabi-v7a"
    elif [ $i == "arm64" ]
    then
        ABI_Folder_Name="arm64-v8a"
    fi

    mkdir ../bin/Android/$ABI_Folder_Name

    if [ $i == "x86" ]
    then
        CxxTarget="i686-linux-android"
    elif [ $i == "x86_64" ]
    then
        CxxTarget="x86_64-linux-android"
    elif [ $i == "arm" ]
    then
        CxxTarget="armv7a-linux-androideabi"
    else
        CxxTarget="aarch64-linux-android"
    fi

    export CXX="$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/$Android_NDK_Host_Tag/bin/$CxxTarget$Android_Minimum_Api_Version-clang++"

    echo "Compiling and linking (output as dynamic library)"

    for i2 in $LibPath/*.cpp; do
        ShortName="${i2##*/}"
        OutputName="${ShortName/cpp/o}"
        $CXX -c $i2 -std=c++0x -o ${PWD}/sourceFiles/$OutputName -fPIC
    done

    $CXX -shared -static-libstdc++ -o ${PWD}/sourceFiles/lib${LibraryName}.so ${PWD}/sourceFiles/*.o

    echo "Copying lib${LibraryName}.so to bin/Android/$ABI_Folder_Name"
    {
        find sourceFiles -name "*.so" -exec cp {} ../bin/Android/$ABI_Folder_Name \;
    } &> /dev/null
    
    echo ""
done

cd ..
echo "** BUILD SUCCEEDED (Android) **"

cd ..

#Cleanup working directories
{
    find . -name "tmp" -type d -exec rm -rf "{}" \;
} &> /dev/null