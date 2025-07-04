read -p "Build type: " buildType
mkdir -p bin
if [[ "${buildType^}" != "Debug" && "${buildType^} != Release" ]]; then
	buildType="Debug"
fi
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE="${buildType^}" .. -G "Unix Makefiles"
make
cd ..
if [[ "${buildType^}" = "Debug" ]]; then
	cd bin
	wezterm start --cwd . --class floating ./$(basename $(dirname $PWD))
fi
exit
