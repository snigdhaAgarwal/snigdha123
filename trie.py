class trie:
    def __init__(self):
        '''Create an empty trie structure'''
        self.data = self.__createTrieList()

    def insert(self, word):
        '''insert word into trie'''
        return self.__insertToTrieList(self.data, word)

    def __insertToTrieList(self, trieList, word):
        '''insert word into a trie structure maintained by trieList
        Assumes trieList to be a valid trie structure.

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        if len(trieList) == 0:
            # If node is NULL, create a new node by inserting
            # 255 NULL pointers (empty lists) and a 0 count
            trieList.extend(self.__createTrieList())
        index = 0

        # if word still has valid characters the index will
        # be the ascii value of the first character
        if len(word) > 0:
            index = ord(word[0])

        if index == 0:
            # if we reached the end of word, increase the word count
            trieList[0] = trieList[0] + 1
            return trieList[0]
        else:
            # otherwise insert the remaining word to the trie
            return self.__insertToTrieList(trieList[index], word[1:])

    def getWords(self):
        '''Gets all words present in the trie as a list in ascending order'''
        return self.__getWordsInTrieList(self.data)

    def __getWordsInTrieList(self, trieList):
        '''gets all words present in the trieList as a list in ascending order
        Assumes trieList to be a valid trie structure.

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        outputList = []
        for i in range(len(trieList)):
            if i == 0 and trieList[i] > 0:
                # if end of string "\0" has valid count, add
                # null string to output list and the count
                outputList.append("")
                outputList.append(trieList[i])
            elif i > 0 and len(trieList[i]) > 0:
                currChar = chr(i)
                # get all words in the sub tree
                sublist = self.__getWordsInTrieList(trieList[i])
                for j in sublist:
                    # add current character to all words
                    if type(j) == str:
                        # only add to strings
                        outputList.append(currChar + j)
                    else:
                        outputList.append(j)
        return outputList

    def getTrie(self):
        '''Returns a string representing the trie as a tree structure'''
        return self.__getTrieInTrieList(self.data,1)

    def __getTrieInTrieList(self, trieList, level):
        '''Returs a string representing the trie structure present in trieList
        Assumes trieList to be a valid trie structure.

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        output = ""
        if level == 1:
            # if root, print root
            output = output + "root\n"
        for i in range(len(trieList)):
            if i == 0 and trieList[i] > 0:
                # since count > 0 for end of string position
                # add | level number of times followed by $
                output = output + ("|" * level) + "$\n"
            elif i > 0 and len(trieList[i]) > 0:
                # add | level number of times followed by the character
                # it has a child and hence is a valid trie
                currChar = chr(i)
                output = output + ("|" * level) + currChar + "\n"
                output = output + self.__getTrieInTrieList(trieList[i], level + 1)
        return output

    def search(self, word):
        '''Searches for word in trie. It returns a tuple of two elements, the
        first element is a boolean representing whether or not the word was found
        and the second element being a list giving a list of all words which have 
        largest matched prefix with the input word'''
        return self.__searchWordInTrieList(self.data, word)

    def __searchWordInTrieList(self, trieList, word):
        '''Searches for word in trieList. It returns a tuple of two elements, the
        first element is a boolean representing whether or not the word was found
        and the second element being a list giving a list of all words which have
        largest matched prefix with the input word.
        It Assumes that trieList is a valid list.

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        if len(trieList) == 0:
            # If we reached an empty node, the word wasn't found
            return (False, [])
        if len(word) == 0 and trieList[0] == 0:
            return (False, self.__getWordsInTrieList(trieList))
        if len(word) == 0 and trieList[0] > 0:
            # if we reached the end of word, and the count for that word is
            # greater than 0, we found the word. Return the same.
            return (True, [ trieList[0] ])
        # Get the result and the list of matching words for the remaining word
        (result, outlist) = self.__searchWordInTrieList(trieList[ord(word[0])], word[1:])
        # If the word was not found, we need to add words with common prefix
        if result == False:
            if len(outlist) == 0:
                # attach the subtree for the first matching node.
                outlist = self.__getWordsInTrieList(trieList)
            else:
                for i in range(len(outlist)):
                    # while traversing up, add the characters we are came through
                    if type(outlist[i]) == str:
                        outlist[i] = word[0] + outlist[i]
        return (result, outlist)

    def remove(self, word):
        '''Removes the word from trie. Returns -1 if the word was not found, else
        returns the updated count'''
        return self.__removeInTrieList(self.data, word)

    def __removeInTrieList(self, trieList, word):
        '''Removes the word from trie structure represented by trieList. Returns -1 if
        the word was found, else returns the updated count.
        It Assumes that trieList is a valid list.

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        if len(trieList) == 0:
            # reached NULL. Not found
            return -1
        if len(word) == 0 and trieList[0] == 0:
            # matched word, but not the end of any valid word
            return -1
        elif len(word) == 0:
            # Word was found and it exists
            trieList[0] = trieList[0] - 1
            return trieList[0]
        else:
            # Word not matched completely yet
            currChar = ord(word[0])
            newCount = self.__removeInTrieList(trieList[currChar], word[1:])
            if newCount == 0:
                #actual deletion happend, check if collapse is required
                for i in trieList:
                    if i != 0 and i != []:
                        # no need to collapse
                        return newCount
                # collapse required
                trieList[:] = []
            return newCount

    def __createTrieList(self):
        '''Creates an list represnting an empty trie node

        Note: This function is a helper function for trie class and
        is not supposed to be called by the user'''
        l = []
        l.append(0)
        # For ASCII character range (128 characters)
        for i in range(127):
            l.append([])
        return l
    def __str__(self):
        return str(self.getTrie())
    def ptrie(self):
        '''Prints the trie structure'''
        print self

if __name__ == "__main__":
    t = trie()
    commands = { "insert" : t.insert, "search" : t.search, "remove" : t.remove, "ptrie" : t.ptrie }
    noOfCases = input()
    for i in range(noOfCases):
        cmd = raw_input();
        args = cmd.split()
        if len(args) == 1:
            commands[args[0]]()
        else:
            output = commands[args[0]](args[1])
            if args[0] == "search":
                # special priting required
                # output is a tuple of a boolean and a list
                if output[0]:
                    # if it was found, output[1] contains a list contianing just the count
                    print "true", output[1][0]
                else:
                    print "false",
                    for i in output[1]:
                        print i,
                    print
            else:
                print output
