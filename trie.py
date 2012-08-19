#!/usr/bin/evn python
class trie:
    def __init__(self):
        self.data = self.createList()
    def insert(self, word):
        return self.insertToList(self.data, word)
    def insertToList(self, trieList, word):
        if len(trieList) == 0:
            trieList.extend(self.createList())
        index = 0
        if len(word) > 0:
            index = ord(word[0])
        if index == 0:
            trieList[0] = trieList[0] + 1
            return trieList[0]
        else:
            return self.insertToList(trieList[index], word[1:])
    def getWords(self):
        return self.getWordsInTrieList(self.data)
    def getWordsInTrieList(self, trieList):
        outputList = []
        for i in range(len(trieList)):
            if i == 0 and trieList[i] > 0:
                outputList.append("")
            elif i > 0 and len(trieList[i]) > 0:
                currChar = chr(i)
                sublist = self.getWordsInTrieList(trieList[i])
                for j in sublist:
                    outputList.append(currChar + j)
        return outputList
    def search(self, word):
        return self.searchWordInTrieList(self.data, word)
    def searchWordInTrieList(self, trieList, word):
        if len(trieList) == 0:
            return (False, [])
        if len(word) == 0 and trieList[0] > 0:
            return (True, [ trieList[0] ])
        (result, outlist) = self.searchWordInTrieList(trieList[ord(word[0])], word[1:])
        if result == False:
            if len(outlist) == 0:
                outlist = self.getWordsInTrieList(trieList)
            else:
                for i in range(len(outlist)):
                    outlist[i] = word[0] + outlist[i]
        return (result, outlist)
    def createList(self):
        l = []
        l.append(0)
        # For ASCII character range (128 characters)
        for i in range(127):
            l.append([])
        return l
    def __str__(self):
        return str(self.getWords())

if __name__ == "__main__":
    t = trie()
    t.insert("cat")
    t.insert("call")
    t.insert("cast")
    t.insert("crow")
    t.insert("calls")
    t.insert("band")
    print t
    print t.search("calling")
    print t.search("call")
    print t.insert("call")
    print t.search("calling")
