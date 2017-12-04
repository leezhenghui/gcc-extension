all: ./build ./main-debug ./main ./preload_hook ./preload_hook-debug

./build:
	@echo "[Generate Make File]"
	@./tools/gyp/gyp build.gyp --depth=. -f make --generator-output=./build

./main-debug:
	@make main -C ./build V=1 BUILDTYPE=Debug

./main:
	@make main -C ./build V=1 BUILDTYPE=Release

./preload_hook:
	@make preload_hook -C ./build V=1 BUILDTYPE=Release

./preload_hook-debug:
	@make preload_hook -C ./build V=1 BUILDTYPE=Debug

./test-debug:
	@LD_PRELOAD=./build/out/Debug/lib.target/libpreload_hook.so ./build/out/Debug/main

./test:
	@LD_PRELOAD=./build/out/Release/lib.target/libpreload_hook.so ./build/out/Release/main

./clean:
	@echo "[Cleanup]"
	@rm -rf ./build
