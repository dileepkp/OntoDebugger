#FreadFollowsFopen

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fopen':
      fileDict[var] = valOfVar
    if funcName == 'fread':
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]

def completeProcessing():
    global isBugDetected
    if len(fileDict) == 0 and isBugDetected == 0:
      print("No Bug: FreadFollowsFopen")
    else:
      print("Bug: FreadFollowsFopen")
