#! /bin/bash

chmod +x /app/run.sh
/app/run.sh
echo "$uid"
echo "$gid"
chown -R $uid:$gid /app
chown -R $uid:$gid /data
chown -R $uid:$gid /config
chown -R $uid:$gid /output
