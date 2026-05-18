#!/bin/bash
# Deploy minitel_heart_search to a Pi at $1 (default: 192.168.1.50)
HOST=${1:-192.168.1.50}
PASS=pi

sshpass -p "$PASS" ssh -o StrictHostKeyChecking=no pi@$HOST "mkdir -p /home/pi/texts/poetry_corpus"
sshpass -p "$PASS" rsync -av texts/poetry_corpus/ pi@$HOST:/home/pi/texts/poetry_corpus/
sshpass -p "$PASS" scp -o StrictHostKeyChecking=no minitel_heart_search.py pi@$HOST:/home/pi/
sshpass -p "$PASS" ssh -o StrictHostKeyChecking=no pi@$HOST "echo $PASS | sudo -S apt-get install -y python3-serial 2>/dev/null || pip3 install -q pyserial 2>/dev/null || true"

echo "Done. Run on the Pi:"
echo "  python3 /home/pi/minitel_heart_search.py --port /dev/ttyUSB0"
