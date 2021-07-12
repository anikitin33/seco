import sys
from subprocess import Popen, PIPE

eins = b'\xba\xb6\xfa\xc6'
zwei = b'\x01'*16
arg = eins+zwei
cmd = b'./ctfc.exe ' + arg
p = Popen(cmd, shell=True, stdout=PIPE, stdin=PIPE, stderr=PIPE)
out, err = p.communicate()

print(out.decode("ASCII"))
