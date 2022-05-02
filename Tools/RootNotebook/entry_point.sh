#!/bin/bash
. /opt/conda/etc/profile.d/conda.sh && conda activate base
echo jupyter --path
echo "IP address is" `hostname -i`
exec "$@"
