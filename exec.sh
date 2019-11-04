#!/bin/sh

echo "start compiling c program"
echo
gcc  bankers_interrupt_main.c bankers_process.c interrupt_create.c  queue.c common.c

echo "starting application..."
./a.out
echo "application finished========================="

python bankerintdataprocessing.py

echo "kill if server running at port 3000 if any"
ps aux | grep 3000 | grep -v grep | awk '{print $2}' | uniq | xargs kill -9

if which node > /dev/null
then
    echo "node is installed, skipping installation..."
else
	echo "Installing node..."
    npm install node
fi

echo
echo "starting node server"
node app.js 3000 &

echo "started node server in detached mode"
echo
open http://localhost:3000
echo
echo "opened report in your favorite browser"
