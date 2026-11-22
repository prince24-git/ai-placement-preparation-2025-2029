number = abs(int(input("Enter a number: ")))

odd_sum = 0
even_sum = 0

while number > 0:
    digit = number % 10
    if digit % 2 == 0:
        even_sum += digit
    else:
        odd_sum += digit
    number //= 10

print("Sum of odd digits:", odd_sum)
print("Sum of even digits:", even_sum)
