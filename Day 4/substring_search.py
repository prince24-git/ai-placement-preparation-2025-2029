def build_lps(pattern):
    """Build the longest-prefix-suffix table used by KMP."""
    lps = [0] * len(pattern)
    prefix_length = 0
    i = 1

    while i < len(pattern):
        if pattern[i] == pattern[prefix_length]:
            prefix_length += 1
            lps[i] = prefix_length
            i += 1
        elif prefix_length != 0:
            prefix_length = lps[prefix_length - 1]
        else:
            lps[i] = 0
            i += 1

    return lps


def contains_substring(text, pattern):
    """Return True if pattern occurs in text, using O(n + m) KMP search."""
    if pattern == "":
        return True
    if len(pattern) > len(text):
        return False

    lps = build_lps(pattern)
    text_index = 0
    pattern_index = 0

    while text_index < len(text):
        if text[text_index] == pattern[pattern_index]:
            text_index += 1
            pattern_index += 1
            if pattern_index == len(pattern):
                return True
        elif pattern_index != 0:
            pattern_index = lps[pattern_index - 1]
        else:
            text_index += 1

    return False


def main():
    text = input("Enter the main string: ")
    pattern = input("Enter the substring to find: ")

    if contains_substring(text, pattern):
        print("Substring found")
    else:
        print("Substring not found")


if __name__ == "__main__":
    main()
