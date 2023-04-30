n = int(input("Enter the size of array: "))
print('Enter the array elements: ')
a = [1,2]
for i in range(0,n):
    a[i] = int(input())

p = 2**n

print("Power set:")
for i in range(p):
    for j in range(n):
        if i&(1<<j):
            print(a[j])
    print()