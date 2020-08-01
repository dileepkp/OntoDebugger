#FopenPrecedesFclose

fileDict = {}
isBugDetected = 0

def process(funcName, ind, var, top, valOfVar, line):
    if funcName == 'fopen':
      fileDict[var] = valOfVar
    if funcName == 'fclose':
      if var in fileDict and fileDict.get(var) == valOfVar:
        del fileDict[var]
      else:
        global isBugDetected
        isBugDetected = 1
        print("Bug in the code: FopenPrecedesFclose" + str(line))

def completeProcessing():
    global isBugDetected
    if isBugDetected == 0:
      print("No Bug: FopenPrecedesFclose")
