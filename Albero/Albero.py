import random

class Node():
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None
    
    def insertNode(self,key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else: 
                    self.right.insertNode(key)
            elif key < self.key:
                if self.left is None:
                    self.left = Node(key)
                else:
                    self.left.insertNode(key)
        else:
            self.key = key
            #root = Node(key)


    def printTree(self,level = 0):
        if self.left is not None:
            self.left.printTree(level+1)
        print(f"Livello: {level}->{self.key}")
        if self.right is not None:
            self.right.printTree(level+1)
    
    def findNode(self,node):
        if self.key is not None:
            if node == self.key:
                return True
            elif node < self.key:
                if self.left is not None:
                    self.left.findNode(node)
                else: pass

            if node == self.key:
                return True
            elif node < self.key:
                if self.right is not None:
                    self.right.findNode(node)
                else: pass
        else: return False


    def stampaKey(self):
        print(self.key)


"""
def printTree(root):
    if root is not None:
        print(root.key)
        printTree(root.right)
"""

def main():
    lista_key = list(range(0,40,5))
    random.shuffle(lista_key)
    print(lista_key)
    root = Node(lista_key[0])
    for a in lista_key[1:]:
        root.insertNode(a)
    root.printTree()
    print(root.findNode(25))
    """
    insertNode(root, 56)
    insertNode(root, 22)
    insertNode(root, 90)
    printTree(root)
    """

if __name__ == "__main__":
    main()