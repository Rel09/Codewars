#Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

#move_zeros([1, 0, 1, 2, 0, 1, 3]) # returns [1, 1, 2, 1, 3, 0, 0]


def move_zeros(array):
    list = []
    zero = 0
    for x in array:
        if x != 0:
            list.append(x)
        else:
            zero += 1

    for x in range(zero):
        list.append(0)
        
    return list

if __name__ == '__main__':
    print(move_zeros([9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9]))
    print(move_zeros([1, 2, 0, 1, 0, 1, 0, 3, 0, 1]))