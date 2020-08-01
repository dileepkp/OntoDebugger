#FcloseFollowsFopen
import sys, os, re
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '.'))
import listVerification

fopenBPs = []
fcloseBPs = [] 
fopenVars = []
fcloseVars = []
fileDict = {}

with open("space_single_original.c") as myFile:
    for num, line in enumerate(myFile, 1):
       fcloseMatch = re.search('fclose\s*\((\w+)\)', line)
       if fcloseMatch:
        fcloseBPs.append(gdb.Breakpoint(str(num)))
        fcloseVars.append(fcloseMatch.group(1))
       fopenMatch = re.search('(\w+)\s*=\s*fopen\s*\(', line)
       if fopenMatch:
        fopenBPs.append(gdb.Breakpoint(str(num)))
        fopenVars.append(fopenMatch.group(1))

def stopHandler(stopEvent):
  for b in stopEvent.breakpoints:
    if b in fopenBPs:
      gdb.execute("next")
      ind = fopenBPs.index(b)
      var = fopenVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      fileDict[var] = valOfVar
    if b in fcloseBPs:
      ind = fcloseBPs.index(b)
      var = fcloseVars[ind]
      top = gdb.newest_frame()
      valOfVar = (top.read_var(var))
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]
  gdb.execute("continue")

gdb.events.stop.connect (stopHandler)
gdb.execute("run")
if len(fileDict) == 0:
  print("No Bug")
