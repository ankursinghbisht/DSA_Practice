"""
Idea:
extracting no. from each LL & returning the product
(keeping the product under 10^9+7 , by constantly performing modulus on the product)
"""

MOD = 10 ** 9 + 7
# your task is to complete this function
# Function should return an integer value
# head1 denotes head node of 1st list
# head2 denotes head node of 2nd list

'''
class node:
    def __init__(self):
        self.data = None
        self.next = None
'''


def multiplyTwoList(head1, head2):
    # Code here
    ans1 = ans2 = 0
    while head1:
        ans1 = (ans1 * 10 + head1.data) % MOD
        head1 = head1.next

    while head2:
        ans2 = (ans2 * 10 + head2.data) % MOD
        head2 = head2.next
    return (ans1 * ans2) % MOD


# {
# Driver Code Starts
class node:
    def __init__(self):
        self.data = None
        self.next = None


class Linked_List:
    def __init__(self):
        self.head = None

    def get_head(self):
        return self.head

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            temp = self.head
            while (temp.next):
                temp = temp.next
            temp.next = new_node


def printlist(ptr):
    while ptr != None:
        print(ptr.data, end=" ")
        ptr = ptr.next


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        list1 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list1.insert(i)
        # printlist(list1.get_head())
        # print ''
        list2 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list2.insert(i)
        # printlist(list2.get_head())
        # print ''
        print(multiplyTwoList(list1.get_head(), list2.get_head()))

# } Driver Code Ends