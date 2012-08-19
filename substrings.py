from trie import trie
class substrings(trie):
    def __init__(self):
        ''' Creates an empty trie structure '''
        trie.__init__(self)
    def getCount(self):
        ''' Returns the number of non empty unique substrings'''
        # reduces 1 as we have counted empty substring as well
        return self.__getCount(self.data) - 1
    def __getCount(self, trieList):
        count = 0
        for i in trieList:
            if type(i) == int:
                # count the node
                count = count + 1
            else:
                # Get substrings
                count = count + self.__getCount(i)
        return count

if __name__ == "__main__":
    cases = input()
    for i in range(cases):
        dummy = input() # length of string not required
        s = raw_input()
        t = substrings()
        for i in xrange(len(s)):
            t.insert(s[i:])
        print t.getCount()
