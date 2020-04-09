# Given an array order so that all even numbers come first, without using more
# memory

def order(lst):
    # start going through elements with indexes captured
    runner = 0
    while runner < len(lst):
        # if odd search for next even
        if lst[runner] % 2:
            finder = runner + 1
            while finder < len(lst):
                # if even found swap them out
                if not lst[finder]%2:
                    lst[runner], lst[finder] = lst[finder], lst[runner]
                    break
                else:
                    finder += 1
        runner += 1

    print(lst)

if __name__ == '__main__':
    order([1,4,2,6,7,3,2,899,345,31,16,238,5919])
