# macos_execute_from_memory
I wanted to see how hard would it be to recreate in-memory macho execution used by Lazarus 6588d262529dc372c400bef8478c2eec sample.

this PoC is largely based on https://github.com/opensource-apple/dyld/tree/master/unit-tests/test-cases/bundle-memory-load and https://objective-see.com/blog/blog_0x51.html

turns out its easy
