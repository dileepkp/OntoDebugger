#FcloseFollowsFread

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fread':
      fileDict[var] = valOfVar
    if funcName == 'fclose':
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]

def completeProcessing():
    global isBugDetected
    if len(fileDict) == 0 and isBugDetected == 0:
      print("No Bug: FcloseFollowsFread")
    else:
      print("Bug: FcloseFollowsFread")
