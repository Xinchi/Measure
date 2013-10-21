#/bin/bash
tail -0f /var/log/kern.log > kernlog &
make insert
sleep 10
make remove
pkill tail
