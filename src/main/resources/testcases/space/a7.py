#Double fopen

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fopen':
      if var in fileDict:
        global isBugDetected
        isBugDetected = 1
        print("Bug in the code" + str(line))
      fileDict[var] = valOfVar
    if funcName == 'fclose':
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]

def completeProcessing():
    global isBugDetected
    if isBugDetected == 0:
      print("No Bug: Double fopen")
