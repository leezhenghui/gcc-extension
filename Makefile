all: ./build ./main-debug ./main

./build:
	@echo "[Generate Make File]"
	@./tools/gyp/gyp build.gyp --depth=. -f make --generator-output=./build

./main-debug:
	@make main -C ./build V=1 BUILDTYPE=Debug

./main:
	@make main -C ./build V=1 BUILDTYPE=Release

./test-debug:
	@./build/out/Debug/main

./test:
	@./build/out/Release/main

./clean:
	@echo "[Cleanup]"
	@rm -rf ./build
