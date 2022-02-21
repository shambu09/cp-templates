def generate(n, diff, left, right):
    if n > 9: return

    if n and (2 * abs(diff) <= n):
        if n == 1:
            generate(n - 1, diff, left, "0" + right)
            generate(n - 1, diff, left, "1" + right)

        if left != "":
            generate(n - 2, diff, left + "0", right + "0")
            generate(n - 2, diff - 1, left + "0", right + "1")

        generate(n - 2, diff, left + "1", right + "1")
        generate(n - 2, diff + 1, left + "1", right + "0")

    if n == 0 and diff == 0:
        print(left + right)

generate(int(input()), 0, "", "")