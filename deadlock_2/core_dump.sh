ulimit -c unlimited
ps -aux | grep main
kill -11 PID
apport-unpack /var/crash/_home_fnv473_demo_kdi_deadlock_build_main.1001.crash ./core
gdb


