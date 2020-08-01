#FcloseFollowsFopen

fileDict = {}

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fopen':
      fileDict[var] = valOfVar
    if funcName == 'fclose':
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]

def completeProcessing():
    if len(fileDict) == 0:
      print("No Bug: FcloseFollowsFopen")
    else:
      print("Bug: FcloseFollowsFopen")
