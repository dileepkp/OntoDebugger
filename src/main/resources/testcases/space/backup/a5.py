#FreadPrecedesFclose
import sys, os, re
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification

freadBPs = []
fcloseBPs = [] 
freadVars = []
fcloseVars = []
fileDict = {}

with open("space_single_original.c") as myFile:
    for num, line in enumerate(myFile, 1):
       fcloseMatch = re.search('fclose\s*\((\w+)\)', line)
       if fcloseMatch:
        fcloseBPs.append(gdb.Breakpoint(str(num)))
        fcloseVars.append(fcloseMatch.group(1))
       freadMatch = re.search('getc\s*\((\w+)\)', line)
       if freadMatch:
        freadBPs.append(gdb.Breakpoint(str(num)))
        freadVars.append(freadMatch.group(1))

def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b in freadBPs:
      ind = freadBPs.index(b)
      var = freadVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      fileDict[var] = valOfVar
    if b in fcloseBPs:
      ind = fcloseBPs.index(b)
      var = fcloseVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      if not(var in fileDict and fileDict.get(var) == valOfVar):
        print("Bug in the code" + str(top.find_sal().line))
  gdb.execute("continue")

gdb.events.stop.connect (stopHandler)
gdb.execute("run")
print("No Bug")
