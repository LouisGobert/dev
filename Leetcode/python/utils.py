def binarySearch(list, val):
    l = 0
    r = len(list)
    midle = 0
    while l <= r:
        midle = (r+l)//2

        if list[midle] == val:
            return midle
        else:
            if list[midle] < val:
                l = midle + 1
            else:
                r = midle-1

        return None
        