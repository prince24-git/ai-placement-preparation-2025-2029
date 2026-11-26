from __future__ import annotations


def main() -> None:
    n = int(input().strip())
    strings = [input() for _ in range(n)]

    for end in range(n - 1, 0, -1):
        swapped = False
        for index in range(end):
            if strings[index] > strings[index + 1]:
                strings[index], strings[index + 1] = strings[index + 1], strings[index]
                swapped = True
        if not swapped:
            break

    print("\n".join(strings))


if __name__ == "__main__":
    main()
