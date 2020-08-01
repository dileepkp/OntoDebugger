

def strictly_increasing(L):
    return all(x<y for x, y in zip(L, L[1:]))

def strictly_decreasing(L):
    return all(x>y for x, y in zip(L, L[1:]))

def non_increasing(L):
    return all(x>=y for x, y in zip(L, L[1:]))

def non_decreasing(L):
    return all(x<=y for x, y in zip(L, L[1:]))


def allSame(L):
    return all(x==y for x, y in zip(L, L[1:]))


def duplicateElements(list1): 
    result = False
  
    # traverse in the 1st list 
    for outerIndex,x in enumerate(list1): 
  
        # traverse in the 2nd list 
        for innerIndex,y in enumerate(list1): 
    
            # if one common 
            if outerIndex != innerIndex and x == y: 
                result = True
                return result  
                  
    return result 

def allDistinct(L):
    return not duplicateElements(L)


def allNonZero(list1): 
    #result = False
  
    for x in list1: 
     if x == 0:
      return False

    return True


def allPositive(list1): 
    #result = False
  
    for x in list1: 
     if x <= 0:
      return False

    return True


def allNegative(list1): 
    #result = False
  
    for x in list1: 
     if x >= 0:
      return False

    return True

def allNonPositive(list1): 
    #result = False
  
    for x in list1: 
     if x > 0:
      return False

    return True


def allNonNegative(list1): 
    #result = False
  
    for x in list1: 
     if x < 0:
      return False

    return True



def equalSpanOf(list1, list2): 
   return list1 == list2 


