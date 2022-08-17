# Data structure to store a binary tree node
class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

# Insert method to create nodes
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)

            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def minValueNode(node):
        current = node

        # loop down to find the leftmost leaf
        while(current.left is not None):
            current = current.left

        return current

# findNode method to compare the value with nodes
    def findNode(self, value):
        if value < self.data:
            if self.left is None:
                return str(value)+" Not Found"
            return self.left.findNode(value)

        elif value > self.data:
            if self.right is None:
                return str(value)+" Not Found"
            return self.right.findNode(value)
        else:
            print(str(self.data) + ' is found')

# To be completed
    def deleteNode(self, key):
        # Base Case
        if self.data is None:
            return self.data

        # If the key to be deleted
        # is smaller than the root's
        # key then it lies in  left subtree
        if key < self.data:
            return self.left.deleteNode(key)

        # If the kye to be delete
        # is greater than the root's key
        # then it lies in right subtree
        elif(key > self.data):
            return self.right.deleteNode(key)

        # If key is same as root's key, then this is the node
        # to be deleted
        else:
            # Node with only one child or no child
            if self.left is None:
                temp = self.right
                self = None
                return temp

            elif self.right is None:
                temp = self.left
                self = None
                return temp

            # Node with two children:
            # Get the inorder successor
            # (smallest in the right subtree)
            temp = self.minValueNode(root.right)

            # Copy the inorder successor's
            # content to this node
            self.data = temp.data

            # Delete the inorder successor
            self.right = self.right.deleteNode(temp.data)

        return self

# Print the tree
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data),
        if self.right:
            self.right.PrintTree()


root = Node(12)
root.insert(6)
root.insert(14)
root.insert(3)
root.insert(7)
root.insert(15)
root.insert(22)

print(root.findNode(7))
print(root.findNode(14))
print(root.findNode(15))

root.PrintTree()

print(root.deleteNode(22))
root.PrintTree()
