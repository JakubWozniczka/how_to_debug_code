scan-build -o myhtml -v --use-analyzer=/usr/lib/llvm-9/bin/clang cmake ..
#scan-build -o myhtml -v --use-analyzer=/usr/lib/llvm-9/bin/clang -enable-checker valist.Uninitialized make
scan-build -o myhtml -v --use-analyzer=/usr/lib/llvm-9/bin/clang -enable-checker optin.cplusplus.UninitializedObject make
