import os
import re
root = "."
for rt,dirs,files in os.walk(root):
    for f in files:
        filename = rt + os.sep + f
        ret = re.search(".*\.run$",filename)
        if ret != None:
            print("Removing binary file " + filename + ": ........ OK!")
            os.remove(filename)
