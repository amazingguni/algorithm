
total_testcase = 1
num_student = 2
num_pair = 3
pairs = []

def init():
    total_testcase = 0
    num_student = 0
    num_pair = 0
    pairs = []

def get_input():
    temp = input().split()
    num_student = int(temp[0])
    num_pair = int(temp[1])
    temp = input().split()
    for i in range(num_pair):
        a = int(temp[i * 2])
        b = int(temp[i * 2 + 1])
        pairs.append((a, b))
    
def calculate():
    print(num_student)
    print(num_pair)
    print(pairs)

def main():
    total_testcase = int(input())
    for tc in range(total_testcase):
        init()
        get_input()
        print(num_student)
        print(num_pair)
        calculate()

main()
