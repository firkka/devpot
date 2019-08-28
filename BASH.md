Commands
===================

Locate
------------
Pipe through grep

$ locate less | grep ^/bin
/bin/bzless
/bin/less

cd /home/tim/science
locate math | grep `pwd`
