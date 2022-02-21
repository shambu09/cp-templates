def calc(instr, inarr):
    """
    Time ~ O(N)
    Space ~ O(N)
    """
    memo = {}
    res = ""
    for i in range(len(instr)):
        l = instr[i];
        if memo.get(l, None) == None:
            memo[l] = inarr[i]

        elif memo[l] != inarr[i]:
            memo[l] = "-"
   
    for i in range(len(inarr)):
        w = inarr[i]
        if memo.get(w, None) == None:
            memo[w] = instr[i]

        elif memo[w] != instr[i]:
            memo[w] = "--"

    for i in memo:
        if len(i) == 1 and memo[i] != "-" and i == memo[memo[i]]:
            res += i

    if res == "":
        res = "NA"

    print(res)

instr = input()
inarr = input().split(",")
calc(instr, inarr)