def hanoi(n, source, auxiliary, destination):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return

    hanoi(n - 1, source, destination, auxiliary)
    print(f"Move disk {n} from {source} to {destination}")
    hanoi(n - 1, auxiliary, source, destination)


disks = int(input("Enter number of disks: "))

if disks <= 0:
    print("Please enter a positive number of disks.")
else:
    hanoi(disks, "A", "B", "C")
