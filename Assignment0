import hashlib
import time
var = input("Enter a string: ")
comp = 0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
i = 1
var1 = var + "%s"%i
res = hashlib.sha256(var1.encode('UTF8'))
start = time.time()
while(int(res.hexdigest(),16)>int(hex(comp),16)):
    i+=1
    var1 = var + "%s"%i
    res = hashlib.sha256(var1.encode('UTF8'))
end = time.time()
print("The resultant string is:")
print(var1)
print("The SHA256 hash of this string is:")
print(res.hexdigest())
print("Time taken to find the nonce value is:")
print(end-start)
