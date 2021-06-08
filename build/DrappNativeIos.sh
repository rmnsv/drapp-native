echo "------ Build started (Android and iOS) ------"
echo ""

echo "Preparing working files and directories"

#Create directories and copy library files to working directory
{
    find . -name "bin/iOS" -type d -exec rm -rf "{}" \;
    find . -name "tmp/iOS" -type d -exec rm -rf "{}" \;
    mkdir bin
    mkdir bin/iOS
    mkdir tmp    
    mkdir tmp/sourceFiles
    mkdir tmp/iOS

    find . -name "*.cpp" -exec cp {} tmp/sourceFiles \;
    find . -name "*.h" -exec cp {} tmp/sourceFiles \;
} &> /dev/null

declare -a iOSArchitectures=("x86_64" "arm64" "arm64e")

LibraryName="DrappNative"
iOS_SDK_Version="14.3"
iOS_SDK_Min_Version="10.0"

echo ""
echo "=== BUILD TARGET iOS ==="
echo ""

cd tmp

for i in "${iOSArchitectures[@]}"
do
    SdkRootValue="iPhoneOS"
    echo "Build for $i:"
    if [ $i == "x86_64" ]
    then
        SdkRootValue="iPhoneSimulator"
    fi

    export DEVROOT=/Applications/Xcode.app/Contents/Developer/Platforms/$SdkRootValue.platform/Developer
    export IPHONEOS_DEPLOYMENT_TARGET=$iOS_SDK_Version
    export SDKROOT=$DEVROOT/SDKs/$SdkRootValue.sdk
    export CFLAGS="-std=c++0x -arch $i -pipe -no-cpp-precomp -fembed-bitcode -isysroot $SDKROOT -miphoneos-version-min=$iOS_SDK_Min_Version -I$SDKROOT/usr/include"

    echo $CFLAGS

    echo "Compiling and linking (output as static library)"

    cd sourceFiles
    g++ -c *.cpp $CFLAGS
    cd ..

    {
        ar ru iOS/${LibraryName}_${i}.a sourceFiles/*.o
    } &> /dev/null

    cd sourceFiles
    find . -name "*.o" -type f -delete
    cd ..

    echo ""
done

echo "Build universal library:"
lipo iOS/*.a -output iOS/lib$LibraryName.a -create

echo "Copying lib${LibraryName}.a to /bin/iOS"
{
    find iOS -name "lib${LibraryName}.a" -exec cp {} ../bin/iOS \;
} &> /dev/null

cd ..

echo ""
echo "** BUILD SUCCEEDED (iOS) **"
echo ""

cd ..

#Cleanup working directories
{
    find . -name "tmp" -type d -exec rm -rf "{}" \;
} &> /dev/null