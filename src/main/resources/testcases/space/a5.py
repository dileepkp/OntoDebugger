#FreadPrecedesFclose

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fread':
      fileDict[var] = valOfVar
    if funcName == 'fclose':
      if not(var in fileDict and fileDict.get(var) == valOfVar):
        global isBugDetected
        isBugDetected = 1
        print("Bug in the code: FreadPrecedesFclose" + str(line))

def completeProcessing():
    global isBugDetected
    if isBugDetected == 0:
      print("No Bug: FreadPrecedesFclose")
