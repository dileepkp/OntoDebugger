#FopenPrecedesFread

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fopen':
      print("fopen precedes fread" + var)
      fileDict[var] = valOfVar
    if funcName == 'fread':
      if not(var in fileDict and fileDict.get(var) == valOfVar):
        global isBugDetected
        isBugDetected = 1
        print("Bug in the code:FopenPrecedesFread " + str(line))

def completeProcessing():
    global isBugDetected
    if isBugDetected == 0:
      print("No Bug: FopenPrecedesFread")
