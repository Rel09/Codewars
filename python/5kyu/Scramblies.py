#Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.
#
#Notes:
#
#    Only lower case letters will be used (a-z). No punctuation or digits will be included.
#    Performance needs to be considered.
#
#Examples
#
#scramble('rkqodlw', 'world') ==> True
#scramble('cedewaraaossoqqyt', 'codewars') ==> True
#scramble('katas', 'steak') ==> False

def scramble(s1, s2):
    dict = {}
    
    #Scan the first word
    for x in s1.lower():
        if x in dict:
            dict[x] = dict[x] + 1
        else:
            dict[x] = 1
            
    #Scan the second word
    for x in s2.lower():
        if x in dict:
            dict[x] = dict[x] -1
            if dict[x] < 0:
                return False
        else: return False
    return True

if __name__ == '__main__':

    print(scramble('rkqodlw', 'world'))
    print(scramble('cedewaraaossoqqyt', 'codewars'))
    print(scramble('katas', 'steak'))
    print(scramble('scriptjava', 'javascript'))
    print(scramble('scriptingjava', 'javascript'))                
        

    
    
    
    