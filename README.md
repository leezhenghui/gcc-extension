# Examples for some interesting GCC extension usages.

## Examples

1. Startup Hook

  Provide Pre/Post hook point for main() method

2. Make a wrapper for the method

   Make a wrapper on the target method, and provide a chance to do function argument (re)construction

3. Instrument on the method invocation

   Provide a Pre/Post hook point on the method, usually we want to turn on this in tracing or profing situations


## How to run

The project is using GYP as the compile tool.

```sh
git clone https://github.com/leezhenghui/gcc-extension.git 

git submodule init

git submodule update

make clean

make 

make test

make test-debug

```

note: the `instrument` will only work on `Debug` mode, so the pre/post tracing will be printed when run `test-debug`



